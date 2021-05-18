// https://leetcode.com/problems/course-schedule/

//By checking in both recusive and visited array

#include<bits/stdc++.h>
using namespace std;

bool check(int a,vector<int> &vis, vector<int> &rec,vector<int> arr[]){
    if(!vis[a]){
        vis[a]=1;
        rec[a]=1;
        
        for(int child : arr[a]){
            if(!vis[child]){
                if(check(child,vis,rec,arr)) return true;
            }
            else {
                if(rec[child]) return true;
            }
        }
    }
    
    rec[a]=0;
    return false;
}
bool canFinish(int num, vector<vector<int>>& pre) {
     vector<int> arr[num];
    
    for(int i=0;i<pre.size();i++){
      arr[pre[i][0]].push_back(pre[i][1]);  
    }
    
    vector<int> vis(num,0);
    vector<int> rec(num,0);
    
    for(int i=0;i<num;i++){
       if( check(i,vis,rec,arr)) return false;
    }
    return true;
}