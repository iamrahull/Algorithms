#include<bits/stdc++.h>

using namespace std;
// Next Greatest Element 2
// Complexity Time => O(2*n) Space => O(n) Easy Implementation
vector < int > nextGreaterElements(vector < int > & nums) {
    stack < int > container;
    vector < int > nextGreatest(nums.size(), -1);
    for (int iterator = 0; iterator < nums.size() || (iterator < nums.size() * 2 && !container.empty()); iterator++) {
        int temp = nums[iterator % nums.size()];
        if (container.empty() || nums[container.top()] >= temp) {
            container.push(iterator % nums.size());
        } else {
            while (container.empty() == false && nums[container.top()] < temp) {
                nextGreatest[container.top()] = temp;
                container.pop();
            }
            container.push(iterator % nums.size());
        }
    }

    for (int iterator = 0; iterator < nums.size() && container.empty() == false; iterator++) {
        while (!container.empty() && nums[container.top()] == nums[iterator]) {
            nextGreatest[container.top()] = nextGreatest[iterator];
            container.pop();
        }
        while (!container.empty() && nums[container.top()] < nums[iterator]) {
            nextGreatest[container.top()] = nums[iterator];
            container.pop();
        }
    }
    return nextGreatest;
}
// Complexity Time => O(2*n) Space => O(n) 
vector < int > nextGreaterElements(vector < int > & nums) {
    stack < int > container;
    vector < int > nextGreatest(nums.size(), -1);
    for (int iterator = 0; iterator < nums.size() || (iterator < nums.size() * 2 && !container.empty()); iterator++) {
        int temp = nums[iterator % nums.size()];
        if (container.empty() || nums[container.top()] >= temp) {
            container.push(iterator % nums.size());
        } else {
            while (container.empty() == false && nums[container.top()] < temp) {
                nextGreatest[container.top()] = temp;
                container.pop();
            }
            container.push(iterator % nums.size());
        }
    }
    return nextGreatest;
}
