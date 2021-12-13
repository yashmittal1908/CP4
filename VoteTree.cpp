#include <stdio.h>
#include <iostream>
#include "VoteTree.h"

string final = " ";

void updateVotepointer(){

}
void VoteTree::addVoteNode(string v, int i){
    if(H.size() == 0){
        cout<<"Size of VoteTree: " <<H.size()<<endl;
        User* rootNode = new User(v,i,H.size());
        H.push_back(rootNode);
        cout << "Node added to VoteTree with ID: " << H.at(0)->user_id << " index: "<< H.size()-1<< endl;
    }
    else{
            H.push_back(new User(v,i,H.size()));
            cout <<"Node added to VoteTree  else with ID: "<< H.back()->user_id<< " index: "<< H.size()-1<< endl;
        }    
    }

// void VoteTree::printTree(){
//     cout<<"Print function from Vote Tree"<<endl;
//     cout << "userId = " << root->user_id <<endl; 
//     cout << "vote count = " << root->vote_count << endl;
//     if(root->left != nullptr){
//         cout << "lc --> "; 
//         cout << "Votes:" << root->left->vote_count << " ID:" << root->left->user_id << endl;
//         if(root->left->left != nullptr){
//             cout << "llc --> "; 
//             cout << "Votes:" << root->left->left->vote_count << " ID:" << root->left->left->user_id << endl;
//         }
//         if(root->left->right != nullptr){
//             cout << "lrc --> ";
//             cout<< "Votes:" << root->left->right->vote_count << "ID:" <<root->left->right->user_id<< endl;
//         }
//     }
//     if(root->right != nullptr){
//         cout << "rc --> "; 
//         cout << "Votes:" << root->right->vote_count << " ID:" << root->right->user_id << endl;
//         if(root->right->left != nullptr){
//             cout << "rlc --> "; 
//             cout << "Votes:" << root->right->left->vote_count << " ID:" << root->right->left->user_id << endl;
//         }
//         if(root->right->right != nullptr){
//             cout << "rrc --> "; 
//             cout << "Votes:" << root->right->right->vote_count << " ID:" << root->right->right->user_id << endl;
//         }
//     }
// }

void VoteTree::updateVotes(int numvotes, string ui,UserTree T){
    if(numvotes < 1){
        cout << "Thats' an invalid number of votes!" << endl;
    }
    else{
        if (H.size() == 0){
            cout << "Tree doesn't exist, votes can not be added!" << endl;
        }
        else if(H.at(0)->user_id == ui){
            cout << "root" << endl;
            H.at(0)->vote_count += numvotes;
            cout << H.at(0)->user_id << " vote count is " << H.at(0)->vote_count << endl;
        }
        else{
            int s = search(ui,T);
            print();
            cout<< "Search Result: "<<s;
            if( s != -1){
                cout<< endl;
                // cout << "Before Votes:" << H.at(s)->vote_count << endl;
                H.at(s)-> vote_count += numvotes;
                // cout << "After Votes:" << H.at(s)->vote_count << endl;
             
     

                reheapify(s,T);
                if (final == " "){
                    final = H.at(s)->user_id;
                }
                    cout<<"Final:"<<final<<endl;

                if(ui!=final){
                    cout<<"UI from swap: "<<ui<<endl;
                    cout<<"Final from swap: "<<final<<endl;
                    cout<<"B :"<<T.returnSearchedAddress(ui)->votepointer->indexVal<<endl;
                    cout<<"A :"<<T.returnSearchedAddress(final)->votepointer->indexVal<<endl;
                
         
                cout<<"Before"<<endl;
                cout<<"UI:      "<<T.returnSearchedAddress(ui)->votepointer->indexVal<<endl;
                cout<<"Final:    "<<T.returnSearchedAddress(final)->votepointer->indexVal<<endl;

                //to update index value of VoteTree nodes inside VoteTree
                swap(T.returnSearchedAddress(ui)->votepointer->indexVal,T.returnSearchedAddress(final)->votepointer->indexVal);

                // to update votepointer inside UserTree
                    
                    // swap(T.returnSearchedAddress(ui)->votepointer,T.returnSearchedAddress(final)->votepointer);
                 cout<<"After"<<endl;
                cout<<"UI:      "<<T.returnSearchedAddress(ui)->votepointer->indexVal<<endl;
                cout<<"Final:    "<<T.returnSearchedAddress(final)->votepointer->indexVal<<endl;
                final = " ";
                }
            }
        }
    }
}

