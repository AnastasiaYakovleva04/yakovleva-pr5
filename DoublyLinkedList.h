#pragma once
#include <iostream>
class DoublyLinkedList
{
	struct Node {
		int data;
		Node* next;
		Node* prev;

		Node(int value) : data(value), next(nullptr), prev(nullptr) {};
	};

	Node* head;
	Node* tail;

	void PushFront(int value) {
		Node* temp = new Node(value);
		temp->next = head;
		head->prev = temp;
		head = temp;
	}

	void PushBack(int value){
		Node* temp = new Node(value);
		temp->prev = tail;
		tail->next = temp;
		tail = temp;
	}

	void PopFront() {
		head = head->next;
		head->prev = nullptr;
		if (head == nullptr) {
			head->next = nullptr;
		}
	}

	void PopBack() {
		tail = tail->next;
		tail->next = nullptr;
		if (tail == nullptr) {
			head = nullptr;
		}
	}

	void PrintList() {
		Node* temp = head;
		while (temp->next != nullptr) {
			std::cout << temp << "\n" << std::endl;
			temp = temp->next;
		}
	}
};

