#pragma once
#include <iostream>
#include <memory>

class DoublyLinkedList {
private:
    struct Node {
        int value;
        std::shared_ptr<Node> next;
        std::shared_ptr<Node> prev;
        Node(int v) : value(v) {}
        ~Node() {
            std::cout << "Destroying node " << value << "\n";
        }
    };

    std::shared_ptr<Node> head_;
    std::shared_ptr<Node> tail_;

public:
    DoublyLinkedList() = default;
    ~DoublyLinkedList() = default;

    DoublyLinkedList(const DoublyLinkedList&) = delete;
    DoublyLinkedList& operator=(const DoublyLinkedList&) = delete;

    void push_back(int value) {
        auto n = std::make_shared<Node>(value);
        if (!head_) {
            head_ = tail_ = n;
        } else {
            n->prev = tail_;
            tail_->next = n;
            tail_ = n;
        }
    }

    void print_forward(std::ostream& os) const {
        auto curr = head_;
        while (curr) {
            os << curr->value;
            if (curr->next) os << " -> ";
            curr = curr->next;
        }
        os << "\n";
    }
};
