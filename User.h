#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

class User{
    public:
        void update_votes(int num_votes){
            vote_count += num_votes;
        }

    private:
        string user_id;
        int  vote_count = 0;

        User * left_user; //left child
        User * right_user; //right child
        
};