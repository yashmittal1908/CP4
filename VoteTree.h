#include <stdio.h>
#include <iostream>
#include <vector>
#include "VoteNode.h"

using namespace std;

class VoteTree{
    private:
        // VoteNode * root = nullptr;
        vector<VoteNode*> H;

    public:
       void addVoteNode(string v);
       void printTree();
       void reheapify(int index);
       //bool UniqueUserSearch(string ui);
       int search(string use);
       void updateVotes(int numvotes, string ui);
       void print();
    //    void heapSort(vector<VoteNode*> H, int n);
    //    void heapify(vector<VoteNode*> H, int n, int i);
};  