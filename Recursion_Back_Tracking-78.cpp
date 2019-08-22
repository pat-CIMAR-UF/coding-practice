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

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> item;
        vector<vector<int> > result;

        result.push_back(item);
        generate(0, nums, item, result);
        return result;
    }

private:
    void generate(int i, vector<int> &nums, vector<int> &item, vector<vector<int> > &result){
        if (i>= nums.size()) return;

        item.push_back(nums[i]);
        result.push_back(item);
        generate(i+1, nums, item, result);

        item.pop_back();
        generate(i+1, nums, item, result);
    }
};

class Solution2{
public:
    vector<vector<int> > subsets(vector<int> &nums){
        vector<vector<int> > result;

        int all_set = 1 << nums.size();

        for (int i = 0; i < all_set; i++){
            vector<int> item;
            for(int j = 0; j < nums.size(); j++){
                if ( i & (1 << j)){
                    item.push_back(nums[j]);
                }
            }

            result.push_back(item);
        }

        return result;
    }
};