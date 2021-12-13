#ifndef __USER_H_
#define __USER_H_

#include <stdio.h>
#include <string.h>
#include <iostream>
#include "VoteNode.h"

using namespace std;

class User{
    public:
        void update_votes(int num_votes){
            vote_count += num_votes;
        }

        User(){};
        User(string ui){
            user_id = ui;
        }
        User(string ui,int i,int index){
            user_id = ui;
            vote_count = i;
            indexVal = index;
        }
        User(string ui,User* vote){
            user_id = ui;
            votepointer = vote;
        }
        User(const User &u){
            user_id = u.user_id;
            vote_count = u.vote_count;
            left_user = new User;
            right_user = new User;
            *left_user = *(u.left_user);
            *right_user = *(u.right_user);
        }
        
    // private:
        string user_id = "initial value";
        int vote_count = 0;
        int indexVal = -1;

        User * left_user = nullptr; //left child
        User * right_user = nullptr; //right child

        User* votepointer = nullptr;

    friend class UserTree;   
};

#endif