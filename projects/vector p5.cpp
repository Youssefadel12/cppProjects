#include <iostream>
#include<cassert>
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
	void set(int idx, int val) {
		assert(0 <= idx && idx < size);
		arr[idx] = val;
	}
	void print() {
		for (int i = 0; i < size; ++i)
			cout << arr[i] << " ";
		cout << "\n";
	}
	int improved_search(int val) {
		for (int i = 0; i < size; i++) {
			if (arr[i] == val) {
				if (i == 0)
					return 0;
				swap(arr[i], arr[i - 1]);
				return i - 1;
			}
			return -1;
		}
}
};
int main()
{

	Vector v(5);
	for (int i = 0; i < 5; ++i)
		v.set(i, i);
	v.print();
}
