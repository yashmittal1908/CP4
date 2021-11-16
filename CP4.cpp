#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]){
    int flight_cost = stoi(argv[0]);
    string choice;
    string action;

    string parse_action(string a);
    string parse_parameter(string p, string a); //p is for parameter, a is the action

    //menu
    cout << "What would you like to do?" << endl;
    cout << "1. Register <userid>" << endl;

    getline(cin, choice);

    action = parse_action(choice); //will retrieve action user wants to perform
    if(action == "Register" || "register"){
        //
    }

}