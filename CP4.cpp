#include <stdio.h>
#include <string.h>
#include <iostream>
#include <sstream>
#include "UserTree.h"

using namespace std;

int main(int argc, char *argv[]){
    stringstream convert(argv[0]);
    int flight_cost = 0;
    convert >> flight_cost;
    string choice;
    string action;
    UserTree T;

    string parse_action(string a);
    string parse_parameter(string p,string a); //p is for parameter, a is the action

    //menu
    cout << "What would you like to do?" << endl;
    cout << "1. Register <userid>" << endl;

    getline(cin, choice);

    action = parse_action(choice); //will retrieve action user wants to perform
    if(action == "Register" || "register"){
        string userid = parse_parameter(choice, action);
        cout << "user Id = " << userid << endl;
        // call a fucntion to add to the tree

        // search before adding

            T.addUserNode(userid);
            T.printTree();
    }

}