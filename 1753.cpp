// 1753.cpp

#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>

using namespace std;

const int INF = 1e9 + 1;
const int MAX = 20001;

vector <pair<int, int>> vertex[MAX];
int dist[MAX];
int V, E, K;

void Dijkstra() {
	
	priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	dist[K] = 0;
	pq.push(make_pair(0,K));

	while (!pq.empty()) {

		int cost = pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (dist[cur] < cost && dist[cur] != -1)
			continue;

		for (unsigned int i = 0; i < vertex[cur].size(); i++) {
			int next = vertex[cur][i].second;
			int nextDist = cost + vertex[cur][i].first;

			if (dist[next] >= nextDist || dist[next] == -1) {
				dist[next] = nextDist;
				pq.push(make_pair(dist[next], next));
			}
		}
	}
}

int main() {

	cin >> V >> E;
	cin >> K;

	for (int i = 0; i < E; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		vertex[u].push_back(make_pair(w,v));
	}

	memset(dist, -1, sizeof(dist));
	Dijkstra();
	
	for (int i = 1; i <= V; i++) {
		if (dist[i] == -1)
			printf("INF\n");
		else
			printf("%d\n", dist[i]);
	}
	return 0;
}