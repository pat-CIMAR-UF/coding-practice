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

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };

bool cmp(const ListNode *a, const ListNode *b){
        return a->val < b->val;
}

class Solution {
public:
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<ListNode *> node_vec;
        for(int i = 0; i < lists.size(); i++){
            ListNode *head = lists[i];
            while(head){
                node_vec.push_back(head);
                head = head->next;
            }
        }

        if (node_vec.size() == 0) return NULL;

        sort(node_vec.begin(), node_vec.end(), cmp);

        for (int i = 1; i < node_vec.size(); i++){
            node_vec[i-1]->next = node_vec[i];
        }

        node_vec[node_vec.size() - 1]->next = NULL;

        return node_vec[0];
    }

};