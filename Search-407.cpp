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

    struct Qitem{
        int x;
        int y;
        int h;
        Qitem(int x, int y, int h):
            x(x), y(y), h(h){}
    };

    struct cmp{
        bool operator()(const Qitem &a, const Qitem &b){
            return a.h > b.h;
        }
    };

public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        priority_queue<Qitem, vector<Qitem>, cmp> Q;

        if(heightMap.size() < 3 || heightMap[0].size() < 3)
            return 0;

        int row = heightMap.size();
        int col = heightMap[0].size();

        vector<vector<int> > mark;
        for (int i = 0; i < row; i++){
            mark.push_back(vector<int> ());
            for (int j = 0; j < col; j++){
                mark[i].push_back(0);
            }
        }

        for(int i = 0; i < row; i++){
            Q.push(Qitem(i, 0, heightMap[i][0]));
            mark[i][0] = 1;
            Q.push(Qitem(i, col - 1, heightMap[i][col-1]));
            mark[i][col - 1] = 1;
        }

        for(int i = 1; i < col - 1; i++){
            Q.push(Qitem(0, i, heightMap[0][i]));
            mark[0][i] = 1;
            Q.push(Qitem(row-1, i, heightMap[row-1][i]));
            mark[row-1][i] = 1;
        }

        static const int dx[] = {-1, 1, 0, 0};
        static const int dy[] = {0, 0, -1, 1};

        int result = 0;
        while(!Q.empty()){
            int x = Q.top().x;
            int y = Q.top().y;
            int h = Q.top().h;
            Q.pop();

            for (int i = 0; i < 4; i++){
                int newx = x + dx[i];
                int newy = y + dy[i];

                if(newx < 0 || newx>= row || newy < 0 || newy >= col || mark[newx][newy])
                    continue;
                
                if(h>heightMap[newx][newy]){
                    result += h - heightMap[newx][newy];
                    heightMap[newx][newy] = h;
                }

                Q.push(Qitem(newx, newy, heightMap[newx][newy]));

                mark[newx][newy] = 1;
            }
        }

        return result;
    }
};