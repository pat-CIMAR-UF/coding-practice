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

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<int> index;
        for(int i = 0; i < nums.size(); i++){
            index.push_back(i + nums[i]);
        }
        int jump = 0;
        int max_index = index[0];
        while(jump < index.size() && jump <= max_index){
            if (max_index < index[jump]){
                max_index = index[jump];
            }
            jump++;
        }

        if (jump == nums.size()) return true;

        return false;
    }
};