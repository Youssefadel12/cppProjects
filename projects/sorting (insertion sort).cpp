#include <iostream>
#include <vector>
using namespace std;
void insertionSort(vector<int>& nums) {
	for (int i = 1; i < nums.size(); i++) {
		int key = nums[i];
		int j = i - 1;   //1 5 7 4 2
		if (nums[j] > key && j >= 0) {
			nums[j + 1] = nums[j];
			j--;
		}
		nums[j +1] = key;
	}
}
int main()
{
	vector<int>v = { 2 ,1,5,3 };
	insertionSort(v);
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
}
