// 17396.cpp
// 백도어

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

const int MAX = 100001;
vector<pair<int, int>> v[MAX];
priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> pq;
int a[MAX];
long long dist[MAX];
int N, M;

void Dijkstra() {
	pq.push({ 0,0 });
	int cur, cost;
	while (!pq.empty()) {
		cur = pq.top().second;
		cost = pq.top().first;
		pq.pop();
		if (dist[cur] < -cost && dist[cur] != 0)
			continue;

		for (unsigned int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i].second;
			long long nextCost = dist[cur] + v[cur][i].first;
			if ((a[next] == 0 || next == N - 1) && (dist[next] > nextCost || (dist[next] == 0) && next != 0)) {
				dist[next] = nextCost;
				pq.push({ -nextCost, next });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(stdin);
	cin.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> a[i];
	dist[0] = 0;
	for (int i = 0; i < M; i++) {
		int a, b, t;
		cin >> a >> b >> t;
		v[a].push_back({ t,b });
		v[b].push_back({ t,a });
	}
	Dijkstra();
	if (dist[N - 1] == 0)
		cout << "-1\n";
	else
		cout << dist[N - 1] << "\n";
	return 0;
}