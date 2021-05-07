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
    printBFS(edges, n, sv);
}

//Input
/*8
9
0 4
0 5
4 3
3 2
2 1
1 3
5 6
3 6
6 7*/