#include <stdio.h>
#include <iostream>
#include "User.h"

class UserTree{
    private:
        User *root = nullptr;

    public:
       void addUserNode(string ui);
       void printTree();
       void addToSubTree(User *use, string u);
       bool UniqueUserSearch(string ui);
       bool SearchSubTree(User *use, string ui);
       void updateUserVotes(int numvotes, string ui);
};  
