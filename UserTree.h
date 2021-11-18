#include <stdio.h>
#include <iostream>
#include "User.h"

class UserTree{
    private:
        User *root = NULL;

    public:
       void addUserNode(string ui);
       void printTree();
};  