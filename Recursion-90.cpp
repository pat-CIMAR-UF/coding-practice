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
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int> > result;
        vector<int> item;
        set<vector<int> > res_set;

        sort(nums.begin(), nums.end());

        result.push_back(item);
        generate(0, nums, result, item, res_set);

        return result;
    }

    void generate(int i, vector<int> &nums, vector<vector<int> > &result, vector<int> &item, set<vector<int> > &res_set){
        if (i >= nums.size()) return;

        item.push_back(nums[i]);
        if(res_set.find(item) == res_set.end()){
            result.push_back(item);
            res_set.insert(item);
        }

        generate(i + 1, nums, result, item, res_set);
        item.pop_back();
        generate(i + 1, nums, result, item, res_set);
    }
};