int VoteTree::search(string use,UserTree T){
    
   
        // User* temp = T.returnSearchedAddress(use);
        // cout<<"address from votepointer from search"<<&(T.returnSearchedAddress(use)->votepointer)<<endl;
        // cout<<"address of a"<<H.at(0)<<endl;
        // cout<<"address of b"<<H.at(1)<<endl;
        // cout<<"H at 0 adress"<<&H[0]<<endl;

        // // int temp = *(T.returnSearchedAddress(use)->votepointer);
        // // User* temp2 = H.at(0);

        int index = T.returnSearchedAddress(use)->votepointer->indexVal;
        cout<<"User Id from search:"<< T.returnSearchedAddress(use)->votepointer->user_id;
        // int temp = (T.returnSearchedAddress(use)->votepointer) - H.data();
      
        return index;
        
  
}



void VoteTree::reheapify(int index,UserTree T){

    if(H.at(0)->user_id == H.at(index)->user_id){
        cout<< "nothing happens on reheapify" << endl;
    }
    else{ 
        if(H.at(index)->vote_count > H.at((index-1)/2)->vote_count){
            final = H.at((index-1)/2)->user_id;

            cout<<"Enter reheapufy loop"<<endl;

            swap( H.at(index), H.at((index-1)/2));
            string node1_id = H.at(index)->user_id;
            string node2_id = H.at((index-1)/2)->user_id;

            // swap(T.returnSearchedAddress(node1_id)->votepointer,T.returnSearchedAddress(node2_id)->votepointer);
            T.inorder(T.root);     
           
        } else{
            final = H.at(index)->user_id;
        }

        cout<<" Reheapified" << endl;
        // cout<<"Final:"<<final<<endl;
        index = (index-1)/2;
        reheapify(index,T);
    }
    
    
}

void VoteTree::print(){
    for(int i=0;i<H.size();i++){
        cout<<"Votes " << H.at(i)->vote_count<< " ID: " << H.at(i)->user_id<<endl;
    }
}


void VoteTree::scoreboard(int k,UserTree T){
    vector<User*> temp;
    if(k>H.size()){
        cout<<"Enter valid k value"<<endl;
    } else {
    cout<<"Scoreboard:"<<endl;
    if(H.size()==0){
        cout<<"No users registered!"<<endl;
    } else if(H.size()==1){
        cout<<H.at(0)->user_id<<" "<<H.at(0)->vote_count<<endl;
    } else {
        for(int i=0;i<k;i++){
            User* temp2 = H.at(0);
    


            cout<<temp2->user_id<<" "<<temp2->vote_count<<endl;
            // cout<<"1"<<endl;
            temp.push_back(H.at(0));
            // cout<<"2"<<endl;
            H.erase(H.begin());
            // cout<<"3"<<endl;
            if(H.size()!=0){
                  heapify(0,T);
            }
          
            // if(H.at(0)>H.at(2)){
            //     heapify(1);
            // } else {
            //     heapify(2);
            // }
        }
    }

    for(int i=0;i<k;i++){
        
        addVoteNode(temp.at(i)->user_id,temp.at(i)->vote_count);
        heapify(0,T);
    }
    }
}


void VoteTree::heapify(int i,UserTree T)
{
    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2
 
    // If left child is larger than root
    if (l < H.size() && H.at(l)->vote_count > H.at(largest)->vote_count)
        largest = l;
 
    // If right child is larger than largest so far
    if (r < H.size() && H.at(r)->vote_count > H.at(largest)->vote_count)
        largest = r;
 
    // If largest is not root


    if (largest != i) {
        //swapd the indexVal, indexVal is the value of the index of VoteTree node stored in BST
        swap(H.at(i)->indexVal,H.at(largest)->indexVal);
        swap(H.at(i), H.at(largest));
        string node1_id = H.at(i)->user_id;
        string node2_id = H.at(largest)->user_id;
        swap(T.returnSearchedAddress(node1_id)->votepointer,T.returnSearchedAddress(node2_id)->votepointer);
 
        // Recursively heapify the affected sub-tree
        heapify(largest, T);
    }
}
 
// Function to delete the root from Heap
string VoteTree::deleteRoot(UserTree T)
{

    string launchUserId = H.at(0)->user_id; 
    swap(H.at(0), H.at(H.size()-1));
    H.resize(H.size()-1);

 
    // heapify the root node
    heapify(0,T);
    

    return launchUserId;
}