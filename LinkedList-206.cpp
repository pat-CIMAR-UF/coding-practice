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
	ListNode* reverseList(ListNode* head) {
		ListNode* new_head = NULL;
		while (head) {
			ListNode* next = head->next;
			head->next = new_head;
			new_head = head;
			head = next;
		}

		return new_head;
	}
};