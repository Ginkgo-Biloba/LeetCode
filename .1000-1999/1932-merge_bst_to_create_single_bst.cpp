#include "leetcode.hpp"

/* 1932. 合并多棵二叉搜索树

给你 n 个 二叉搜索树的根节点 ，存储在数组 trees 中（下标从 0 开始），对应 n 棵不同的二叉搜索树。
trees 中的每棵二叉搜索树 最多有 3 个节点 ，且不存在值相同的两个根节点。
在一步操作中，将会完成下述步骤：

  选择两个 不同的 下标 i 和 j ，要求满足在 trees[i] 中的某个 叶节点 的值等于 trees[j] 的 根节点的值 。
  用 trees[j] 替换 trees[i] 中的那个叶节点。
  从 trees 中移除 trees[j] 。

如果在执行 n - 1 次操作后，能形成一棵有效的二叉搜索树，则返回结果二叉树的 根节点；如果无法构造一棵有效的二叉搜索树，返回 null 。

二叉搜索树是一种二叉树，且树中每个节点均满足下述属性：
  任意节点的左子树中的值都 严格小于 此节点的值。
  任意节点的右子树中的值都 严格大于 此节点的值。

叶节点是不含子节点的节点。

示例 1：
https://assets.leetcode.com/uploads/2021/06/08/d1.png
输入：trees = [[2,1],[3,2,5],[5,4]]
输出：[3,2,5,1,null,4]
解释：
第一步操作中，选出 i=1 和 j=0 ，并将 trees[0] 合并到 trees[1] 中。
删除 trees[0] ，trees = [[3,2,5,1],[5,4]] 。
https://assets.leetcode.com/uploads/2021/06/24/diagram.png
在第二步操作中，选出 i=0 和 j=1 ，将 trees[1] 合并到 trees[0] 中。
删除 trees[1] ，trees = [[3,2,5,1,null,4]] 。
https://assets.leetcode.com/uploads/2021/06/24/diagram-2.png
结果树如上图所示，为一棵有效的二叉搜索树，所以返回该树的根节点。

示例 2：
https://assets.leetcode.com/uploads/2021/06/08/d2.png
输入：trees = [[5,3,8],[3,2,6]]
输出：[]
解释：
选出 i=0 和 j=1 ，然后将 trees[1] 合并到 trees[0] 中。
删除 trees[1] ，trees = [[5,3,8,2,6]] 。
https://assets.leetcode.com/uploads/2021/06/24/diagram-3.png
结果树如上图所示。仅能执行一次有效的操作，但结果树不是一棵有效的二叉搜索树，所以返回 null 。

示例 3：
https://assets.leetcode.com/uploads/2021/06/08/d3.png
输入：trees = [[5,4],[3]]
输出：[]
解释：无法执行任何操作。

提示：
  n == trees.length
  1 <= n <= 5 * 10^4
  每棵树中节点数目在范围 [1, 3] 内。
  输入数据的每个节点可能有子节点但不存在子节点的子节点
  trees 中不存在两棵树根节点值相同的情况。
  输入中的所有树都是 有效的二叉树搜索树 。
  1 <= TreeNode.val <= 5 * 10^4.
*/

// https://leetcode-cn.com/problems/merge-bsts-to-create-single-bst/solution/he-bing-duo-ke-er-cha-sou-suo-shu-by-lee-m42t/
// 抄的
class Solution {
	static int const limit = static_cast<int>(5e4 + 1);
	// prev: 中序遍历上一个值，用于检查单调性
	int prev, rest;
	vector<char> leaf;      // 有没有这个叶子节点
	vector<TreeNode*> cand; // 根节点的值，根

	// 中序遍历
	bool travel(TreeNode* t)
	{
		if (!t)
			return true;

		// 如果到叶子节点，并且存在可以合并的树，那么就合并
		if (!t->left && !t->right && cand[t->val]) {
			t->left = cand[t->val]->left;
			t->right = cand[t->val]->right;
			rest -= 1;
			cand[t->val] = nullptr;
		}

		// 遍历左边、当前、右边
		if (!travel(t->left))
			return false;
		if (t->val <= prev)
			return false;
		prev = t->val;
		return travel(t->right);
	}

public:
	TreeNode* canMerge(vector<TreeNode*>& trees)
	{
		prev = rest = 0;
		leaf.assign(limit, 0);
		cand.assign(limit, nullptr);

		for (auto t : trees) {
			if (t->left)
				leaf[t->left->val] = 1;
			if (t->right)
				leaf[t->right->val] = 1;
			rest += 1;
			cand[t->val] = t;
		}

		for (auto t : trees)
			if (!leaf[t->val]) {
				rest -= 1;
				cand[t->val] = nullptr;
				bool fin = travel(t) && (rest == 0);
				return fin ? t : nullptr;
			}
		return nullptr;
	}
};

int main() { }
