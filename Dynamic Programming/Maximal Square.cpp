#include<bits/stdc++.h>

using namespace std;
//  Maximal Square

// n = number of rows and m = number of columns

// Recursive: Time => O((n*m)^2), Auxiliary  => O(n*m)
int currMax(int row, int col, vector<vector<char>>& matrix){
    int maxSideOfSquare = 0;
    for(int  iterator = row, nestedIterator = col; iterator<matrix.size() && nestedIterator < matrix[row].size(); iterator++, nestedIterator++){
        for(int itr1 = row; itr1 <= iterator; itr1++){
            for(int itr2 = col; itr2 <= nestedIterator; itr2++){
                if(matrix[itr1][itr2] == '0')  return maxSideOfSquare*maxSideOfSquare;
            }
        }
        maxSideOfSquare++;
    }
    return maxSideOfSquare*maxSideOfSquare;
}
int maxSquare(int row, int col, vector<vector<char>>& matrix,vector < vector < int > >&dp){
    if(row == matrix.size() || col == matrix[row].size()) return 0;
    if(dp[row][col] == -1){
    dp[row][col] =  max(currMax(row, col, matrix), max(maxSquare(row + 1, col, matrix,dp), maxSquare(row, col + 1, matrix,dp)));
    }
    return dp[row][col];
}
int maximalSquare(vector<vector<char>>& matrix) {
    vector < vector < int > > dp(matrix.size(), vector < int >(matrix[0].size(), -1));
    return maxSquare(0, 0, matrix, dp);
}

// Iterative + Tabulation: Time => O(n*m) , Space => O(n*m)
int maximalSquare(vector<vector<char>>& matrix) {
    vector < vector < int > > dp(matrix.size(), vector < int> (matrix[0].size(), 0));
    int maxSideOfSquare = 0;                                                        
       for(int  iterator = 0; iterator<matrix.size(); iterator++) {
          if(matrix[iterator][0] == '1') dp[iterator][0] = 1;
           maxSideOfSquare = max(maxSideOfSquare, dp[iterator][0]);
        }
         for(int  iterator = 1; iterator<matrix[0].size(); iterator++) {
          if(matrix[0][iterator] == '1') dp[0][iterator] = 1;
             maxSideOfSquare = max(maxSideOfSquare, dp[0][iterator]);
        }           
                                                                        
       for(int iterator  = 1; iterator<matrix.size(); iterator++){
           for(int nestedIterator = 1; nestedIterator<matrix[iterator].size(); nestedIterator++){
              
               if(matrix[iterator][nestedIterator] == '1')
               {dp[iterator][nestedIterator] = min(dp[iterator - 1][nestedIterator - 1],min(dp[iterator - 1][nestedIterator], dp[iterator][nestedIterator - 1])) + 1;
                maxSideOfSquare = max(maxSideOfSquare, dp[iterator][nestedIterator]);
               }
               
           }
       }
    return maxSideOfSquare*maxSideOfSquare;
}

// Iterative + Tabulation: Time => O(n*m) , Space => O(n) with linear space complexity

int maximalSquare(vector<vector<char>>& matrix) {
    vector < int > dp(matrix[0].size(), 0);
    int previousValueHolder = 0, maxSideOfSquare = 0, tempValueHolder;
    for(int iterator = 0; iterator<matrix[0].size(); iterator++){
        dp[iterator] = matrix[0][iterator] == '1'? 1: 0;
        maxSideOfSquare = max(maxSideOfSquare, dp[iterator]);
    }
    
    for(int iterator = 1; iterator<matrix.size(); iterator++){
        previousValueHolder = dp[0];
        dp[0] = matrix[iterator][0] == '1'? 1: 0;
        maxSideOfSquare = max(maxSideOfSquare, dp[0]);
        for(int  nestedIterator = 1; nestedIterator<matrix[0].size(); nestedIterator++){
            
            if(matrix[iterator][nestedIterator] == '1') {
                tempValueHolder = min(previousValueHolder, min(dp[nestedIterator], dp[nestedIterator - 1])) + 1; 
                maxSideOfSquare = max(tempValueHolder, maxSideOfSquare);
                previousValueHolder = dp[nestedIterator];
                dp[nestedIterator] = tempValueHolder;
                }
            else {
                previousValueHolder = dp[nestedIterator];
                dp[nestedIterator] = 0;
            }
        }
    }
    return maxSideOfSquare * maxSideOfSquare;
}

