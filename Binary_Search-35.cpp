#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <map>
#include <set>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int index = -1;
        int begin = 0;
        int end = nums.size() - 1;
        while( index == -1 ){
            int mid = (begin + end) / 2;
            
            if (target == nums[mid]){
                index = mid;
            }

            else if (target < nums[mid]){
                if (mid == 0 || target > nums[mid - 1]){
                    index = mid;
                }
                end = mid - 1;
            }

            else if (target > nums[mid]){
                if (mid == nums.size() - 1 || target < nums[mid + 1]){
                    index = mid + 1;
                }
                begin = mid + 1;
            }

        }
        return index;
    }
};
