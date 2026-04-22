#include <iostream>
#include "doubly_linked_list_weak.hpp"

int main() {
	{
		DoublyLinkedList list;
		list.push_back(1);
		list.push_back(2);
		list.push_back(3);
		list.print_forward(std::cout);
		std::cout << "\n";
		list.print_backward(std::cout);
		std::cout << "\n";
	}

	std::cout << "Finished scope\n";
	return 0;
}
