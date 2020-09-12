// 1865.cpp
// 웜홀
// 
// 문제를 잘 읽어보면 가중치가 음수인 경우를 포함하여 거리를 계산해야되므로 Bellman-Ford Algorithm이 사용된다.
// (Bellman-Ford Algorithm을 이해했다는 가정하에 설명하겠다.)
// 이 문제의 경우에는 Bellman-Ford Algorithm을 사용하지만 특정 점에서 특정 점까지의 최단거리를 구하는 것 보다는
// "음의 cycle이 있는지를 확인하는 것" 에 초점을 둬서 푸는 문제다. (문제를 잘 읽어보면 알 것이다.)
//
// 따라서 시작점을 지정해주지 않고 그냥 Bellman-Ford Algorithm을 한번 돌린 뒤 한번 더 돌려줘서 dist[] 값이 바뀌었는지를 체크하여 
// 바뀐 경우 음의 cycle이 있기에 YES를 출력하고, 바뀌지 않는 경우 음의 cycle이 없는 경우이므로 NO를 출력해주면 된다.

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int INF = 1e9 + 7;
const int MAX = 501;
int dist[MAX];

bool Bellman_Ford(vector<pair<int,int>> v[], int N) {

	bool update = false;
	for (int t = 1; t < N; t++) {
		for (int i = 1; i <= N; i++) {
			for (unsigned int j = 0; j < v[i].size(); j++) {
				int next = v[i][j].first;
				int adj = v[i][j].second;
				if (dist[next] > dist[i] + adj) {
					update = true;
					dist[next] = dist[i] + adj;
				}
			}
		}
	}
	if(update)
		return true;
	else
		return false;
}

int main() {

	int TC;
	cin >> TC;

	for (int tc = 0; tc < TC; tc++) {

		int N, M, W;
		vector <pair<int, int>> v[MAX];
		cin >> N >> M >> W;

		for (int i = 0; i < M; i++) {
			int S, E, T;
			cin >> S >> E >> T;
			v[S].push_back(make_pair(E, T));
			v[E].push_back(make_pair(S, T));
		}

		for (int i = 0; i < W; i++) {
			int S, E, T;
			cin >> S >> E >> T;
			v[S].push_back(make_pair(E, (-1)*T));
		}

		for (int i = 1; i <= N; i++)
			dist[i] = INF;
		
		Bellman_Ford(v, N);

		if(Bellman_Ford(v, N))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;

	}

	return 0;
}