#include <stdio.h>
#include <iostream>
#include "VoteTree.h"


void VoteTree::addVoteNode(string v){
    if(H.size() == 0){
        cout<<"Size of VoteTree: " <<H.size()<<endl;
        VoteNode* rootNode = new VoteNode(v);
        H.push_back(rootNode);
        cout << "Node added to VoteTree with ID: " << H.at(0)->id << endl;
    }
    else{
            H.push_back(new VoteNode(v));
            cout <<"Node added to VoteTree with ID: "<< H.back()->id << endl;
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
    if(numvotes < 1){
        cout << "Thats' an invalid number of votes!" << endl;
    }
    else{
        if (H.size() == 0){
            cout << "Tree doesn't exist, votes can not be added!" << endl;
        }
        else if(H.at(0)->id == ui){
            cout << "root" << endl;
            H.at(0)->votes += numvotes;
            cout << H.at(0)->id << " vote count is " << H.at(0)->votes << endl;
        }
        else{
            int s = search(ui);
            cout<< "Search Result: "<<s;
            if( s != -1){
                cout<< endl;
                // cout << "Before Votes:" << H.at(s)->votes << endl;
                H.at(s)-> votes += numvotes;
                // cout << "After Votes:" << H.at(s)->votes << endl;
                reheapify(s);
                
            }
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
            // VoteNode* temp = new VoteNode;
            // temp = H.at((index-1)/2);
            // H.at((index-1)/2) = H.at(index);
            // H.at(index) =  temp;
            // delete temp;

            swap( H.at(index), H.at((index-1)/2));
        }

        cout<<" Reheapified" << endl;
        index = (index-1)/2;
        reheapify(index);
    }
    
    
}

void VoteTree::print(){
    for(int i=0;i<H.size();i++){
        cout<<"Votes " << H.at(i)->votes<< " ID: " << H.at(i)->id<<endl;
    }
}


// void VoteTree::heapSort(vector<VoteNode*> H, int n)
// {
//     // Build heap (rearrange array)
//     for (int i = n / 2 - 1; i >= 0; i--)
//         heapify(H, n, i);
 
//     // One by one extract an element from heap
//     for (int i = n - 1; i > 0; i--) {
//         // Move current root to end
//         // swap(H.at(0), H.at(i));
//         cout<<"swapping 1"<<endl;
//         VoteNode* temp = new VoteNode;
//         temp = H.at(i);
//         H.at(i) = H.at(0);
//         H.at(0) =  temp;
//         // delete temp;
 
//         // call max heapify on the reduced heap
//         heapify(H, i, 0);
//     }
//     cout<<" Reheapified" << endl;
// }

// void VoteTree::heapify(vector<VoteNode*> H, int n, int i)
// {
//     int largest = i; // Initialize largest as root
//     int l = 2 * i + 1; // left = 2*i + 1
//     int r = 2 * i + 2; // right = 2*i + 2
 
//     // If left child is larger than root
//     if (l < n && H.at(l)->votes > H.at(largest)->votes)
//         largest = l;
 
//     // If right child is larger than largest so far
//     if (r < n && H.at(r)->votes > H.at(largest)->votes)
//         largest = r;
 
//     // If largest is not root
//     if (largest != i) {
//         // swap(H.at(i), H.at(largest));
//         cout<<"swapping 2"<<endl;
//         VoteNode* temp = new VoteNode;
//         temp = H.at(largest);
//         H.at(largest) = H.at(i);
//         H.at(i) =  temp;
//         // delete temp;
 
//         // Recursively heapify the affected sub-tree
//         heapify(H, n, largest);
//     }
// }

void VoteTree::scoreboard(int k){
    for(int i=0;i<k;i++){

    }
}


void VoteTree::heapify(int i)
{
    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2
 
    // If left child is larger than root
    if (l < H.size() && H.at(l)->votes > H.at(largest)->votes)
        largest = l;
 
    // If right child is larger than largest so far
    if (r < H.size() && H.at(r)->votes > H.at(largest)->votes)
        largest = r;
 
    // If largest is not root
    if (largest != i) {
        swap(H.at(i), H.at(largest));
 
        // Recursively heapify the affected sub-tree
        heapify(largest);
    }
}
 
// Function to delete the root from Heap
string VoteTree::deleteRoot()
{
    // // Get the last element
    // VoteNode* lastElement = H.at(H.size()-1);
 
    // // Replace root with last element
    // H.at(0) = lastElement;

    string launchUserId = H.at(0)->id;
    
    swap(H.at(0), H.at(H.size()-1));
    // Decrease size of heap by 1
    H.resize(H.size()-1);

 
    // heapify the root node
    heapify(0);

    return launchUserId;
}