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

using namespace std;

bool cmp(const vector<int>& v1, const vector<int>& v2) {
	return v1[0] < v2[0];
}

int main() {
	vector<vector<int> > p{ {3,4},{1,2},{7,9} };

	sort(p.begin(), p.end(), cmp);

	// Displaying the 2D vector after sorting 
	cout << "The Matrix after sorting 1st row is:\n";
	for (int i = 0; i < p.size(); i++)
	{
		for (int j = 0; j < p[0].size(); j++)
			cout << p[i][j] << " ";
		cout << endl;
	}

	return 0;
}