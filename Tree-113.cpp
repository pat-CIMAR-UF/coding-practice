/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int> > result;
        vector<int> path;

        int path_value = 0;
        preorder(root, path_value, sum, path, result);
        return result;

    }

private:
    void preorder(TreeNode* node, int &path_value, int sum, vector<int> &path, vector<vector<int> > &result){
        if (!node) return;

        path_value += node->val;
        path.push_back(node->val);
        if(!node->left && !node->right && path_value == sum){
            result.push_back(path);
        }
        
        preorder(node->left, path_value, sum, path, result);
        preorder(node->right, path_value, sum, path, result);

        path_value -= node->val;

        path.pop_back();
    }
};