// 1260.cpp
// DFS¿Í BFS

#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;

vector<int> v[1001];
queue<int> q;
int visited[1001] = { 0 };
int order[1000];
int pos = 0;

void dfs(int cur) {
	visited[cur] = 1;
	order[pos] = cur;
	for (int i = 0; i < v[cur].size(); i++) {
		if (visited[v[cur][i]] == 0) {
			pos++;
			dfs(v[cur][i]);
		}
	}
}

void bfs(int cur) {
	visited[cur] = 1;
	q.push(cur);

	while (!q.empty()) {
		cur = q.front();
		q.pop();
		order[pos] = cur;
		pos++;
		for (int i = 0; i < v[cur].size(); i++) {
			if (visited[v[cur][i]] == 0) {
				visited[v[cur][i]] = 1;
				q.push(v[cur][i]);
			}
		}
	}
}

int main() {

	int N, M, V;
	scanf("%d %d %d", &N, &M, &V);

	for (int i = 0; i < M; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}

	for (int i = 1; i <= N; i++)
		sort(v[i].begin(), v[i].end());

	dfs(V);
	
	for (int i = 0; i < N; i++) {
		if (order[i] == 0)
			continue;
		printf("%d ", order[i]);
	}
	printf("\n");

	pos = 0;
	for (int i = 0; i < N; i++) {
		visited[i + 1] = 0;
		order[i] = 0;
	}
	
	bfs(V);

	for (int i = 0; i < N; i++) {
		if (order[i] == 0)
			continue;
		printf("%d ", order[i]);
	}
	printf("\n");

	return 0;
}