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
    string removeKdigits(string num, int k) {
        vector<int> s;
        string result = "";

        for(int i = 0; i<num.length(); i++){
            int number = num[i] - '0';
            while(s.size() != 0 && s[s.size() - 1] > number && k > 0){
                s.pop_back();
                k--;
            }
            if (number != 0 || s.size() != 0){
                s.push_back(number);
            }
        }

        while(s.size() != 0 && k > 0){
            s.pop_back();
            k--;
        }

        for (int i = 0; i < s.size(); i++){
            result.append(1, s[i] + '0');
        }

        if (result == "")
            return "0";

        return result;
    }
};