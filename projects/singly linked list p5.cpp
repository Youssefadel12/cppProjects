#include <iostream>
#include <cassert>
#include <climits>
#include <vector>		// for debug
#include <algorithm>
#include <sstream>
using namespace std;

struct Node {
	int data{ };
	Node* next{ };
	Node(int data) : data(data) {}
	~Node() {
		cout << "Destroy value: " << data << " at address " << this << "\n";
	}
};

class LinkedList {
private:
	Node* head{ };
	Node* tail{ };
	int length = 0;	// let's maintain how many nodes

	vector<Node*> debug_data;	// add/remove nodes you use

	void debug_add_node(Node* node) {
		debug_data.push_back(node);
	}
	void debug_remove_node(Node* node) {
		auto it = std::find(debug_data.begin(), debug_data.end(), node);
		if (it == debug_data.end())
			cout << "Node does not exist\n";
		else
			debug_data.erase(it);
	}

public:

	// Below 2 deletes prevent copy and assign to avoid this mistake
	LinkedList() {
	}
	LinkedList(const LinkedList&) = delete;
	LinkedList& operator=(const LinkedList& another) = delete;


	void print() {
		for (Node* cur = head; cur; cur = cur->next)
			cout << cur->data << " ";
		cout << "\n";
	}

	bool is_same1(const LinkedList &other) {
		Node* h1 = head, *h2 = other.head;
		while (h1 && h2) {
			if (h1->data != h2->data)
				return false;
			h1 = h1->next, h2 = h2->next;
		}
		return !h1 && !h2;
	}
	bool is_same(const LinkedList& other) {
		if (length != other.length) 
			return false;
		Node* other_h = head;
		for (Node* cur_h = head; cur_h; cur_h = cur_h->next) {
			if (cur_h->data != other_h->data)
				return false;
			other_h = other_h->next;
		}
		return true;
	}

};

void test1() {
	LinkedList list1;
	LinkedList list2;

	assert(list1.is_same(list2));
	list1.insert_end(6);
	list1.insert_end(10);
	list2.insert_end(6);
	assert(!list1.is_same(list2));
	list2.insert_end(10);
	assert(list1.is_same(list2));
	list1.insert_end(8);
	list1.insert_end(15);
	list2.insert_end(8);
	list2.insert_end(77);
	assert(!list1.is_same(list2));
}


int main() {
	test1();
	//test2();
	//test3();

	// must see it, otherwise RTE
	cout << "\n\nNO RTE\n";

	return 0;
}
