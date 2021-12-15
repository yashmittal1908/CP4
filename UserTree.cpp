#include <string>
#include <iostream>
#include "UserTree.h"

using std::string;

User* UserTree::insert(User* user) {
    return insert(user, m_root);
}

User* UserTree::insert(User* user, UserTree::UserNode*& subtree) {
    if (!subtree) return (subtree = new UserNode{user})->m_user;
    else if (user->m_user_id > subtree->m_user->m_user_id)
        return insert(user, subtree->m_right);
    else if (user->m_user_id < subtree->m_user->m_user_id)
        return insert(user, subtree->m_left);
    else {
        std::cerr << "User already registered" << std::endl;
        delete user; // this one is bad, give the one that already existed
        return subtree->m_user;
    }
}

User* UserTree::find(const string& user_id){
    return find(user_id, m_root);
}

User* UserTree::find(const string& user_id, UserTree::UserNode* subtree) {
    if (!subtree) return nullptr;
    else if (user_id > subtree->m_user->m_user_id)
        return find(user_id, subtree->m_right);
    else if (user_id < subtree->m_user->m_user_id)
        return find(user_id, subtree->m_left);
    else
        return subtree->m_user;
}

User* UserTree::remove(User* user) {
    return remove(user, m_root);
}

User* UserTree::remove(User* user, UserTree::UserNode*& subtree) {
    if (!subtree) return nullptr; // warning? never in tree?
    else if (user->m_user_id > subtree->m_user->m_user_id)
        return remove(user, subtree->m_right);
    else if (user->m_user_id < subtree->m_user->m_user_id)
        return remove(user, subtree->m_left);
    else if (subtree->m_left && subtree->m_right) {
        UserNode* curr = subtree;
        UserNode* next = curr->m_right;
        while (next && next->m_left) {
            curr = next;
            next = next->m_left;
        }

        std::swap(subtree->m_user, next->m_user); // swap the users
        if (curr == subtree) {
            curr->m_right = next->m_right;
            next->m_right = nullptr;
        } else {
            curr->m_left = nullptr;
        }

        User* ret = next->m_user;
        delete next;
        return ret;
    } else if (subtree->m_left) {
        UserNode* to_delete = subtree;
        User* ret = to_delete->m_user;
        subtree = subtree->m_left;
        subtree->m_left = nullptr;
        delete to_delete;
        return ret;
    } else {
        UserNode* to_delete = subtree;
        User* ret = to_delete->m_user;
        subtree = subtree->m_right;
        subtree->m_right = nullptr;
        delete to_delete;
        return ret;
    }
}


