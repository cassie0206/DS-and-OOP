#include <iostream>
#include <vector>
#include <ctime>
using namespace std;




void merge(vector<int>& v, int l, int m, int r) {
	vector<int> v_l, v_r;
	for (int i = l; i <= m; i++) {
		v_l.push_back(v[i]);
	}
	for (int i = m + 1; i <= r; i++) {
		v_r.push_back(v[i]);
	}
	int i = 0, j = 0;
	/*while (i < m-l+1 || j < r-m) {
		if (j == r - m || v_l[i] < v_r[j]) {
			v[k++] = v_l[i++];
			if (j == r - m+1) {
				break;
			}
		}
		else if (i == m-l+1 || v_l[i] > v_r[j]) {
			v[k++] = v_r[j++];
			if (i == m - l + 2) {
				break;
			}
		}
	}*/
	for (int k = l; k <= r; k++) {
		if (i == m - l + 1) {
			v[k] = v_r[j++];
		}
		else if (j == r - m || v_l[i] <= v_r[j]) {
			v[k] = v_l[i++];
		}
		else if (v_l[i] > v_r[j]) {
			v[k] = v_r[j++];
		}
	}
}


void merge_sort(vector<int>& v, int l, int r) {
	if (r > l) {
		int m = (l + r) / 2;
		merge_sort(v, l, m);
		merge_sort(v, m + 1, r);
		merge(v, l, m, r);
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
		
		merge_sort(v, 0, v.size() - 1);

		
		for (int i = 0; i < num; i++) {
			cout << v[i] << " ";
		}cout << endl;
		v.clear();
		cin >> num;
	}
	

	

	return 0;
}