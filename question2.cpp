//question 2//
#include <bits/stdc++.h>
using namespace std;
// function to find the shortest subarray with sum equal to k
int shortestSubarraySumK(vector<int>& nums, int k) {
    int minLength = INT_MAX;
    int sum = 0;
    int start = 0;
    map<int, int> mp; 
	// map to store the index of the sum
    mp[0] = -1;
	 // setting the index of sum 0 to -1

    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];

        // if the sum is greater than k, remove elements from the start
        while (sum > k) {
            sum -= nums[start];
            start++;
        }

        // if the sum is equal to k, update the minimum length
        if (sum == k) {
            minLength = min(minLength, i - start + 1);
        }

        // if the sum is not found in the map, add it
        if (mp.find(sum) == mp.end()) {
            mp[sum] = i;
        }
        // if the sum is found in the map, update the minimum length
        else {
            minLength = min(minLength, i - mp[sum]);
        }
    }

    // if the minimum length is INT_MAX, return -1
    if (minLength == INT_MAX) {
        return -1;
    }

    return minLength;
}

int main(){
    int n;int k;
    cin >> n >> k;
    vector<int> nums(n);
    for( int i=0;i<n;i++){
        cin >> nums[i];
    }
    cout << shortestSubarraySumK(nums,k);
    
}
// overall complexity is O(n) due to one for loop only 
