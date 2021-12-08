#include <stdio.h>
#include <iostream>
#include "UserTree.h"

void UserTree::addUserNode(string u){
    //User temp = User(userid);
    //cout << "made it" << endl;
    if(this->root == nullptr){
        
        //cout << "made it" << endl;
        root = new User; //ask if this needs to be deleted later
        // cout << "Before" << root->user_id << endl;
        root->user_id = u;
        // cout <<"After: " << root->user_id << endl;

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
    }
}

void UserTree::printTree(User * use){
    cout << "made it" << endl;
    cout << "ID: " << use->user_id << "Votes: " << use->vote_count;
    if(use->left_user != nullptr){
        printTree(use->left_user);
    }
    if(use->right_user != nullptr){
        printTree(use->right_user);
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

bool UserTree::UniqueUserSearch(string ui){
    //false= not in tree, true = in tree
    if (root == nullptr){
        cout << "From UniqueUserSearch: No tree made yet!" << endl;
        return false;
    }
    if(root->user_id == ui){
        cout << "From UniqueUserSearch: root is key" << endl;
        return true;
    }
    // Key is greater than r>left_user, ui);
    if(root->user_id < ui){
        if(root->right_user == nullptr){
            return false;
        }
        else{
            cout << "calling right sub" << endl;
            return SearchSubTree(root->right_user, ui);
        }
    }
    // Key is smaller than root's key
    else{
        if(root->left_user == nullptr){
            return false;
        }
        else{
            cout << "calling left sub" << endl;
            return SearchSubTree(root->left_user, ui);
        }
    }
}

bool UserTree::SearchSubTree(User *use, string ui){//use is current node, ui is key
    cout << "current node:" << use->user_id << endl;
    cout << "key:" << ui << endl;
    if(use->user_id == ui){
        cout << ui << "= " << use->user_id << endl;
        return true;
    }
    //cehck current node to see if key is a match
    else if(ui < use->user_id){
        cout << ui << "< " << use->user_id << endl;
        if(use->left_user == nullptr){
            return false;
        }
        else{
            return SearchSubTree(use->left_user, ui);
        }
    }
    else{//greater than curent node value
        cout << ui << "> " << use->user_id << endl;
        if(use->right_user == nullptr){
            return false;
        }
        else{
            return SearchSubTree(use->right_user, ui);
        }
    }
}

void UserTree::updateUserVotes(int numvotes, string ui){
    printTree(root);
    if (root == nullptr){
        cout << "No tree" << endl;
    }
    if(root->user_id == ui){
        // cout << "root" << endl;
        root->vote_count += numvotes;
        // cout << root->user_id << " vote count is " << root->vote_count << endl;
    }
    // Key is greater than, ui);
    else if(root->user_id < ui){
        if(root->right_user == nullptr){
       
        }
        else{
            cout << "calling right sub" << endl;
            updateSubTreeVotes(root->right_user, ui, numvotes);
        }
    }
    // Key is smaller than root's key
    else{
        if(root->left_user == nullptr){
           
        }
        else{
            cout << "calling left sub" << endl;
            updateSubTreeVotes(root->left_user, ui, numvotes);
        }
    }
    printTree(root);
}

void UserTree::updateSubTreeVotes(User * use, string ui, int numvotes){
    if(use->user_id == ui){
        use->vote_count += numvotes;
    }
    else if(ui > use->user_id){
        updateSubTreeVotes(use->right_user, ui, numvotes);
    }
    else{
        updateSubTreeVotes(use->left_user, ui, numvotes);
    }
}