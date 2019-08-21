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
    bool cmp(const vector<int>& v1, const vector<int>& v2) {
	    return v1[0] < v2[0];
    }
    
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.size() == 0) return 0;
        
        sort(points.begin(), points.end());

        int shoot_num = 1;
        int shoot_begin = points[0][0];
        int shoot_end = points[0][1];

        for (int i = 1; i < points.size(); i++){
            if (shoot_end >= points[i][0]){
                shoot_begin = points[i][0];

                if(shoot_end > points[i][1])
                    shoot_end = points[i][1];
            }
            else{
                shoot_num++;
                shoot_begin = points[i][0];
                shoot_end = points[i][1];
            }
        }

        return shoot_num;
    }
}; 