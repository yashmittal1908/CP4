#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

string parse_action(string a){
    string action = "";

    for(char c: a){
        if(c == " "){ //change to all whitespace eventually
            break;
        }
        action += c;
    }

    return action;

}

string parse_parameter(string p, string a){ //for singular parameters
    string param = "";
    int counter = 0; //look for more efficient method

    if(a == "register" || a == "Register"){ // 8 letter long, white space 9th character
        for(char c: p){
            if(counter > 9){
                
                param += c;
            }
            counter++;
        }
    } else if(a == "scoreboard" || a == "Scoreboard"){
        for(char c: p){
            if(counter > 11){
                param += c;
            }
            counter++;
        }
    }

    return param;
}

int numCounter = 0;
int parse_num_vote(string p){ //param inckudes num votes and user id
    string ret = "";
    for(char c: p){
        if(numCounter > 5){
            if(isdigit(c) == true){
                ret += c;
            }
            if(c == " "){ //should break at first whitespace encountered after vote, which seperates num of votes and user id
                break;
            }
        }

        numCounter++;
    }
    int r = 0;
    r = stoi(ret);

    return r;

}

string parse_vote_user(string p){
    int counter = 0;
    string ret = "";

    for(char c: p){
        if(counter > numCounter){
            ret += c;
        }
    }

    return ret;
}