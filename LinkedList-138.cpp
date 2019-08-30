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

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        map<Node *, int> node_map;
        vector<Node*> node_vec;
        Node *ptr = head;
        int i = 0;
        while(ptr){
            node_vec.push_back(new Node(ptr->val, ptr->next, ptr->random));
            node_map[ptr] = i;
            ptr = ptr->next;
            i++;
        }

        node_vec.push_back(0);

        ptr = head;
        i = 0;

        while(ptr){
            node_vec[i]->next = node_vec[i+1];
            if (ptr->random){
                int id = node_map[ptr->random];
                node_vec[i]->random = node_vec[id];
            }
            ptr = ptr->next;
            i++;
        }

        return node_vec[0];
    }
};
