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
    }
}