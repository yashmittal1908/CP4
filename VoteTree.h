#include <stdio.h>
#include <iostream>
#include <vector>
#include "User.h"

using namespace std;

class VoteTree{
    private:
        // VoteNode * root = nullptr;
        vector<User*> H;

    public:
       void addVoteNode(string v,int i=0);
       void printTree();
       void reheapify(int index);
       //bool UniqueUserSearch(string ui);
       int search(string use);
       void updateVotes(int numvotes, string ui);
       void print();
       void scoreboard(int k);
    //    void heapSort(vector<VoteNode*> H, int n);
    //    void heapify(vector<VoteNode*> H, int n, int i);

        void heapify(int i);
        string deleteRoot();

        int getSize(){
            return H.size();
        }
};  