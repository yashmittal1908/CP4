#include <stdio.h>
#include <iostream>
#include <vector>
#include "UserTree.h"

using namespace std;



class VoteTree{
    private:
        // VoteNode * root = nullptr;
        vector<User*> H;

    public:
       void addVoteNode(string v,int i=0);
       void printTree();
       void reheapify(int index,UserTree T);
       //bool UniqueUserSearch(string ui);
       int search(string use,UserTree T);

    void updateVotepointer();
       void updateVotes(int numvotes, string ui,UserTree T);
       void print();
       void scoreboard(int k,UserTree T);
    //    void heapSort(vector<VoteNode*> H, int n);
    //    void heapify(vector<VoteNode*> H, int n, int i);

        void heapify(int i,UserTree T);
        string deleteRoot(UserTree T);

        int getSize(){
            return H.size();
        }
        User* returnAddress(){
            return H.at(H.size()-1);
        }

        friend class UserTree;
};  