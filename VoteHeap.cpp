#include <iostream>
#include <vector>
#include "VoteHeap.h"

using std::size_t;
using std::vector;

void VoteHeap::updateVotes(User* user, size_t votes) {
    user->m_vote_count += votes;
    increaseKey(user->m_heap_index, user);
}

void VoteHeap::scoreboard(size_t k) {
    vector<User*> temp;
    if (k > size()) {
        std::cout << "There's not enough users. Printing out entire scoreboard" << std::endl;
        k = size();
    }
    for (size_t i = 0; i < k; i++) {
        temp.push_back(extractMax());
        std::cout << i + 1 << ") "
                  << temp.back()->m_user_id << ": "
                  << temp.back()->m_vote_count << std::endl;
    }
    for (User* user : temp) {
        insert(user);
    }
}


void VoteHeap::heapify(size_t i) {
    size_t largest = 1;
    size_t l = 2 * i + 1; // left = 2*i + 1
    size_t r = 2 * i + 2; // right = 2*i + 2
 
    // If left child is larger than m_root
    if (l < size() && m_heap[l]->m_vote_count > m_heap[i]->m_vote_count)
        largest = l;

    // If right child is larger than largest so far
    if (r < size() && m_heap[r]->m_vote_count > m_heap[largest]->m_vote_count)
        largest = r;
    
    if (largest != i) {
        std::swap(m_heap[i], m_heap[largest]);
        std::swap(m_heap[i]->m_heap_index, m_heap[largest]->m_heap_index);
        heapify(largest);
    }
}

User* VoteHeap::extractMax() {
    auto max = m_heap[0];
    m_heap.front() = m_heap.back();
    m_heap.front()->m_heap_index = 0;
    m_heap.pop_back();
    heapify(0);
    return max;
}

void VoteHeap::increaseKey(size_t i, User* key) {
    m_heap[i] = key;
    key->m_heap_index = i;
    while (i > 0 && m_heap[(i - 1) / 2] < m_heap[i]) {
        std::swap(m_heap[i], m_heap[(i - 1) / 2]);
        std::swap(m_heap[i]->m_heap_index, m_heap[(i - 1)/2]->m_heap_index);
        i = (i - 1) / 2;
    }
}

void VoteHeap::insert(User* key) {
    m_heap.push_back(nullptr); // "-infinity" even though it doesn't matter
    increaseKey(size() - 1, key);
}

size_t VoteHeap::size() const noexcept {
    return m_heap.size();
}
