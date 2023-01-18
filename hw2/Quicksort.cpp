#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

void swap(int& a, int& b) {
	int temp = 0;
	temp = a;
	a = b;
	b = temp;
}


int partition(vector<int>& v, int left, int right) {
	int i = left - 1;
	for (int j = left; j <= right; j++) {
		if (v[j] < v[right]) {
			i++;
			swap(v[i], v[j]);
		}
	}
	swap(v[++i], v[right]);
	return i;
}

void quick_sort(vector<int>& v, int left, int right) {
	if (left < right) {
		int q = partition(v, left, right);
		quick_sort(v, left, q - 1);
		quick_sort(v, q + 1, right);
	}
}

int main() {
	int num;
	cin >> num;
	while (num != 0) {
		vector<int> v;
		int x;
		for (int i = 0; i < num; i++) {
			cin >> x;
			v.push_back(x);
		}
		quick_sort(v, 0, v.size() - 1);
		for (int i = 0; i < num; i++) {
			cout << v[i] << " ";
		}cout << endl;
		v.clear();
		cin >> num;
	}




	return 0;
}