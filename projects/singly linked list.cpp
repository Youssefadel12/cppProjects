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

	void print() {
		for (Node* cur = head; cur; cur = cur->next) {
			cout << cur->data << " ";
	}
		cout << endl;
	}
	void insert_end(int value) {
		Node* item = new Node(value);
		if (!head)
			head = tail = item;
		else {
			tail->next = item;
			tail = item;
		}
	}
   Node* get_nth(int nth){
		int c = 1;
		for (Node* cur = head; cur; cur = cur->next) {
			if (c == nth)
				return cur;
			c++;
		}
		return nullptr;
	}
   int search(int value) {
	   int idx = 0;
	   for (Node* cur = head; cur; cur = cur->next,idx++){
		   if (cur->data == value)
			   return idx;
	   }
	   return -1;
   }
   int search_improved(int value) {
	   int idx = 0;
	   Node* prev = nullptr;
	   for (Node* cur = head; cur; cur = cur->next, idx++) {
		   if (cur->data == value) {
			   if (!prev)
				   return idx;
			   swap(cur->data, prev->data);
			   return idx - 1;
		   }
		   prev=cur;
	   }
   }
   void verify_data_integraty() {
	   if (length = 0) {
		   assert(head == nullptr);
		   assert(tail == nullptr);
		   return;
	   }
	   assert(head != nullptr);
	   assert(tail != nullptr);
	   assert(tail->next == nullptr);
	   if (length == 1) {
		   assert(head == tail);
	   }
	   else {
		   assert(head != tail);
		   if (length == 2)
			   assert(head->next == tail);
		   else if (length==3) {
			   assert(head->next);
			   assert(head->next->next == tail);
		   }
	   }
	   int len = 0;
	   Node* prev = nullptr;
	   for (Node* cur = head; cur; prev = cur, cur = cur->next, len++) {
		   assert(len < 10000);
	   }
	   assert(length == len);
	   assert(prev == tail);
   }
};
int main() {
	LinkedList list;
	list.insert_end(6);
	list.insert_end(10);
	list.insert_end(8);
	list.insert_end(15);
	list.print();
Node*res=list.get_nth(3);
cout << res->data;
	cout << endl;
	cout << list.search(8);
	cout << endl;
	cout << list.search_improved(6);
	return 0;
}


