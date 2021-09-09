#include<bits/stdc++.h>
using namespace std;
//  Triangle
	// Recursive: Time => O(2^n), Auxiliary  => O(2^n)
	int recursiveFunction(int row, int index, vector < vector < int > > & triangle){
        if(row == triangle.size() - 1) return triangle[row][index];
        return min(recursiveFunction(row + 1, index, triangle),recursiveFunction(row + 1, index + 1, triangle)) + triangle[row][index];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.size() == 0 || triangle[0].size() == 0) return 0;
        return recursiveFunction(0, 0, triangle);
    }

	// Recursion + Memorization: Time => O(n*n) , Space => O(n*n)
	int recursiveFunction(int row, int index, vector < vector < int > > & triangle, vector < vector<int> >&dp){
        if(row == triangle.size() - 1) return triangle[row][index];
        if(dp[row][index] == -1){
            dp[row][index] =  min(recursiveFunction(row + 1, index, triangle, dp),recursiveFunction(row + 1, index + 1, triangle, dp)) + triangle[row][index];
        }
        return dp[row][index];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.size() == 0 || triangle[0].size() == 0) return 0;
        vector < vector < int > > dp;
        for(int i = 0; i<triangle.size(); i++){
            vector < int > temp(i + 1, - 1);
            dp.push_back(temp);
        }
        return recursiveFunction(0, 0, triangle, dp);
    }

	// Iterative + Tabulation: Time => O(n*n) , Space => O(n*n)
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.size() == 0) return 0;
        vector < vector < int > > dp;
        for(int i = 0; i<triangle.size(); i++){
            vector < int > temp(i + 1, INT_MAX);
            dp.push_back(temp);
        }
        dp[0][0] = triangle[0][0];
        
        for(int i = 1; i<triangle.size(); i++){
            dp[i][0] = dp[i - 1][0] + triangle[i][0];
            dp[i][dp[i].size() - 1] = dp[i - 1][dp[i - 1].size() - 1] + triangle[i][dp[i].size() - 1];
        }
        for(int i = 2; i<dp.size(); i++){
            for(int j = 1; j<dp[i].size() - 1; j++){
                dp[i][j] = min(dp[i-1][j], dp[i-1][j-1]) + triangle[i][j];
            }
        }
        int minimumSum = INT_MAX;
        for(int  i = 0; i<dp[dp.size() - 1].size(); i++){
            minimumSum = min(minimumSum, dp[dp.size() - 1][i]);
        }
        return minimumSum;
    }

    // Iterative + Tabulation: Time => O(n*n) , Space => O(n) with linear space complexity
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.size() == 0) return 0;
        vector < int > dp(triangle.size(), INT_MAX);
        dp[0]= triangle[0][0];
        for(int  i = 1; i<triangle.size(); i++){
            for(int j = i; j> -1; j--){
                dp[j] = min(j-1>=0?dp[j-1]:INT_MAX, dp[j]) + triangle[i][j];
            }
        }
        return *min_element(dp.begin(), dp.end());
    }

    // Iterative + Tabulation: Time => O(n*n) , Space => O(1) with constant space complexity
    int minimumTotal(vector<vector<int>>& triangle) {
        for(int i = 1; i<triangle.size(); i++){
            triangle[i][0] += triangle[i - 1][0];
            triangle[i][triangle[i].size() - 1]+= triangle[i - 1][triangle[i - 1].size() - 1];
            for(int j = 1; j<triangle[i].size() - 1; j++){
                triangle[i][j]+= min(triangle[i-1][j], triangle[i-1][j-1]);
            }
        }
        int minimumSum = INT_MAX;
        for(int  i = 0; i<triangle[triangle.size() - 1].size(); i++){
            minimumSum = min(minimumSum, triangle[triangle.size() - 1][i]);
        }
        return minimumSum;
    }
