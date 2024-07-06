#include <iostream>
#include <cassert>
#include <climits>
#include <vector>	
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
	int length = 0;
	vector<Node*> debug_data;
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
	void print() {
		for (Node* cur = head; cur; cur = cur->next)
			cout << cur->data << " ";
		cout << "\n";
	}
	void delete_node(Node* node) {
		debug_remove_node(node);
		--length;
		delete node;
	}
	void delete_front() {
		assert(length);
		Node* cur = head->next;
		delete_node(head);
		head = cur;

		if (length <= 1)
			tail = head;
	}
	void add_node(Node* node) {
		debug_add_node(node);
		++length;
	}
	void insert_front(int value) {
		Node* item = new Node(value);
		add_node(item);
		item->next = head;
		head = item;
		if (length = 1)
			tail = head;
	}
};

int main() {
	LinkedList ls;
	ls.insert_front(3);
	ls.insert_front(4);
	ls.print();
	ls.delete_front();
	ls.print();

}