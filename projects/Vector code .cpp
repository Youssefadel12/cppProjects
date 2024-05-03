#include <iostream>
#include <cassert>
using namespace std; 

class Vector {
private:
	int* arr = nullptr;
	int size = 0;
	int capacity = 0;
public:
	Vector(int size) :
		size(size) {
		if (size < 0)
			size = 1;
		capacity = size + 10;
		arr = new int[capacity] {};
	}

	~Vector() {
		delete[] arr;
		arr = nullptr;
	}

	int get_size() {
		return size;
	}

	int get(int idx) {
		assert(0 <= idx && idx < size);
		return arr[idx];
	}

	void set(int idx, int val) {
		assert(0 <= idx && idx < size);
		arr[idx] = val;
	}

	void print() {
		for (int i = 0; i < size; ++i)
			cout << arr[i] << " ";
		cout << "\n";
	}

	int find(int value) {
		for (int i = 0; i < size; ++i)
			if (arr[i] == value)
				return i;
		return -1;	
	}

	int get_front() {
		return arr[0];
	}

	int get_back() {
		return arr[size - 1];
	}


	void push_back(int value) {
		if (size == capacity) 
			expand_capacity();
		arr[size++] = value;
	}
	void expand_capacity() {
		capacity *= 2;
		cout << "Expanded capacity to: " << capacity;
		int* arr2 = new int [capacity] {};
		for (int i = 0; i < size; i++)
			arr2[i] = arr[i];
		swap(arr, arr2);
		delete[]arr2;
	}
	void insert(int idx, int val) {
		assert(0 <= idx && idx < size);
		if (size == capacity)
			expand_capacity();
		for (int i = size - 1; i >= idx; i--)
			arr[i + 1] = arr[i];
		arr[idx] = val;
		size++;
	}
};

int main() {

	int n = 4;
	Vector v(n);
	for (int i = 0; i < n; ++i)
		v.set(i, i);
	v.insert(3, 20);
	v.push_back(15);
	v.push_back(17);
	v.push_back(19);
	v.print();
	

	return 0;
}
