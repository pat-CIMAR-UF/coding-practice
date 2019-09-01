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
    int longestPalindrome(string s) {
        int char_map[128] = {0};
        int max_length = 0;
        int flag = 0;
        for (int i = 0; i < s.length(); i++){
            char_map[s[i]]++;
        }

        for (int i = 0; i < 128; i++){
            if (char_map[i] % 2 == 0){
                max_length += char_map[i];
            }
            else{
                max_length += char_map[i] - 1;
                flag = 1;
            }
        }

        return max_length + flag;
    }
};