#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <map>
#include <set>
#include <math.h>
#include <stdio.h>
#include <string>
#include<algorithm>
#include <math.h>
#include <stack> 

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() == 0){
            return 0;
        }

        vector<int> dp(nums.size(), 0);
        dp[0] = 1;
        int LIS = 1;
        for (int i = 1; i < dp.size(); i++){
            dp[i] = 1;

            for (int j = 0; j < i; j++){
                if (nums[i] > nums[j] && dp[i] < dp[j] + 1){
                    dp[i] = dp[j] + 1;
                }
            }

            if (LIS < dp[i]){
                LIS = dp[i];
            }
        }

        return LIS;
    }
};

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() == 0){
            return 0;
        }

        vector<int> stack;
        stack.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++){
            if(nums[i] > stack.back()){
                stack.push_back(nums[i]);
            }

            else{
                for (int j = 0; j < stack.size(); j++){
                    if (stack[j] >= nums[i]){
                        stack[j] = nums[i];
                        break;
                    }
                }
            }
        }

        return stack.size();
    }
};
