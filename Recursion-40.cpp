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
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int> >result;
        vector<int> item;
        set<vector<int> >res_set;
        sort(candidates.begin(), candidates.end());
        generate(0, candidates, result, item, res_set, 0, target);
        return result;
    }
private:
    void generate(int i, vector<int> &nums, vector<vector<int> > &result, vector<int> &item, set<vector<int> > &res_set, int sum, int target){
        if ( i >= nums.size() || sum > target){
            return;
        }

        sum += nums[i];
        item.push_back(nums[i]);

        if (target == sum && res_set.find(item) == res_set.end()){
            result.push_back(item);
            res_set.insert(item);
        }

        generate(i + 1, nums, result, item, res_set, sum, target);

        sum -= nums[i];
        item.pop_back();
        
        generate(i + 1, nums, result, item, res_set, sum, target);
    }
};