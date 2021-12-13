#include <stdio.h>
#include <string.h>
#include <iostream>
#include <sstream>
#include "VoteTree.h"

using namespace std;

int main(int argc, char *argv[]){
    int flight_cost = atoi(argv[1]);
    string choice;
    string action;
    UserTree T;
    VoteTree V;
    int profit = 0;
    int moneyPool = 0;
    

    string parse_action(string a);
    string parse_parameter(string p,string a); //p is for parameter, a is the action
    int parse_num_vote(string p);
    string parse_vote_user(string p);

    //menu
    do{
        cout<<endl;
        cout << "What would you like to do?" << endl;
        cout << "1. Register <userid>" << endl;
        cout << "2. Vote <numofvotes> <userid>" << endl;
        cout << "3. Scoreboard <k>" << endl;
        cout<<endl;
    
        getline(cin, choice);
    
        action = parse_action(choice); //will retrieve action user wants to perform
        // cout << action << endl;
        if(action == "Register" || action == "register"){
            string userid = parse_parameter(choice, action);
            // cout << "user Id = " << userid << endl;
            // search before adding
            // bool b = T.UniqueUserSearch(userid);
            // cout << "bool: " << b << endl;
            if(T.UniqueUserSearch(userid) == true){
                cout << "This username is already taken! Please try again!" << endl;
            }
            else{
                cout << "New Node Added!" << endl;
                V.addVoteNode(userid,0);
               
                T.addUserNode(userid,V.returnAddress());
                T.inorder(T.returnRoot());
                
                // V.printTree();
            }
        }
        else if(action == "Vote" || action == "vote"){
            // cout << "calling vote" << endl;
            int numofvotes = parse_num_vote(choice);
            string voteuser = parse_vote_user(choice);
            // cout << numofvotes << endl;
            // cout << voteuser << endl;
            
            if(T.UniqueUserSearch(voteuser) == true){
                //update user's vote count
                cout<< "Before Votes Updated "<<endl; 
                
                cout<<"Before:"<<endl;
                T.inorder(T.returnRoot());
                cout<<endl;
                V.updateVotes(numofvotes, voteuser,T);
                T.updateUserVotes(numofvotes, voteuser);
                cout<<"After:"<<endl;
                cout<<endl;
                T.inorder(T.returnRoot());
                V.print();
                if(numofvotes % 2 == 1){
                    moneyPool += numofvotes/2;
                    profit += numofvotes/2 + 1;
                    cout<<"MoneyPool = "<<moneyPool;
                }
                else {
                    moneyPool += numofvotes/2;
                    profit += numofvotes/2;
                    cout<<"MoneyPool = "<<moneyPool;
                }
                while(moneyPool>=flight_cost && V.getSize()>0){
                    cout<<"Delete is called"<<endl;
                    // get user_id from VoteTree
                    string launchUserID = V.deleteRoot(T);
                    cout<<"Launch User Id: "<<launchUserID<<endl;
                    User* temp = new User;
                    temp = T.deleteNode(T.returnRoot(),launchUserID);
                   
                    // T.inorder(T.returnRoot());
                    T.initialiseUser(temp);
                    cout<<"From VoteTree:"<<endl;
                    V.print();
                    cout<<endl;
                    cout<<"From UserTree:"<<endl;
                    T.inorder(T.returnRoot());
                    cout<<endl;

                    moneyPool -= flight_cost;
                }

                // cout << "updated votes" << endl;
                cout<< "After Votes Updated "<<endl;
            }
            else{
                cout << "This user doesn't exist!" << endl;
            }
        } 
        else if(action == "Scoreboard" || action == "scoreboard"){
            int k = stoi(parse_parameter(choice,action));
            if(k==0){
                cout<<"No Tree Exists Yet"<<endl;
            } if (k<1){
                cout<<"Top of negative numver not possible!"<<endl;
            } else {
                V.scoreboard(k,T);
        
            }
            // User* temp = new User;
            // temp = T.deleteNode(T.returnRoot(),"l");
            // T.inorder(T.returnRoot());
        
            // delete temp;
          
        }
    }while(choice != "Exit");
}
