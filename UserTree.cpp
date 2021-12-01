#include <stdio.h>
#include <iostream>
#include "UserTree.h"

void UserTree::addUserNode(string u){
    //User temp = User(userid);
    //cout << "made it" << endl;
    if(this->root == nullptr){
        
        //cout << "made it" << endl;
        root = new User; //ask if this needs to be deleted later
        cout << "Before" << root->user_id << endl;
        root->user_id = u;
        cout <<"After: " << root->user_id << endl;

    }
    else{
        //less or more alphabetically
        //will users eever be ==
        if(u < root->user_id){
            if(root->left_user == nullptr){
                root->left_user = new User(u); //delete ?this too
            }
            else{
                addToSubTree(root->left_user, u);
            }
        }
        else{
            if(root->right_user == nullptr){
                root->right_user = new User(u); //delete ?this too
            }
            else{
                addToSubTree(root->right_user, u);
            }
        } //comp strimngs as long as cases same
        /*
        char arr1[root->user_id.length()];
        char arr2[userid.length()];
        for(char c: root->userid){
            
        }
        User temp = User(userid);
        */
    }
}

void UserTree::printTree(){
    cout << "userId = " << root->user_id <<endl; 
    cout << "vote count = " << root->vote_count << endl;
    if(root->left_user != nullptr){
        cout << root->left_user->user_id << endl;
        if(root->left_user->left_user != nullptr){
            cout << root->left_user->left_user->user_id << endl;
        }
    }
    
}

void UserTree::addToSubTree(User *use, string u){
    if(u < use->user_id){
        if(use->left_user == nullptr){
            use->left_user = new User(u); //delete ?this too
        }
        else{
            addToSubTree(use->left_user, u);
        }
    }
    else{
        if(use->right_user == nullptr){
            use->right_user = new User(u); //delete ?this too
        }
        else{
            addToSubTree(use->right_user, u);
        }
    }
}
