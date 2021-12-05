#include <stdio.h>
#include <iostream>
#include "User.h"

class VoteNode{
    public:
    
    private:
        int votes = 0;
        string * user_address;
        
    friend class User;
}
