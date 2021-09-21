#include<bits/stdc++.h>

using namespace std;

// Complexity Time => O((N*M)^2), Space => O(N*M)
int currMax(int row, int col, vector < vector < char >> & matrix) {
    int maxSquareSide = 0;
    for (int rowIterator = row, colIterator = col; rowIterator < matrix.size() && colIterator < matrix[row].size(); rowIterator++, colIterator++) {
        for (int itr1 = row; itr1 <= rowIterator; itr1++) {
            for (int itr2 = col; itr2 <= colIterator; itr2++) {
                if (matrix[itr1][itr2] == '0') return maxSquareSide * maxSquareSide;
            }
        }
        maxSquareSide++;
    }
    return maxSquareSide * maxSquareSide;
}
int maxSquare(int row, int col, vector < vector < char >> & matrix, vector < vector < int > > & dp) {
    if (row == matrix.size() || col == matrix[row].size()) return 0;
    if (dp[row][col] == -1) {
        dp[row][col] = max(currMax(row, col, matrix), max(maxSquare(row + 1, col, matrix, dp), maxSquare(row, col + 1, matrix, dp)));
    }
    return dp[row][col];
}
int maximalSquare(vector < vector < char >> & matrix) {
    vector < vector < int > > dp(matrix.size(), vector < int > (matrix[0].size(), -1));
    return maxSquare(0, 0, matrix, dp);
}

// Complexity Time => O(N*M), Space => O(N*M) { Improved Time Complexity }
int maximalSquare(vector < vector < char >> & matrix) {
    vector < vector < int > > dp(matrix.size(), vector < int > (matrix[0].size(), 0));
    int maxSquareSide = 0;

    for (int iterator = 0; iterator < matrix.size(); iterator++) {
        if (matrix[iterator][0] == '1') dp[iterator][0] = 1;
        maxSquareSide = max(maxSquareSide, dp[iterator][0]);
    }
    for (int iterator = 1; iterator < matrix[0].size(); iterator++) {
        if (matrix[0][iterator] == '1') dp[0][iterator] = 1;
        maxSquareSide = max(maxSquareSide, dp[0][iterator]);
    }

    for (int upperIterator = 1; upperIterator < matrix.size(); upperIterator++) {
        for (int innerIterator = 1; innerIterator < matrix[upperIterator].size(); innerIterator++) {

            if (matrix[upperIterator][innerIterator] == '1') {
                dp[upperIterator][innerIterator] = min(dp[upperIterator - 1][innerIterator - 1], min(dp[upperIterator - 1][innerIterator], dp[upperIterator][innerIterator - 1])) + 1;
                maxSquareSide = max(maxSquareSide, dp[upperIterator][innerIterator]);
            }

        }
    }
    return maxSquareSide * maxSquareSide;
}


// Complexity Time => O(N*M), Space => O(M) { Improved Space Complexity }
int maximalSquare(vector < vector < char >> & matrix) {
    if (matrix.size() == 0 || matrix[0].size() == 0) return 0;
    vector < int > dp(matrix[0].size(), 0);
    int prevState = 0, maxSquareSide = 0, tempVariable;
    for (int iterator = 0; iterator < matrix[0].size(); iterator++) {
        dp[iterator] = matrix[0][iterator] == '1' ? 1 : 0;
        maxSquareSide = max(maxSquareSide, dp[iterator]);
    }

    for (int upperIterator = 1; upperIterator < matrix.size(); upperIterator++) {
        prevState = dp[0];
        dp[0] = matrix[upperIterator][0] == '1' ? 1 : 0;
        maxSquareSide = max(maxSquareSide, dp[0]);
        for (int innerIterator = 1; innerIterator < matrix[0].size(); innerIterator++) {

            if (matrix[upperIterator][innerIterator] == '1') {
                tempVariable = min(prevState, min(dp[innerIterator], dp[innerIterator - 1])) + 1;
                maxSquareSide = max(tempVariable, maxSquareSide);
                prevState = dp[innerIterator];
                dp[innerIterator] = tempVariable;
            } else {
                prevState = dp[innerIterator];
                dp[innerIterator] = 0;
            }
        }
    }
    return maxSquareSide * maxSquareSide;
}
