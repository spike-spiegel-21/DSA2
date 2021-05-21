// Steps to implement BFS.
//     1. Select the staring vertex.
//     2. Add that veretex in the queue, and mark that visited.
//     3. Run a loop. While(queue is no empty).
//         3a. Copy the first element(e) of queue and pop it out.
//         3b. Print that copy.
//         3c. For(All adjacent nodes of "e")
//                 if not visited -> mark visted -> push in queue.


#include<iostream>
#include<queue>
using namespace std;

void print(int** edges, int n, int sv, bool* visited){
    cout<<sv<<endl;
    visited[sv]=1;
    for(int i=0; i<n; i++){

        if(i==sv){
            continue;
        }

        if(edges[sv][i]==1){
            if(visited[i]==1){
                continue;
            }
            print(edges, n, i, visited);
        }

    }
}

bool hasPath(int** edges, int n, int sv, int en, bool* visited){
    visited[sv]=1;
    if(edges[sv][en] == 1){
            return true;
    }
    for(int i=0; i<n; i++){
        if(visited[i]==0){
            if(hasPath(edges, n, i, en, visited)){
                return true;
            }
        }    
    }

    return false;

}

void printBFS(int** edges, int n, int sv){
    queue<int> pendingVertives;
    bool* visited = new bool[n];
    for(int i=0; i<n; i++){
        visited[i]=false;
    }
    pendingVertives.push(sv);
    visited[sv]=true;
    while(!pendingVertives.empty()){
        int currentVertex = pendingVertives.front();
        pendingVertives.pop();
        cout<<currentVertex<<endl;
        for(int i=0; i<n; i++){
            if(i==currentVertex){
                continue;
            }

            if(edges[currentVertex][i] == 1 && !visited[i]){
                pendingVertives.push(i);
                visited[i]=true;
            }
        }
    }
}

int main() {
    int n; 
    int e;
    cin>>n>>e; 

    int** edges = new int*[n];

    for(int i=0; i<n; i++){
        edges[i] = new int[n];
        for(int j=0; j<n; j++){
            edges[i][j]=0;
        }
    }

    for(int i=0; i<e; i++){
        int f,s;
        cin>>f>>s;
        edges[f][s]=1;
        edges[s][f]=1;
    }

    int sv=0;
    bool* visited = new bool[n];
    for(int i=0; i<n; i++){
        visited[i]=0;
    }
 //   print(edges, n, sv, visited);
 //   printBFS(edges, n, sv);
    if(hasPath(edges, n, 0, 7, visited)){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
 //   cout<<hasPath(edges, n, 0, 7);
}

//Input
/*
8
9
0 4
0 5
4 3
3 2
2 1
1 3
5 6
3 6
6 7
*/
