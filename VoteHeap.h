#include <vector>
#include "UserTree.h"

using std::size_t;
using std::vector;

class VoteHeap {
    friend class UserTree;
    vector<User*> m_heap;
public:
    void updateVotes(User* user, size_t votes);

    void scoreboard(size_t k);

    void increaseKey(size_t i, User* key);

    void insert(User* key);

    void heapify(size_t i);

    User* extractMax();

    size_t size() const noexcept;
};