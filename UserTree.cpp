#include <stdio.h>
#include <iostream>
#include "UserTree.h"

void UserTree::addUserNode(string userid){
    User temp = User(userid);
    if(root == NULL){
        
        // cout << "Before" << root->user_id << endl;
        root = &temp;
        cout <<"After: " << root->user_id << endl;

    } else {
        // 
    }
}

void UserTree::printTree(){
    cout<<"userId = "<< root->user_id <<endl; 
    cout << "vote count = " << root->vote_count << endl;
}