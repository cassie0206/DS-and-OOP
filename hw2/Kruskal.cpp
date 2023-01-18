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
		else if (j == r - m || v_l[i].cost < v_r[j].cost) {
			v[k] = v_l[i++];
		}
		else if (v_l[i].cost >= v_r[j].cost) {
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

long unsigned int find(vector<vector<int>>& vertex, int x) {
	long unsigned int index = 0;
	for (long unsigned int i = 0; i < vertex.size(); i++) {
		for (long unsigned int j = 0; j < vertex[i].size(); j++) {
			if (x == vertex[i][j]) {
				index = i;
				return index;
			}
		}
	}
	return index;
}

void Union(vector<vector<int>>& vertex, int s, int e) {
	int s_index, e_index;
	s_index = find(vertex, s);
	e_index = find(vertex, e);
	if (vertex[s_index].size() >= vertex[e_index].size()) {
		vertex[s_index].insert(vertex[s_index].end(), vertex[e_index].begin(), vertex[e_index].end());
		vertex[e_index].clear();
	}
	else {
		vertex[e_index].insert(vertex[e_index].end(), vertex[s_index].begin(), vertex[s_index].end());
		vertex[s_index].clear();
	}
}

int kruskal(vector<edge>& e, int edge, int node) {
	merge_sort(e, 0, edge - 1);
	vector<vector<int>> vertex;
	vector<int> row;
	for (int i = 0; i < node; i++) {
		row.push_back(i);
		vertex.push_back(row);
		row.clear();
	}
	int weight = 0;
	int k = 0;
	int i = 0;
	while (k < node - 1) {
		if (find(vertex, e[i].start) != find(vertex, e[i].end)) {
			Union(vertex, e[i].start, e[i].end);
			weight += e[i].cost;
			k++;
		}
		i++;
	}
	return weight;
}


int main() {
	int m, n;
	cin >> m >> n;
	vector<edge> E;
	int a, b, c;
	edge e;
	for (int i = 0; i < n; i++) {
		cin >> a >> b >> c;
		e.start = a;
		e.end = b;
		e.cost = c;
		E.push_back(e);
	}
	cout << kruskal(E, n, m);



	return 0;
}