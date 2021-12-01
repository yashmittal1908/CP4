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
};  
