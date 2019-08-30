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

class Solution2 {
public:
    ListNode *detectCycle(ListNode *head) {
        set<ListNode* > node_set;
        while(head){
            if (node_set.find(head) != node_set.end())
                return head;
            set.insert(head);
            head = head->next;
        }

        return NULL;
    }
};

class Solution{
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;
        ListNode *meet = NULL;
        while(fast){
            slow = slow->next;
            fast = fast->next;
            if(!fast) return NULL;

            fast = fast->next;

            if (fast == slow){
                meet = fast;
                break;
            }
        }

        if (meet == NULL) return NULL;

        while(head && meet){
            if (head == meet)
                return head;
            
            head = head->next;
            meet = meet->next;
        }

        return NULL;
    }
};