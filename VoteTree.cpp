#include <stdio.h>
#include <iostream>
#include "VoteTree.h"


void VoteTree::addVoteNode(string v){
    if(H.size() == 0){
        cout<< H.size()<<endl;
        VoteNode* rootNode = new VoteNode(v);
        H.push_back(rootNode);
        cout << H.at(0)->id << endl;
    }
    else{
            H.push_back(new VoteNode(v));
            cout << H.back()->id << endl;
        }    
    }

// void VoteTree::printTree(){
//     cout<<"Print function from Vote Tree"<<endl;
//     cout << "userId = " << root->id <<endl; 
//     cout << "vote count = " << root->votes << endl;
//     if(root->left != nullptr){
//         cout << "lc --> "; 
//         cout << "Votes:" << root->left->votes << " ID:" << root->left->id << endl;
//         if(root->left->left != nullptr){
//             cout << "llc --> "; 
//             cout << "Votes:" << root->left->left->votes << " ID:" << root->left->left->id << endl;
//         }
//         if(root->left->right != nullptr){
//             cout << "lrc --> ";
//             cout<< "Votes:" << root->left->right->votes << "ID:" <<root->left->right->id<< endl;
//         }
//     }
//     if(root->right != nullptr){
//         cout << "rc --> "; 
//         cout << "Votes:" << root->right->votes << " ID:" << root->right->id << endl;
//         if(root->right->left != nullptr){
//             cout << "rlc --> "; 
//             cout << "Votes:" << root->right->left->votes << " ID:" << root->right->left->id << endl;
//         }
//         if(root->right->right != nullptr){
//             cout << "rrc --> "; 
//             cout << "Votes:" << root->right->right->votes << " ID:" << root->right->right->id << endl;
//         }
//     }
// }

void VoteTree::updateVotes(int numvotes, string ui){
    if (H.size() == 0){
        cout << "No tree" << endl;
    }
    else if(H.at(0)->id == ui){
        cout << "root" << endl;
        H.at(0)->votes += numvotes;
        cout << H.at(0)->id << " vote count is " << H.at(0)->votes << endl;
    }
    else{
        int s = search(ui);
        if( s != -1){
            cout << "Before:" << H.at(s)->votes << endl;
            H.at(s)-> votes += numvotes;
            cout << "After:" << H.at(s)->votes << endl;
            reheapify(s);
            cout<<" Reheapified" << endl;
        }

    
    }
}

int VoteTree::search(string use){
    for(int i = 0; i < H.size(); i++){
        if(H.at(i)->id == use){
            return i;
        }
    }
    return -1;
}

void VoteTree::reheapify(int index){
    if(H.at(0)->id == H.at(index)->id){
        cout<< "nothing happens on reheapify" << endl;
    }
    else{ 
        if(H.at(index)->votes > H.at((index-1)/2)->votes){
        //swap
            VoteNode* temp = new VoteNode;
            temp = H.at((index-1)/2);
            H.at((index-1)/2) = H.at(index);
            H.at(index) =  temp;
            delete temp;
        }
    }
    
}

void VoteTree::print(){
    for(int i=0;i<H.size();i++){
        cout<<H.at(i)->votes<< " ";
    }
}
