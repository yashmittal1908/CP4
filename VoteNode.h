#ifndef __VOTENODE_H_
#define __VOTENODE_H_
#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

class User;

class VoteNode{
    public:
        VoteNode(){};
        VoteNode(string uid){
            id = uid;
        }    
        VoteNode(const VoteNode &vn){
            id = vn.id;
            votes = vn.votes;
        }

        
    private:
        string id = "initial";
        int votes = 0;
    

        
    friend class VoteTree;
    friend class User;

};

#endif
