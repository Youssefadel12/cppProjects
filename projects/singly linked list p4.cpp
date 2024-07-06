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
	Node* get_nth(int n) {
		int cnt = 0;
		for (Node* cur = head; cur; cur = cur->next) {
			if (++cnt == n)
				return cur;
		}
		return nullptr;
	}
	Node* get_nth_back(int n) {
		if (length < n)
			return nullptr;
		return get_nth(length - n + 1);
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