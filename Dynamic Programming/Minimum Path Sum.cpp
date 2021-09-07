#include<bits/stdc++.h>
using namespace std;
//  Minimum Path Sum in Grid
	// Recursive Time => O(2^n), Space => O(2^n)
	int rec(int row, int col, vector<vector<int>>& grid){
		
		if(row >= grid.size() || col >=grid[0].size()) return INT_MAX;
		if(row == grid.size()-1 && col ==grid[0].size()-1) return grid[row][col];
		return min(rec(row + 1, col, grid), rec(row, col + 1, grid)) + grid[row][col];
	}
	int minPathSum(vector<vector<int>>& grid) {
		
		return rec(0, 0, grid);
	}

	// Recursion + Memorization => O(n*n), O(n*n)
	int rec(int row, int col, vector<vector<int>>& grid, vector < vector < int > >&dp){
		
		if(row >= grid.size() || col >=grid[0].size()) return INT_MAX;
		if(row == grid.size()-1 && col ==grid[0].size()-1) return grid[row][col];   
		if(dp[row][col] == -1){

			dp[row][col] =  min(rec(row + 1, col, grid, dp), rec(row, col + 1, grid, dp)) + grid[row][col];
		}
		return dp[row][col];
    	}
	int minPathSum(vector<vector<int>>& grid) {
		
		if(grid.size() == 0 || grid[0].size() == 0)return 0;
		vector < vector < int > > dp(grid.size() , vector < int > (grid[0].size() , -1 ));
		return rec(0, 0, grid, dp);
	}

	// Iterative+Tabulation: Time => O(n*n) , Space => O(n*n)
    	int minPathSum(vector<vector<int>>& grid) {
		
		if(grid.size() == 0) return 0;
		int row = grid.size(), col = grid[0].size();
		for(int iterator = 1; iterator	< row; iterator++){
			grid[iterator][0] += grid[iterator - 1][0];
		}
		for(int iterator = 1; iterator < col; iterator++){
			grid[0][iterator] += grid[0][iterator - 1];
		}
		for(int rowIterator = 1; rowIterator < row; rowIterator++){
			for(int colIterator = 1; colIterator < col; colIterator++){
				grid[rowIterator][colIterator] += min(grid[rowIterator - 1][colIterator], grid[rowIterator][colIterator - 1]);
			}
		}
		return grid[row - 1][col - 1];
    	}
