﻿#include "leetcode.hpp"

/* 1882. 使用服务器处理任务

给你两个 下标从 0 开始 的整数数组 servers 和 tasks ，长度分别为 n​​​​​​ 和 m​​​​​​ 。
servers[i] 是第 i​​​​​​​​​​ 台服务器的 权重 ，而 tasks[j] 是处理第 j​​​​​​ 项任务 所需要的时间（单位：秒）。

你正在运行一个仿真系统，在处理完所有任务后，该系统将会关闭。
每台服务器只能同时处理一项任务。第 0 项任务在第 0 秒可以开始处理，相应地，第 j 项任务在第 j 秒可以开始处理。
处理第 j 项任务时，你需要为它分配一台 权重最小 的空闲服务器。
如果存在多台相同权重的空闲服务器，请选择 下标最小 的服务器。
如果一台空闲服务器在第 t 秒分配到第 j 项任务，那么在 t + tasks[j] 时它将恢复空闲状态。

如果没有空闲服务器，则必须等待，直到出现一台空闲服务器，并 尽可能早 地处理剩余任务。
如果有多项任务等待分配，则按照 下标递增 的顺序完成分配。

如果同一时刻存在多台空闲服务器，可以同时将多项任务分别分配给它们。

构建长度为 m 的答案数组 ans ，其中 ans[j] 是第 j 项任务分配的服务器的下标。

返回答案数组 ans​​​​ 。

示例 1：
输入：servers = [3,3,2], tasks = [1,2,3,2,1,2]
输出：[2,2,0,2,1,2]
解释：事件按时间顺序如下：
- 0 秒时，第 0 项任务加入到任务队列，使用第 2 台服务器处理到 1 秒。
- 1 秒时，第 2 台服务器空闲，第 1 项任务加入到任务队列，使用第 2 台服务器处理到 3 秒。
- 2 秒时，第 2 项任务加入到任务队列，使用第 0 台服务器处理到 5 秒。
- 3 秒时，第 2 台服务器空闲，第 3 项任务加入到任务队列，使用第 2 台服务器处理到 5 秒。
- 4 秒时，第 4 项任务加入到任务队列，使用第 1 台服务器处理到 5 秒。
- 5 秒时，所有服务器都空闲，第 5 项任务加入到任务队列，使用第 2 台服务器处理到 7 秒。

示例 2：
输入：servers = [5,1,4,3,2], tasks = [2,1,2,4,5,2,1]
输出：[1,4,1,4,1,3,2]
解释：事件按时间顺序如下：
- 0 秒时，第 0 项任务加入到任务队列，使用第 1 台服务器处理到 2 秒。
- 1 秒时，第 1 项任务加入到任务队列，使用第 4 台服务器处理到 2 秒。
- 2 秒时，第 1 台和第 4 台服务器空闲，第 2 项任务加入到任务队列，使用第 1 台服务器处理到 4 秒。
- 3 秒时，第 3 项任务加入到任务队列，使用第 4 台服务器处理到 7 秒。
- 4 秒时，第 1 台服务器空闲，第 4 项任务加入到任务队列，使用第 1 台服务器处理到 9 秒。
- 5 秒时，第 5 项任务加入到任务队列，使用第 3 台服务器处理到 7 秒。
- 6 秒时，第 6 项任务加入到任务队列，使用第 2 台服务器处理到 7 秒。

提示：
  servers.length == n
  tasks.length == m
  1 <= n, m <= 2 * 10^5
  1 <= servers[i], tasks[j] <= 2 * 10^5
*/

vector<int> assignTasks(vector<int>& servers, vector<int>& tasks)
{
	using elem = array<int64_t, 3>;
	int64_t slen = servers.size();
	int64_t tlen = tasks.size();
	vector<int> ans;
	priority_queue<elem, vector<elem>, std::greater<elem>> busy, idle;
	for (int64_t i = 0; i < slen; ++i)
		idle.push({0, servers[i], i});
	for (int64_t t = 0; t < tlen; ++t) {
		while (busy.size() && (busy.top()[0] <= t || idle.empty())) {
			elem e = busy.top();
			busy.pop();
			idle.push({e[0] <= t ? 0 : e[0], e[1], e[2]});
		}
		elem e = idle.top();
		idle.pop();
		busy.push({max(e[0], t) + tasks[t], e[1], e[2]});
		ans.push_back(static_cast<int>(e[2]));
	}
	return ans;
}

int main()
{
}
