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
    void flatten(TreeNode* root) {
        vector<TreeNode* > node_vec;
        preorder(root, node_vec);

        for(int i = 1; i < node_vec.size(); i++){
            node_vec[i-1]->left = NULL;
            node_vec[i-1]->right = node_vec[i];
        }
    }

private:
    void preorder(TreeNode *node, vector<TreeNode* > &node_vec){
        if (!node) return;

        node_vec.push_back(node);
        preorder(node->left, node_vec);
        preorder(node->right, node_vec);
    }
};