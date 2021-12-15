#ifndef __USER_H_
#define __USER_H_

#include <string>

using std::size_t;
using std::string;

struct User {
    friend class UserTree;

    string m_user_id;
    size_t m_heap_index = -1;
    size_t m_vote_count = 0;

    explicit User(const string& user_id): m_user_id(user_id) {
    }
};

#endif