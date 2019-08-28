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

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        int change_len = n - m + 1;
        ListNode* prehead = NULL;
        ListNode* result = head;

        while(head && --m){
            prehead = head;
            head = head->next;
        }

        ListNode *modify_list_tail = head;
        ListNode *new_head = NULL;

        while(head && change_len){
            ListNode *next = head->next;
            head->next = new_head;
            new_head = head;
            head = next;
            change_len--;
        }

        modify_list_tail->next = head;

        if(prehead)
            prehead->next = new_head;
        else
            result = new_head;

        return result;
    }
};