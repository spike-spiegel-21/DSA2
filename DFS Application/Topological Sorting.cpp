// https://leetcode.com/problems/course-schedule-ii/

//By cutting every node with indegree 0 and putting them inside queue. And then cheking nex for the same.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<vector<int>> adj(n, vector<int>());
        vector<int> degree(n, 0);
        for (auto &p: pre) {
            adj[p[1]].push_back(p[0]);
            degree[p[0]]++;
        }
        queue<int> q;
        vector<int> res;
        for (int i = 0; i < n; i++)
            if (degree[i] == 0) {
                q.push(i);
                res.push_back(i);
            }
        while (!q.empty()) {
            int curr = q.front(); q.pop(); n--;
            for (auto next: adj[curr])
                if (--degree[next] == 0) 
                {
                    q.push(next);
                    res.push_back(next);   
                }
        }
        if(n==0)
            return res;
        else
            return {};
    }
};