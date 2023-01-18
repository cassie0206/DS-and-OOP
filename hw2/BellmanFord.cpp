#include <iostream>
#include <vector>
using namespace std;

class edge {
public:
	int start, end, cost;
};

void merge(vector<edge>& v, int l, int m, int r) {
	vector<edge> v_l, v_r;
	for (int i = l; i <= m; i++) {
		v_l.push_back(v[i]);
	}
	for (int i = m + 1; i <= r; i++) {
		v_r.push_back(v[i]);
	}
	int i = 0, j = 0;
	for (int k = l; k <= r; k++) {
		if (i == m - l + 1) {
			v[k] = v_r[j++];
		}
		else if (j == r - m || v_l[i].start <= v_r[j].start) {
			v[k] = v_l[i++];
		}
		else if (v_l[i].start > v_r[j].start) {
			v[k] = v_r[j++];
		}
	}
}


void merge_sort(vector<edge>& v, int l, int r) {
	if (r > l) {
		int m = (l + r) / 2;
		merge_sort(v, l, m);
		merge_sort(v, m + 1, r);
		merge(v, l, m, r);
	}
}


void bellman_ford(vector<edge>& E, int s, int t, int node,int edge) {
	vector<int> weight;
	for (int i = 0; i < node; i++) {
		if (i == s) {
			weight.push_back(0);
		}
		else {
			weight.push_back(100000);
		}
	}
	merge_sort(E, 0, edge - 1);
	for (int i = 0; i < node - 1; i++) {
		for (int j = 0; j < edge; j++) {
			if (weight[E[j].start] + E[j].cost < weight[E[j].end]) {
				weight[E[j].end] = weight[E[j].start] + E[j].cost;
			}
		}
	}
	for (int j = 0; j < edge; j++) {
		if (weight[E[j].start] + E[j].cost < weight[E[j].end]) {
			cout << "Negative loop detected!" << endl;
			return;
		}
	}
	cout << weight[t];


}


int main() {
	int m, n;
	cin >> m >> n;
	int s, t;
	cin >> s >> t;
	vector<edge> E;
	edge e;
	int a, b, c;
	vector<vector<int>> matrix(n, vector<int>(3, 100000));
	for (int i = 0; i < n; i++) {
		cin >> a >> b >> c;
		e.start = a;
		e.end = b;
		e.cost = c;
		E.push_back(e);
	}
	bellman_ford(E, s, t, m, n);


	return 0;
}