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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
  

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> view;
        queue<pair<TreeNode*, int> > Q;

        if(root){
            Q.push(make_pair(root, 0));
        }

        while(!Q.empty()){
            TreeNode* node = Q.front().first;
            int depth = Q.front().second;
            Q.pop();

            if(view.size() == depth){
                view.push_back(node->val);
            }
            else{
                view[depth] = node->val;
            }

            if(node->left){
                Q.push(make_pair(node->left, depth+1));
            }
            if(node->right){
                Q.push(make_pair(node->right, depth+1));
            }
            
        }
        return view;
    }
};