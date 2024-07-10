#include <iostream>
#include <cassert>
using namespace std;

// simple trick to avoid re-changing the class
typedef char type;

class Stack {
private:
	int size{ };
	int top{ };
	type* array{ };
public:
	Stack(int size) :
		size(size), top(-1) {
		array = new type[size];
	}

	~Stack() {
		delete[] array;
	}

	void push(type x) {
		assert(!isFull());
		array[++top] = x;
	}

	type pop() {
		assert(!isEmpty());
		return array[top--];
	}

	type peek() {
		assert(!isEmpty());
		return array[top];
	}

	int isFull() {
		return top == size - 1;
	}

	int isEmpty() {
		return top == -1;
	}

	void display() {
		for (int i = top; i >= 0; i--)
			cout << array[i] << " ";
		cout << "\n";
	}
};

string reverse_subwords(string line) {
	string result;
	line += ' ';
	Stack stk(line.size());
	for (int i = 0; i < (int)line.size(); i++) {
		if (line[i] == ' ') {
			while (!stk.isEmpty())
				result += stk.pop();
			result += ' ';
		}
		else
			stk.push(line[i]);	
	}
	return result;
}

int main() {
	string line;
	getline(cin, line);

	cout << reverse_subwords(line) << "\n";

	return 0;
}
