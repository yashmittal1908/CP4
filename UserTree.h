#include <string>
#include "User.h"

using std::string;

class UserTree {
    struct UserNode {
        User* m_user = nullptr;
        UserNode* m_left = nullptr;
        UserNode* m_right = nullptr;
        ~UserNode() {
            delete m_left;
            delete m_right;
            delete m_user;
        }
    };
    UserNode* m_root = nullptr;

    User* insert(User* user, UserNode*& subtree);
    User* find(const string& user_id, UserNode* subtree);
    User* remove(User* user, UserNode*& subtree);
public:
    User* insert(User* user);
    User* find(const string& user_id);
    void remove(User* user);
    void io();
    void inorder(UserNode * u);

    ~UserTree() {
        delete m_root;
    }
};
