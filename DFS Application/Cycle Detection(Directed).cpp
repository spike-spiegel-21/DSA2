// https://leetcode.com/problems/course-schedule/

//By checking in both recusive and visited array
// By using 0->unvisited 1->processing 2->processed

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    bool isCyclic(int i, vector<int> adj[], vector<int> &visited, int n){
        if(visited[i]==1){
            return 1;
        }
        
        visited[i]=1;
        
        for(auto x: adj[i]){
            if(visited[x]!=2){
                if(isCyclic(x, adj, visited, n)){
                    return 1;
                }
            }
        }
        
        visited[i]=2;
        return 0;
    }
    
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> visited(numCourses, 0);
        vector<int> adj[numCourses];
        
        for(auto x: prerequisites){
            adj[x[0]].push_back(x[1]);
        }
        
        for(int i=0; i<numCourses; i++){
            if(visited[i]==0){
                if(isCyclic(i, adj, visited, numCourses)){
                    return 0;
                }
            }
        }
        
        return 1;
    }
};
