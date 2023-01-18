#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int prim(vector<vector<int>>& matrix, int node) {
	vector<int> weight;
	for (int i = 0; i < node; i++) {
		if (i == 0) {
			weight.push_back(0);
		}
		else {
			weight.push_back(10001);
		}
	}
	queue<int> q;
	q.push(0);
	vector<bool> visit;
	for (int i = 0; i < node; i++) {
		visit.push_back(false);
	}
	//int min = 1001, key = 0;
	while (!q.empty()) {
		int index;
		index = q.front(); q.pop();
		for (int i = 0; i < node; i++) {
			if (matrix[index][i] != 0 && visit[i] == false && weight[i] > matrix[index][i]) {
				weight[i] = matrix[index][i];
			}
		}
		visit[index] = true;
		int min = 10001, key = 0;
		for (int i = 1; i < node; i++) {
			if (visit[i]==false&&min > weight[i]) {
				min = weight[i];
				key = i;
			}
		}
		if (key != 0) {
			q.push(key);
		}
	}
	int sum = 0;
	for (int i = 1; i < node; i++) {
		sum += weight[i];
	}
	return sum;

}

int main() {
	int m, n;
	cin >> m >> n;
	vector<vector<int>> matrix(m, vector<int>(m, 0));
	int a, b, c;
	for (int i = 0; i < n; i++) {
		cin >> a >> b >> c;
		matrix[a][b] = c;
		matrix[b][a] = c;
	}
	cout << prim(matrix, m);




	return 0;
}