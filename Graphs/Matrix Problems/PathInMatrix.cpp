#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Solution Using DFS
void dfs(int i,int j,int row,int col,int x,int y,vector<vector<int>> &A){
    if(i<0 || j<0 || i>=row || j>=col || A[i][j] == 0) return;
    if(i == x && j == y){
        A[i][j] = 0;
        return;
    }
    A[i][j] = 0;
    dfs(i+1,j,row,col,x,y,A);
    dfs(i-1,j,row,col,x,y,A);
    dfs(i,j+1,row,col,x,y,A);
    dfs(i,j-1,row,col,x,y,A);

}

int checkPath(vector<vector<int> > &A) {
    int scx,scy,dex,dey;
    int row = A.size();
    int col = A[0].size();
    for(int i=0;i<A.size();i++){
        for(int j=0;j<A[0].size();j++){
            if(A[i][j] == 1) scx = i,scy = j;
            else if(A[i][j] == 2) dex = i, dey = j;
        }
    }
    dfs(scx,scy,row,col,dex,dey,A);
    if(A[dex][dey] == 0) return 1;
    return 0;
}

/*
Given N x N matrix filled with 0, 1, 2, 3.

Find whether there is a path possible from source to destination, traversing through blank cells only. 
 
You can traverse up, down, right, and left. Return a single integer 1 if a path exists, otherwise 0.

A value of cell 1 means Source.
A value of cell 2 means Destination.
A value of cell 3 means Blank cell.
A value of cell 0 means Blank Wall.
Note: there are an only a single source and single destination(sink).


Problem Constraints
2 <= N <= 103
0 <= Ai, j <= 3


Input Format
The first argument is the 2D integer array A.


Output Format
Return a single integer 1 if a path exists, otherwise 0.


Example Input
Input 1:
A = [[1, 0], [0, 2]]
Input 2:

A = [[1, 3], [3, 2]]


Example Output
Output 1:
0
Output 2:

1


Example Explanation
Explanation 1:
The source is blocked by walls on all its sides. So, there is no way to reach the destination.
Explanation 2:

We can take any possible path to reach the destination from the source.
*/