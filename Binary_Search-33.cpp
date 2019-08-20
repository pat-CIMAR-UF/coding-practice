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

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int begin = 0;
        int end = nums.size() - 1;
        while(begin <= end){
            int mid = (begin + end) / 2;
            // case 1:
            if (target == nums[mid]) return mid;
            // case 2:
            else if (target < nums[mid] ){
                if (nums[begin] < nums[mid]){
                    if (target >= nums[begin]){
                        end = mid - 1;
                    }
                    else{
                        begin = mid + 1;
                    }
                }

                else if (nums[begin] > nums[mid]){
                    end = mid - 1;
                }

                else if (nums[begin] == nums[mid]){
                    begin = mid + 1;
                }
                
            }
            // case 3:
            else if (target > nums[mid]){
                if (nums[begin] < nums[mid]){
                    begin = mid + 1;
                }

                else if (nums[begin] > nums[mid]){
                    if (target >= nums[begin]){
                        end = mid - 1;
                    }
                    else{
                        begin = mid + 1;
                    }
                }

                else if (nums[begin] == nums[mid]){
                    begin = mid + 1;
                }
            }
        }

        return -1;
    }
};