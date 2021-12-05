#include <stdio.h>
#include <iostream>
#include "VoteTree.h"

void VoteTree::addVoteNode(string v){
    //User temp = User(userid);
    //cout << "made it" << endl;
    if(this->root == nullptr){
        
        //cout << "made it" << endl;
        root = new VoteNode; //ask if this needs to be deleted later
        cout << "Before VOTE" << root->id << endl;
        root->id = v;
        cout <<"After VOTE: " << root->id << endl;

    }
    else{/*
        if(v < root->id){
            if(root->left == nullptr){
                root->left = new VoteNode(v); //delete ?this too
            }
            else{
                addToSubTree(root->left, v);
            }
        }
        else{
            if(root->right == nullptr){
                root->right = new VoteNode(v); //delete ?this too
            }
            else{
                addToSubTree(root->right, v);
            }
        } //comp strimngs as long as cases same
        */
    }
}