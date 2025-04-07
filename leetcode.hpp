#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <array>
#include <cassert>
#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using std::array;
using std::deque;
using std::list;
using std::map;
using std::max;
using std::min;
using std::pair;
using std::priority_queue;
using std::set;
using std::string;
using std::unordered_map;
using std::unordered_set;
using std::vector;

// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode()
		: val(0), left(nullptr), right(nullptr) { }
	TreeNode(int x)
		: val(x), left(nullptr), right(nullptr) { }
	TreeNode(int x, TreeNode* l, TreeNode* r)
		: val(x), left(l), right(r) { }
};

// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode* next;
	ListNode()
		: val(0), next(nullptr) { }
	ListNode(int x)
		: val(x), next(nullptr) { }
	ListNode(int x, ListNode* n)
		: val(x), next(n) { }
};

// \[([^\[\]]+?)\]
// {$1}
//============================================================

#define null INT_MIN

inline TreeNode* buildTree(vector<int> const& A)
{
	if (A.empty()) return nullptr;
	size_t alen = A.size(), aidx = 1;
	TreeNode* root = new TreeNode[alen];
	for (size_t i = 0; i < alen; ++i)
		root[i].val = A[i];
	vector<size_t> Q;
	Q.push_back(0);
	for (size_t i = 0; i < Q.size(); ++i) {
		TreeNode* cur = root + Q[i];
		// 处理左子节点
		if (aidx < alen) {
			if (A[aidx] != null) {
				cur->left = root + aidx;
				Q.push_back(aidx);
			}
			++aidx;
		}
		// 处理右子节点
		if (aidx < alen) {
			if (A[aidx] != null) {
				cur->right = root + aidx;
				Q.push_back(aidx);
			}
			++aidx;
		}
	}
	return root;
}

inline ListNode* buildList(vector<int> const& A)
{
	if (A.empty()) return nullptr;
	size_t alen = A.size();
	ListNode* head = new ListNode[alen];
	head[0].val = A[0];
	for (size_t i = 1; i < alen; ++i) {
		head[i - 1].next = head + i;
		head[i].val = A[i];
	}
	return head;
}

inline int popcount(unsigned n)
{
	n = n - ((n >> 1) & 0x55555555u);
	n = (n & 0x33333333u) + ((n >> 2) & 0x33333333u);
	n = (n + (n >> 4)) & 0x0f0f0f0fu;
	n = (n * 0x1010101u) >> 24;
	return static_cast<int>(n);
}

class Fenwick {
	vector<int> sum;
	int len;

	int lowbit(int i)
	{
		return i & (-i);
	}

public:
	Fenwick(int size)
	{
		len = size + 1;
		sum.resize(len);
	}

	void add(int i, int x)
	{
		++i;
		assert(i < len);
		for (; i < len; i += lowbit(i))
			sum[i] += x;
	}

	int get(int i)
	{
		// 需要 +1 要不 0 那里退不出去循环
		++i;
		assert(i < len);
		int r = 0;
		for (; i > 0; i -= lowbit(i))
			r += sum[i];
		return r;
	}
};

template <typename T>
struct TriLower {
	int const rank;
	vector<T> buffer;

	TriLower(int n)
		: rank(n), buffer(n * (n + 1) / 2) { }

	T& operator()(int h, int w)
	{
		assert(static_cast<unsigned>(w) <= static_cast<unsigned>(h));
		assert(static_cast<unsigned>(h) < static_cast<unsigned>(rank));
		return buffer.at(h * (h + 1) / 2 + w);
	}
};

template <typename T>
struct TriUpper {
	int const rank;
	vector<T> buffer;

	TriUpper(int n)
		: rank(n), buffer(n * (n + 1) / 2) { }

	T& operator()(int h, int w)
	{
		h = rank - 1 - h;
		w = rank - 1 - w;
		assert(static_cast<unsigned>(w) <= static_cast<unsigned>(h));
		assert(static_cast<unsigned>(h) < static_cast<unsigned>(rank));
		return buffer.at(h * (h + 1) / 2 + w);
	}
};

template <typename T>
struct Matrix {
	int rows, cols;
	vector<T> buffer;

	Matrix(int h, int w)
		: rows(h), cols(w), buffer(h * w) { }

	T& operator()(int h, int w)
	{
		assert(static_cast<unsigned>(h) < static_cast<unsigned>(rows));
		assert(static_cast<unsigned>(w) < static_cast<unsigned>(cols));
		return buffer.at(h * cols + w);
	}
};

template <typename T>
std::ostream& operator<<(std::ostream& os, vector<T> const& A)
{
	size_t len = A.size();
	os << "[";
	// oss << "(" << len << ")[";
	for (size_t i = 0; i != len; ++i) {
		os << A[i];
		if (i + 1 != len)
			os << ", ";
	}
	os << "]";
	return os;
}

inline std::ostream& operator<<(std::ostream& os, TreeNode const* root)
{
	os << "[";
	vector<TreeNode const*> Q, T;
	if (root) T.push_back(root);
	while (!T.empty()) {
		Q.swap(T);
		T.clear();
		bool have = false;
		for (auto node : Q)
			if (node) {
				T.push_back(node->left);
				T.push_back(node->right);
				have = have || node->left || node->right;
			}
		if (!have) {
			T.clear();
			while (/*!Q.empty() && */ !Q.back())
				Q.pop_back();
		}
		for (auto node : Q) {
			if (node)
				os << node->val;
			else
				os << "null";
			if (have || node != Q.back())
				os << ", ";
		}
	}
	os << "]";
	return os;
}

inline std::ostream& operator<<(std::ostream& os, ListNode const* head)
{
	os << "[";
	while (head) {
		os << head->val;
		head = head->next;
		if (head)
			os << ", ";
	}
	os << "]";
	return os;
}

#define ToOut(x) \
	std::cout << std::boolalpha << #x " = " << x << std::endl
