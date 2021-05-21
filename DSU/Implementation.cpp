#include<bits/stdc++.h>
using namespace std;

int parent[1000000];
int rank[1000000];

int findParNotComp(int node){
    if(node==parent[node]){
        return node;
    }

    return findParNotComp(parent[node]);
}

int findParComp(int node){
    if(node==parent[node]){
        return node;
    }

    return parent[node]=findParComp(parent[node]);
}



void unionByRank(int u, int v){
    u=findParComp(u);
    v=findParComp(v);

    if(rank[v]>rank[u]){
        parent[u]=v;
    }else if(rank[v]<rank[u]){
        parent[v]=u;
    }else{
        parent[v]=u;
        rank[u]++;
    }
}
