#include <iostream>
#include <vector>

using namespace std;

int dijkstra(vector<vector<int>>& matrix, int s, int t,int node) {
	vector<int> weight;
	vector<bool> visit;
	/*for (int i = 0; i < node; i++) {
		if (i == s) {
			weight.push_back(0);
			visit.push_back(true);
		}
		else if (matrix[s][i] != 0) {
			weight.push_back(matrix[s][i]);
			visit.push_back(false);
		}
		else {
			weight.push_back(10001);
			visit.push_back(false);
		}
	}*/
	for (int i = 0; i < node; i++) {
		weight.push_back(100000);
		visit.push_back(false);
	}
	weight[s] = 0;
	
	for (int i = 0; i < node ; i++) {
		int min = 100000, key = 0;
		for (int j = 0; j < node; j++) {
			if (visit[j]==false&&min >= weight[j]) {
				min = weight[j];
				key = j;
			}
		}
		visit[key] = true;
		for (int j = 0; j < node; j++) {
			if (visit[j]==false /*&&matrix[key][j]>=1*/&& matrix[key][j] + weight[key] < weight[j]) {
				weight[j] = matrix[key][j] + weight[key];
			}
		}
		//visit[key] = true;
	}
	return weight[t];

}



int main() {
	int m, n;
	cin >> m >> n;
	int s, t;
	cin >> s >> t;
	int a, b, c;
	vector<vector<int>> matrix(m, vector<int>(m, 100000));
	for (int i = 0; i < n; i++) {
		cin >> a >> b >> c;
		matrix[a][b] = c;
	}
	cout << dijkstra(matrix, s, t, m);


	return 0;
}