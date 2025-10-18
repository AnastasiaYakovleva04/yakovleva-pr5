#include <iostream>

class DoublyLinkedList
{
	struct Node {
		int data;
		Node* next;
		Node* prev;

		Node(int value) {
			data = value;
			next = nullptr;
			prev = nullptr;
		}
	};

	Node* head = nullptr;
	Node* tail = nullptr;

public:
	~DoublyLinkedList() {}

	void push_front(int value) {
		Node* temp = new Node(value);
		if (head == nullptr){
			head = temp;
			tail = temp;
		}
		else {
			temp->next = head;
			head->prev = temp;
			head = temp;
		}
	}

	void push_back(int value) {
		Node* temp = new Node(value);
		if (head == nullptr) {
			head = temp;
			tail = temp;
		}
		else {
			temp->prev = tail;
			tail->next = temp;
			tail = temp;
		}
	}

	void pop_front() {
		if (head == nullptr) {
			std::cout << "list is empty" << std::endl;
		}
		else{
			head = head->next;
			head->prev = nullptr;
			if (head == nullptr) {
				head->next = nullptr;
			}
		}
	}

	void pop_back() {
		if (head == nullptr) {
			std::cout << "list is empty" << std::endl;
		}
		else {
			tail = tail->next;
			tail->next = nullptr;
			if (tail == nullptr) {
				head = nullptr;
			}
		}
	}

	void display() {
		if (head == nullptr) {
			std::cout << "list is empty" << std::endl;
		}
		else {
			Node* temp = head;
			while (temp != nullptr) {
				std::cout << temp->data << std::endl;
				temp = temp->next;
			}
			delete temp;
		}
	}
	void sort() {
		if (head == nullptr) {
			std::cout << "list is empty" << std::endl;
		}
		else {
			for (Node* cur = head; cur != nullptr; cur = cur->next) {
				for (Node* temp = head; temp->next != nullptr; temp = temp->next) {
					if (cur->data < temp->data) {
						int dat = cur->data;
						cur->data = temp->data;
						temp->data = dat;
					}
				}
			}
			display();
		}
	}
	void remove_duplicates() {
		for (Node* cur = head; cur != nullptr; cur = cur->next) {
			for (Node* temp = cur->next; temp != nullptr; temp = temp->next) {
				if (cur->data == temp->data) {
					temp->prev->next = temp->next;
					if (temp->next != nullptr) {
						temp->next->prev = temp->prev;
					}
				}
			}
		}
	}
};

void print_menu() {
	std::cout << "choose action:\n1.push front\n2.push back\n3.pop front\n4.pop back\n5.display\n6.sort\n7.remove duplicates\n8.exit" << std::endl;
}

int main()
{
	DoublyLinkedList list;
	int value;
	int act = 0;
	while (act != 8) {
		print_menu();
		std::cin >> act;
		switch (act) {
		case 1:
			std::cout << "value: " << std::endl;
			std::cin >> value;
			list.push_front(value);
			std::cout << "added" << std::endl;
			break;
		case 2: 
			std::cout << "value: " << std::endl;
			std::cin >> value;
			list.push_back(value);
			std::cout << "added" << std::endl;
			break;
		case 3: 
			list.pop_front();
			std::cout << "deleted" << std::endl;
			break;
		case 4:
			list.pop_back();
			std::cout << "deleted" << std::endl;
			break;
		case 5:
			std::cout << "list:" << std::endl;
			list.display();
			break;
		case 6:
			std::cout << "sorted list:" << std::endl;
			list.sort();
		case 7:
			list.remove_duplicates();
			std::cout << "removed" << std::endl;
			break;
		case 8:
			break;
		default:
			std::cout << "not correct action" << std::endl;
		}
	}
	system("pause");
	return 0;
}
