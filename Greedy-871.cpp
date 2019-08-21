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
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        
        for (int i = 0; i < stations.size(); i++){
            stations[i][0] = target - stations[i][0];
        }
    

        priority_queue<int> Q;
        int result = 0; 
        stations.push_back({0, 0});
        
        for(int i = 0; i<stations.size(); i++){
            int dis = target - stations[i][0];
            while(!Q.empty() && startFuel < dis){
                startFuel += Q.top();
                Q.pop();
                result++;
            }

            if (Q.empty() && startFuel < dis){
                return -1;
            }
            
            startFuel = startFuel - dis;
            target = stations[i][0];
            Q.push(stations[i][1]);
        }
        return result;
    }
};