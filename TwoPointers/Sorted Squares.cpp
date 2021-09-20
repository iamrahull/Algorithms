#include<bits/stdc++.h>
using namespace std;
// Complexity Time => O(n) Space => O(n)
vector<int> sortedSquares(vector<int>& nums) {
    	int numsSize = nums.size();
        int firstPositiveElementIndex = numsSize;
        for(int  i = 0; i<numsSize; i++){
            if(firstPositiveElementIndex == numsSize && nums[i] > -1) firstPositiveElementIndex = i;
            	nums[i]*=nums[i];
        }
        if(firstPositiveElementIndex == 0) return nums;
        int lastNegativeElementIndex = firstPositiveElementIndex - 1, iterator = 0;
        vector < int > sortedSquaresArray(numsSize);
        while(firstPositiveElementIndex <numsSize && lastNegativeElementIndex > -1){
        	if(nums[firstPositiveElementIndex]< nums[lastNegativeElementIndex]){
        		sortedSquaresArray[iterator++] = nums[firstPositiveElementIndex++];
        	}
        	else sortedSquaresArray[iterator++] = nums[lastNegativeElementIndex--];
        }
        while(firstPositiveElementIndex < numsSize) sortedSquaresArray[iterator++] = nums[firstPositiveElementIndex++];
        while(lastNegativeElementIndex > -1) sortedSquaresArray[iterator++] = nums[lastNegativeElementIndex--];
        return sortedSquaresArray;
    }
};
