#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
	int numIslands(vector<vector<char>>& grid) {

	}

	void DFS(vector<vector<int>>& mark, vector<vector<char>>& grid, int x, int y) {
		mark[x][y] = 1;
		static const int dx[] = { -1, 1, 0, 0 };
		static const int dy[] = { 0, 0, -1, 1 };
		for (int i = 0; i < 4; i++) {
			int newx = dx[i] + x;
			int newy = dy[i] + y;

			if (newx < 0 || newx >= mark.size() || newy < 0 || newy >= mark.size())
				continue;
			if (mark[newx][newy] == 0 && grid[newx][newy] == '1') {
				DFS(mark, grid, newx, newy);
			}
		}
	}
};
