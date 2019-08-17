#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

//EP8: first section
class Solution {
public:
	int numIslands(vector<vector<char>>& grid) {
		int island_num = 0;
		vector<vector<int>> mark;
		for (int i = 0; i < grid.size(); i++){
			mark.push_back(vector<int>());
			for (int j = 0; j < grid[0].size(); j++){
				mark[i].push_back(0);
			}
		}

		for (int i = 0; i<grid.size(); i++){
			for (int j = 0; j< grid[0].size(); j++){
				if (grid[i][j] == '1' && mark[i][j] == 0){
					DFS(mark, grid, i, j); //or BFS
					island_num++;
				}
			}
		}

		return island_num;
	}

	void DFS(vector<vector<int>>& mark, vector<vector<char>>& grid, int x, int y) {
		mark[x][y] = 1;
		static const int dx[] = { -1, 1, 0, 0 };
		static const int dy[] = { 0, 0, -1, 1 };
		for (int i = 0; i < 4; i++) {
			int newx = dx[i] + x;
			int newy = dy[i] + y;

			if (newx < 0 || newx >= mark.size() || newy < 0 || newy >= mark[newx].size())
				continue;
			if (mark[newx][newy] == 0 && grid[newx][newy] == '1') {
				DFS(mark, grid, newx, newy);
			}
		}
	}

	void BFS(vector<vector<int>>& mark, vector<vector<char>>& grid, int x, int y) {
		static const int dx[] = { -1, 1, 0, 0 };
		static const int dy[] = { 0, 0, -1, 1 };

		queue<pair<int, int>> Q;
		Q.push(make_pair(x, y));
		mark[x][y] = 1;
		while (!Q.empty()) {
			x = Q.front().first;
			y = Q.front().second;
			Q.pop();

			for (int i = 0; i < 4; i++) {
				int newx = dx[i] + x;
				int newy = dy[i] + y;

				if (newx < 0 || newx > mark.size() || newy < 0 || newy > mark.size())
					continue;
				if (mark[newx][newy] == 0 && grid[newx][newy] == '1') {
					Q.push(make_pair(newx, newy));
					mark[newx][newy] = 1;
				}
			}
		}
	}
};