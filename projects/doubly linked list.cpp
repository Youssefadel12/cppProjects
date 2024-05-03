#include <iostream>
#include<vector>
#include<cassert>
using namespace std;
struct Node {
	Node* next{};
	Node* prev{};
	int data{};
Node(int data):data(data){}
void set(Node* next, Node* prev) {
	this->next = next;
	this->prev = prev;
}
~Node() {
	cout << "Destroy value: " << data << " at address " << this << "\n";
}
};
class doubly_linkedlist {
private:
	Node* head{};
	Node* tail{};
	int length = 0;
	vector<Node*>debug_data;
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
	void debug_verify_data_integrity() {
		if (length == 0) {
			assert(head == nullptr);
			assert(tail == nullptr);
		}
		else {
			assert(head != nullptr);
			assert(tail != nullptr);
			if (length == 1)
				assert(head == tail);
			else
				assert(head != tail);
			assert(!head->prev);
			assert(!tail->next);
		}
		int len = 0;
		for (Node* cur = head; cur; cur = cur->next, len++) {
			if (len == length - 1)	// make sure we end at tail
				assert(cur == tail);
		}

		assert(length == len);
		assert(length == (int)debug_data.size());

		len = 0;
		for (Node* cur = tail; cur; cur = cur->prev, len++) {
			if (len == length - 1)	// make sure we end at head
				assert(cur == head);
		}
		cout << "\n";
	}
	void print_reversed() {
		for (Node* cur = tail; cur; tail = tail->prev)
			cout << cur->data << " ";
		cout << endl;
	}
	void add_node(Node* node) {
		debug_add_node(node);
		++length;
	}
	void link(Node* first, Node* second) {
		if (first)
			first->next = second;
		if (second)
			second->prev = first;
	}
	void insert_end(int value) {
		Node* item = new Node(value);
		add_node(item);
		if (!head) 
			head = tail = item;
		else {
			link(tail, item);
			tail = item;
		}
		debug_verify_data_integrity();
	}
	void insert_first(int value) {
		Node* item = new Node(value);
		add_node(item);
		if (!head)
			head = tail = item;
		else {
			link(item, head);
			head = item;
		}
		debug_verify_data_integrity();
	}
	void insert_sorted(int value) {
		if (!length || value <= head->data)
			insert_first(value);
		else if (tail->data <= value)
			insert_end(value);
		else {
			for (Node* cur = head; cur; cur = cur->next) {
				if (value <= cur->data) {
					embed_value(cur->prev, value);
					break;
				}
			}
		}
	}
	void embed_value(Node* node_before, int value) {
		Node* middle = new Node(value);
		++length;
		debug_add_node(middle);
		Node* node_after = node_before->next;
		link(node_before, middle);
		link(middle, node_after);
	}
	void delete_node(Node* node) {
		debug_remove_node(node);
		--length;
		delete node;
	}
	void delete_front() {
		if (!head)
			return;
		Node* cur = head;
		head = head->next;
		
		delete_node(cur);
		if (head)
			head->prev = nullptr;
		else if (!length)
			tail = nullptr;
		debug_verify_data_integrity();
	}
	Node* delete_and_link(Node* cur) {
		Node* ret = cur->prev;
		link(cur->prev, cur->next);
		delete_node(cur);
		return ret;
	}
	void delete_node_withkey(int value) {
		if (!length)
			return;
		if (head->data == value)
			delete_front();
		else {
			for (Node* cur = head; cur; cur = cur->next) {
				if (cur->data == value) {
					cur = delete_and_link(cur);
					if (!cur->next)
						tail = cur;
					break;
				}
			}
		}
		debug_verify_data_integrity();
	}
};
int main()
{
  
}
