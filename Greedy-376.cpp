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

class Solution{
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() < 2) return nums.size();
        
        static const int BEGIN = 0;
        static const int UP = 1;
        static const int DOWN = 2;

        int STATE = BEGIN;
        int max_len = 1;

        for (int i = 1; i < nums.size(); i++){
            switch (STATE)
            {
            case BEGIN:
                if (nums[i-1] < nums[i]){
                    STATE = UP;
                    max_len++;
                }
                else if (nums[i-1] > nums[i]){
                    STATE = DOWN;
                    max_len++;
                }
                break;
            case UP:
                if(nums[i-1] > nums[i]){
                    STATE = DOWN;
                    max_len++;
                }
                break;
            case DOWN:
                if(nums[i-1] < nums[i]){
                    STATE = UP;
                    max_len++;
                }
                break;
            }
        }

        return max_len;
    }
};