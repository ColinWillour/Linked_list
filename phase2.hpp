#pragma once
#include <iostream>
#include <memory>

class LinkedList {
private:
    struct Node {
        int value;
        std::unique_ptr<Node> next;
        Node(int v) : value(v), next(nullptr) {}
    };

    std::unique_ptr<Node> head_;
    Node* tail_;   // non-owning, just for O(1) append

public:
    LinkedList() : head_(nullptr), tail_(nullptr) {}
    ~LinkedList() = default;  // unique_ptr chain deletes itself

    LinkedList(const LinkedList&) = delete;
    LinkedList& operator=(const LinkedList&) = delete;

    void push_back(int value) {
        auto n = std::make_unique<Node>(value);
        Node* raw = n.get();   // grab raw ptr before moving
        if (!head_) {
            head_ = std::move(n);
        } else {
            tail_->next = std::move(n);
        }
        tail_ = raw;
    }

    void print(std::ostream& os) const {
        Node* curr = head_.get();
        while (curr) {
            os << curr->value;
            if (curr->next) os << " -> ";
            curr = curr->next.get();
        }
        os << "\n";
    }
};
