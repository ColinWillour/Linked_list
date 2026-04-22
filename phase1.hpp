#pragma once
#include <iostream>

class LinkedList {
private:
    struct Node {
        int value;
        Node* next;
        Node(int v) : value(v), next(nullptr) {}
    };

    Node* head_;
    Node* tail_;

public:
    LinkedList() : head_(nullptr), tail_(nullptr) {}

    ~LinkedList() {
        Node* curr = head_;
        while (curr) {
            Node* next = curr->next;
            delete curr;
            curr = next;
        }
    }

    LinkedList(const LinkedList&) = delete;
    LinkedList& operator=(const LinkedList&) = delete;

    void push_back(int value) {
        Node* n = new Node(value);
        if (!head_) {
            head_ = tail_ = n;
        } else {
            tail_->next = n;
            tail_ = n;
        }
    }

    void print(std::ostream& os) const {
        Node* curr = head_;
        while (curr) {
            os << curr->value;
            if (curr->next) os << " -> ";
            curr = curr->next;
        }
        os << "\n";
    }
};
