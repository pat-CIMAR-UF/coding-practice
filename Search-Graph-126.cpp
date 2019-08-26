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

struct Qitem
{
    string node;
    int parent_pos;
    int step;
    Qitem(string node, int parent_pos, int step):
        node(node), parent_pos(parent_pos), step(step){}
};


class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        map<string, vector<string> > graph;
        construct_graph(beginWord, wordList, graph);

        vector<Qitem> Q;
        vector<int> end_word_pos;
        BFS_graph(beginWord, endWord, graph, Q, end_word_pos);

        vector<vector<string> > result;

        for(int i = 0; i < end_word_pos.size(); i++){
            int pos = end_word_pos[i];
            vector<string> path;
            
            while(pos != -1){
                path.push_back(Q[pos].node);
                pos = Q[pos].parent_pos; 
            }

            result.push_back(vector<string> ());

            for (int j = path.size() -1 ; j >= 0; j--){
                result[i].push_back(path[j]);
            }
        }

        return result;

    }

private:
    void BFS_graph(string &beginWord, string &endWord, map<string, vector<string>> &graph, vector<Qitem> &Q, vector<int> &end_word_pos){
        map<string, int> visit;
        int min_step = 0;
        Q.push_back(Qitem(beginWord, -1, 1));
        visit[beginWord] = 1;
        int front = 0;

        while(front != Q.size()){
            const string &node = Q[front].node;
            int step = Q[front].step;

            if(min_step != 0 && step> min_step)
                break;

            if (node == endWord){
                min_step = step;
                end_word_pos.push_back(front);
            }

            const vector<string> &neighbors = graph[node];
            for (int i = 0; i < neighbors.size(); i++){
                if (visit.find(neighbors[i]) == visit.end() || visit[neighbors[i]] == step + 1){
                    Q.push_back(Qitem(neighbors[i], front, step + 1));
                    visit[neighbors[i]] = step + 1;
                }
            }

            front++;
        }
    }

    void construct_graph(string &beginWord, vector<string> &wordList, map<string, vector<string> > &graph){
        int has_begin_word = 0;
        for (int i = 0; i < wordList.size(); i++){
            if (beginWord == wordList[i])
                has_begin_word = 1;

            graph[wordList[i]] = vector<string> ();
        }

        for (int i = 0; i < wordList.size(); i++){
            for (int j = i + 1; j < wordList.size(); j++){
                if (connect(wordList[i], wordList[j])){
                    graph[wordList[i]].push_back(wordList[j]);
                    graph[wordList[j]].push_back(wordList[i]);
                }
            }

            if (has_begin_word == 0 && connect(beginWord, wordList[i])){
                graph[beginWord].push_back(wordList[i]);
            }
        }
    }

    bool connect(const string & word1, const string & word2){
        int cnt = 0;
        for (int i = 0; i < word1.length(); i++){
            if (word1[i] != word2[i])
                cnt++;
        }

        return cnt == 1;
    }
};