#include<bits/stdc++.h>
using namespace std;
//  Perfect Squares

// Iterative + Tabulation: Time => O(n*sqrt(n)) , Space => O(n)
int numSquares(int n) {
    vector < int > dp(n + 1, INT_MAX);
    dp[0] = 0;
    for (int iterator = 1; iterator <= n; iterator++) {
        for (int nestedIterator = 1; nestedIterator * nestedIterator <= iterator; nestedIterator++) {
            dp[iterator] = min(dp[iterator], dp[iterator - nestedIterator * nestedIterator] + 1);
        }
    }
    return dp[n];
}

// BFS Search: Time => O(n), Auxiliary  => O(n)

int numSquares(int n) {
    if (n < 4) return n;
    vector < int > perfectSq;
    vector < bool > visited(n + 1, false);
    for (int iter = 0; iter * iter <= n; iter++) {
        perfectSq.emplace_back(iter * iter);
        visited[iter * iter] = true;
    }
    if (perfectSq.back() == n) return 1;
    queue < int > searchSpace;
    for (auto iter: perfectSq) {
        searchSpace.push(iter);
    }
    int tempVal, tempSize, currentCount = 1;
    while (searchSpace.empty() == false) {
        currentCount++;
        tempSize = searchSpace.size();
        while (tempSize--) {
            tempVal = searchSpace.front();
            searchSpace.pop();
            for (int iter: perfectSq) {
                if (iter + tempVal == n) return currentCount;
                else if (iter + tempVal < n) {
                    if (visited[iter + tempVal] == false) {
                        visited[iter + tempVal] = true;
                        searchSpace.push(iter + tempVal);
                    }
                } else break;
            }
        }
    }
    return -1;

}
