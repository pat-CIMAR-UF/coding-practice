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
    bool wordPattern(string pattern, string str) {
        map<string, char> word_map;
        char used[128] = {0};
        string word;
        int pos = 0;
        str.push_back(' ');

        for (int i = 0; i < str.length(); i++){
            if(str[i] == ' '){
                if (pos == pattern.length()){
                    return false;
                }

                if(word_map.find(word) == word_map.end()){
                    if (used[pattern[pos]]){
                        return false;
                    }

                    word_map[word] = pattern[pos];
                    used[pattern[pos]] = 1;
                }
                else{
                    if (word_map[word] != pattern[pos]){
                        return false;
                    }
                }

                word = "";
                pos++;
            }
            else{
                word += str[i];
            }
        }

        if (pos!= pattern.length()){
            return false;
        }

        return true;
    }
};