#include <stdio.h>
#include <iostream>
#include "VoteNode.h"

using namespace std;

class VoteTree{
    private:
        VoteNode * root = nullptr;

    public:
       void addVoteNode(string v);
       void printTree();
       //void addToSubTree(User *use, string u);
       //bool UniqueUserSearch(string ui);
       //bool SearchSubTree(User *use, string ui);
       //void updateVotes(int numvotes, string ui);
};  