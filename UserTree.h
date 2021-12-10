#include <stdio.h>
#include <iostream>
#include "User.h"

class UserTree{
    private:
        User * root = nullptr;

    public:
       void addUserNode(string ui);
       void printTree(User* use);
       void addToSubTree(User *use, string u);
       bool UniqueUserSearch(string ui);
       bool SearchSubTree(User *use, string ui);
       void updateUserVotes(int numvotes, string ui);
       void updateSubTreeVotes(User * use, string ui, int numvotes);
       void launch(string ui);
       void removeUser(User * use, string ui);

       void inorder(User* root);

       User* returnRoot(){
           return root;
       }

       void initialiseUser(User * init){
           root = init;
       }


       User* deleteNode(User* current, string key);
       User* minValueNode(User* node);
};  
