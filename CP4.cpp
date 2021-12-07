#include <stdio.h>
#include <string.h>
#include <iostream>
#include <sstream>
#include "UserTree.h"
#include "VoteTree.h"

using namespace std;

int main(int argc, char *argv[]){
    stringstream convert(argv[0]);
    int flight_cost = 0;
    convert >> flight_cost;
    string choice;
    string action;
    UserTree T;
    VoteTree V;
    

    string parse_action(string a);
    string parse_parameter(string p,string a); //p is for parameter, a is the action
    int parse_num_vote(string p);
    string parse_vote_user(string p);

    //menu
    do{
        cout << "What would you like to do?" << endl;
        cout << "1. Register <userid>" << endl;
        cout << "2. Vote <numofvotes> <userid>" << endl;
    
        getline(cin, choice);
    
        action = parse_action(choice); //will retrieve action user wants to perform
        cout << action << endl;
        if(action == "Register" || action == "register"){
            string userid = parse_parameter(choice, action);
            cout << "user Id = " << userid << endl;
            // search before adding
            bool b = T.UniqueUserSearch(userid);
            cout << "bool: " << b << endl;
            if(T.UniqueUserSearch(userid) == true){
                cout << "This username is already taken! Please try again!" << endl;
            }
            else{
                cout << "new node added" << endl;
                T.addUserNode(userid);
                T.printTree();
                V.addVoteNode(userid);
                // V.printTree();
            }
        }
        else if(action == "Vote" || action == "vote"){
            cout << "calling vote" << endl;
            int numofvotes = parse_num_vote(choice);
            string voteuser = parse_vote_user(choice);
            cout << numofvotes << endl;
            cout << voteuser << endl;
            
            if(T.UniqueUserSearch(voteuser) == true){
                //update usser's vote count
                V.print();
                T.updateUserVotes(numofvotes, voteuser);
                V.updateVotes(numofvotes, voteuser);

                cout << "updated votes" << endl;
                V.print();
            }
            else{
                cout << "This user doesn't exist!" << endl;
            }
        } 
    }while(choice != "Exit");
}
