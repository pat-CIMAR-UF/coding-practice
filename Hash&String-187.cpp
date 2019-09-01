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
    vector<string> findRepeatedDnaSequences(string s) {
        map<string, int> word_map;
        vector<string> result;
        for (int i = 0; i < s.length(); i++){
            string word = s.substr(i, 10);
            if (word_map.find(word) != word_map.end()){
                word_map[word]++;
            }
            else{
                word_map[word] = 1;
            }
        }

        map<string, int>::iterator it;
        for(it = word_map.begin(); it!= word_map.end(); it++){
            if(it->second > 1){
                result.push_back(it->first);
            }
        }

        return result;
    }
};