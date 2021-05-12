// link: https://leetcode.com/problems/number-of-islands/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    void mark(vector<vector<char>>& grid, int x, int y, int rows, int cols){
        if(x<0 || x>=rows || y<0 || y>=cols || grid[x][y]!='1'){
            return;
        }
        grid[x][y]='2';
        mark(grid, x+1, y, rows, cols);
        mark(grid, x-1, y, rows, cols);
        mark(grid, x, y+1, rows, cols);
        mark(grid, x, y-1, rows, cols);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        if(rows==0){
            return 0;
        }
        int cols = grid[0].size();
        
        int ctr=0;
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(grid[i][j]=='1'){
                    mark(grid, i, j, rows, cols);
                    ctr++;
                }
            }
        }
        
        return ctr;
    }
};