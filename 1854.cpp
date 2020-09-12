// 1854.cpp
// K번째 최단경로 구하기
// 
// 1번 도시에서 i번 도시로 가는 k번째 최단경로의 소요시간을 출력하라는 문제
// Dijkstra 알고리즘에서는 모든 경로를 돌아보면서 값을 비교하면서 최단경로를 찾기 때문에
// 여기서 우리는 priority queue를 하나 더 만들어 줘서 ( dist ) 모든 경로를 돌아볼 때, 해당 경로 까지 ( 1~i ) 의 경로 값들을 저장
// 이 때 모든 경로를 전부 저장하면 메모리 초과가 뜨게 된다.
// 따라서 priority queue를 max heap으로 구현해서 ( dist )
// 1~i 까지의 경로 값들 수가 if (dist[next].size() < k) 인 경우 계속 max heap에 경로 값들을 넣고
// 1~i 까지의 경로 값들 수가 k개 이상인 경우 else if (dist[next].top() > curCost + nextCost) 를 이용하여 max heap에서 경로 값이 최대인 경로 값과 이번에 들어온 경로 값 ( curCost + nextCost ) 을 비교하여 이번에 들어온 값이 더 작으면 넣어주면 된다.
// 예를 들어보면
// k = 4 인 경우 비교 이전에 dist[i] 에 2,4,7,10 의 경로 값들이 있었을 때, 이번에 들어온 경로 값이 6인 경우 10을 pop 해주고 6을 push 해줘서 dist[i]에 2,4,6,7의 경로 값이 들어가도록 하는 것이다. 이와 같이 해주면 4번째 최단경로를 구할 수 있게 된다.
// 마찬가지로 예시와 같이 하게 되면 k번째 최단경로가 dist[i].top() 에 들어가게 된다. 
// ( min heap이 아닌 max heap을 사용한 이유이기도 함 )
///////////////////////////////////////////////////////////////////////////////////////////////////////
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

const int MAX = 1001;

vector <pair<int, int>> v[MAX];
priority_queue <int, vector<int>, less<int>> dist[MAX];
priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int n, m;
unsigned int k;

void Dijkstra() {
	
	pq.push(make_pair(0, 1));
	dist[1].push(0);
	while (!pq.empty()) {
		int cur = pq.top().second;
		int curCost = pq.top().first;
		pq.pop();

		for (unsigned int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i].first;
			int nextCost = v[cur][i].second;
			if (dist[next].size() < k)
				dist[next].push(curCost + nextCost);
			else if (dist[next].top() > curCost + nextCost) {
				dist[next].pop();	
				dist[next].push(curCost + nextCost);
			}
			else
				continue;
			pq.push(make_pair(curCost + nextCost, next));
		}
	}
}

int main() {

	cin >> n >> m >> k;

	for (int i = 0; i < m; i++) {
		int s, e, a;
		cin >> s >> e >> a;
		v[s].push_back(make_pair(e, a));
	}

	Dijkstra();

	for (int i = 1; i <= n; i++) {
		if (dist[i].size() == k)
			cout << dist[i].top() << endl;
		else
			cout << "-1" << endl;
	}

	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
// error case 1
// 처음에는 단순하게 Dijkstra 알고리즘을 구현하여 나오는 dist를 전부 priority queue 에 집어넣어보았다.
// 다음 코드와 같이 구현하였고 모든 dist가 들어가지도 않고, 같은 dist가 두 번 이상 들어가는 중복의 오류도 생김
///////////////////////////////////////////////////////////////////////////////////////////////////////
// 틀린코드
///////////////////////////////////////////////////////////////////////////////////////////////////////
vector <pair<int, int>> v[MAX];
priority_queue <int, vector<int>, greater<int>> dist[MAX];
priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void Dijkstra() {
	
	pq.push(make_pair(0, 1));
	dist[1].push(0);
	while (!pq.empty()) {
		int cur = pq.top().second;
		int curCost = pq.top().first;
		pq.pop();

		if (curCost > dist[cur].top() && dist[cur].size() != 0) {
			dist[cur].push(curCost);
			continue;
		}

		for (unsigned int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i].first;
			int nextCost = v[cur][i].second;
			if (dist[next].size() == 0) {
				dist[next].push(dist[cur].top() + nextCost);
				pq.push(make_pair(dist[next].top(), next));
			}
			else if (dist[next].top() > dist[cur].top() + nextCost) {
				dist[next].push(dist[cur].top() + nextCost);
				pq.push(make_pair(dist[next].top(), next));
			}
			else
				dist[next].push(dist[cur].top() + nextCost);
		}
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
// 
// error case 2
// 방식 일부 변경
// 해당 dist vector에 가능한 경로 값들을 모두 넣을 것이 아니라 ( 모두 넣으면 메모리 초과 발생 )
// dist vector 를 min heap이 아닌 max heap 으로 priority queue 선언해주어 작은 값 경로 우선 순으로 딱 k개 만큼 넣어준다.
// if (dist[next].size() < k) ,
// else if (dist[next].top() > curCost + nextCost) 사용!
//
// 그러나 까먹고 이거 안바꿔줘서 틀림
// pq.push(make_pair(dist[cur].top() + nextCost, next)); 에서 dist[cur].top() 이 아니라 curCost 사용해야됨
// 왜냐하면 dist[cur].top()은 dist[cur]에서 최단경로의 값이 아닐수도 있기 때문이다. ( max heap을 사용해서 오히려 k개 중 최대 값을 갖는다.)
// curCost는 cur 점 까지의 최단경로 값을 갖기에 이걸 사용해야 된다. 
///////////////////////////////////////////////////////////////////////////////////////////////////////
// 틀린코드
///////////////////////////////////////////////////////////////////////////////////////////////////////
vector <pair<int, int>> v[MAX];
priority_queue <int, vector<int>, less<int>> dist[MAX];
priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int n, m;
unsigned int k;

void Dijkstra() {
	
	pq.push(make_pair(0, 1));
	dist[1].push(0);
	while (!pq.empty()) {
		int cur = pq.top().second;
		int curCost = pq.top().first;
		pq.pop();

		for (unsigned int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i].first;
			int nextCost = v[cur][i].second;
			if (dist[next].size() < k)
				dist[next].push(curCost + nextCost);
			else if (dist[next].top() > curCost + nextCost) {
				dist[next].pop();	
				dist[next].push(curCost + nextCost);
			}
			else
				continue;
			pq.push(make_pair(dist[cur].top() + nextCost, next));
		}
	}
}
///////////////////////////////////////////////////////////////////////////////////////////////////////
