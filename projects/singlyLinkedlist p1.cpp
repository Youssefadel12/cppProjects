#include <iostream>
#include <cassert>
using namespace std;

struct Node {
	int data{};
	Node* next{};
	Node(int data) : data(data) {}
	~Node() {
		cout << "Destroy value: " << data << "at address" << this << "\n";
	}
};
class LinkedList {
private:
	Node* head{ };
	Node* tail{ };
	int length = 0;
public:
	void insert_end(int value) {
		Node* item = new Node(value);
		if (!head)
			head = tail = item;
		else {
			tail->next = item;
			tail = item;
		}
	}
	~LinkedList() {
		while (head) {
			Node* cur = head->next;
			delete head;
			head = cur;
		}
	}
};
int main() {

	LinkedList list;
	list.insert_end(6);
	list.insert_end(10);
	list.insert_end(8);
	list.insert_end(15);

	return 0;
}