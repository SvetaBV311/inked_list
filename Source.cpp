#include <iostream>

template <class T>  

class LinkedList {
	struct Node {   
		T val;
		std::shared_ptr <Node> next;
		Node(T val) : val(val), next(nullptr) {};
	};
	std::shared_ptr <Node> head = nullptr; 
public:
	void Add(T val) {
		std::shared_ptr <Node> newNode = std::make_shared <Node>(val);
		if (!this->head) {
			this->head = newNode;
		}
		else {
			std::shared_ptr <Node> current = this->head;  
			while (current->next) { 
				current = current->next;
			}
			current->next = newNode;
		}
	}

	void Show() {
		std::shared_ptr <Node> current = this->head; 
		while (current) {
			std::cout << current->val << " ";
			current = current->next;
		}
		std::cout << std::endl;
	}

	bool Remove(T val) { 
		std::shared_ptr <Node> current = this->head;
		while (current->val != val) {
			current = current->next;
			if (current == nullptr) { std::cout << val << " is not found" << std::endl; return false; }
		}
		if (current == this->head) { this->head = this->head->next; }
		else {
			std::shared_ptr <Node> two = this->head;
			while (two->next->val != val) {
				two = two->next;
			}
			two->next = current->next;
		}
		return true;
	}

	std::shared_ptr <Node> Find(T val) {
		std::shared_ptr <Node> current = this->head;
		while (current->val != val) {
			current = current->next;
			if (current == nullptr) { std::cout << val << " is not found" << std::endl; return current; }
		}
		return current;
	}

	void Reverse() {
		std::shared_ptr <Node> previous = nullptr;
		std::shared_ptr <Node> current = this->head;
		std::shared_ptr <Node> nxt;

		while (current) {
			nxt = current->next;
			current->next = previous;
			previous = current;
			current = nxt;
		}
		this->head = previous;
	}
};

int main() {
	LinkedList <int> list;
	list.Add(10);
	list.Add(20);
	list.Add(30);
	list.Add(40);
	list.Show();
	list.Remove(40);
	list.Show();
	list.Remove(10);
	list.Show();
	list.Add(80);
	list.Add(90);
	list.Show();
	list.Reverse();
	list.Show();
	list.Remove(450);
	list.Show();
	std::cout << list.Find(10);
	std::cout << list.Find(80);
}
