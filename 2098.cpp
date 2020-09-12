// 2098.cpp
// 외판원 순회 (TSP 문제)
// 참고	: http://blog.naver.com/PostView.nhn?blogId=kks227&logNo=220557403491
// 	: https://www.acmicpc.net/source/share/2f030234c482465b86f80589c94cb50f (by. raararaara) 
//
// 사실상 참고를 보고 이해하면서 코드를 짜서 코드가 거의 같다. (dp문제라서...)
// 이 문제에서 이동이 안되는 경우나 초기화를 대부분 10억 이상의 값으로 처리한다. 이유는 최솟값을 찾는 문제기 때문이다.
//
// cost[i][j] : i 도시에서 j 도시로 가는데 필요한 비용을 입력에서 받아온다. (이 때 입력이 0이면, 10억으로 처리하였다. 이동이 안되는 것으로 처리함)
// dist[vis][cur] : vis는 현재까지 거쳐온 도시를 bitwise로 표현한 수이고, cur은 거쳐온 도시 중 가장 마지막(최근) 도시의 번호를 갖는다. 
// vis 는 int형 변수로 처리하여 다음의 위치별로 거쳐온 도시 번호의 위치에 1을, 거치지 않은 도시는 0을 표시하였다.
//          16      15      14     13      12      11      10       9       8       7        6       5       4        3       2       1 
//      ┌──┬──┬──┬──┬──┬──┬──┬──┬──┬──┬──┬──┬──┬──┬──┬──┐
//      │      │      │      │      │      │      │      │      │      │      │      │      │      │      │      │      │     =     vis
//      └──┴──┴──┴──┴──┴──┴──┴──┴──┴──┴──┴──┴──┴──┴──┴──┘
// 예를 들어 vis = 7 은 1, 2, 3 도시를 거쳐왔다 할 수 있다.
//
// 이제 distance 함수의 구성을 분석해보자.
// 이 함수는 vis 와 cur을 매개변수로 받아온다.
// 먼저 vis == 1<<N - 1 인 경우는 바로 cost[cur][0]을 return 해준다.
// 의미는 vis == 1<<N - 1 인 경우는 모든 도시를 전부 돈 경우다. (vis 의 2진수 표현이 전부 1로 구성되므로)
// 이 때 모든 도시를 전부 돈 경우에서 제일 마지막으로 거친 도시가 cur 번호에 해당하므로 
// 우리는 시작을 1번도시 (코드에서는 0번) 에서 했기에 ( 처음 호출 시 distance(1,0) 로 호출 )
// cur 번호의 도시에서 시작도시( 0번 ) 으로 돌아가는 비용인 cost[cur][0] 값을 return 해줘야 한다.
//
// 그 다음으로 우리가 distance(vis, cur) 함수를 호출할 때 원하는 값이 무엇인지 생각해보자. => 당연 dist[vis][cur] 값이다.
// 여기서 이 값이 정해져 있다면 그냥 가져다 쓰면 되므로 dist[vis][cur]값을 return 시키면 된다.
// 
// 그러나 값이 정해지지 않은 경우 ( dist[vis][cur] = -1 일 때 ) 최솟값을 구해야 한다. 이는 for문을 이용한다.
// 도시의 종류는 16가지 이므로 그 다음으로 갈 도시는 16곳 중 한 곳이다.
// 이 때 제외해야 될 도시는 여태 거쳐온 도시이고, 이를 vis를 이용하여 구분할 수 있다.
// vis & (1 << next) != 0 인 경우 겹치는 도시가 있다는 의미 이므로 ( & 연산 시 0이 되어야 겹치는 도시가 없는 것! )
// if문을 이용하여 continue로 걸러낸다.
// 거쳐온 도시는 걸러내고, 거치지 않은 도시는 다시 distance(vis & (1 << next), next) + cost[cur][next] 를 이용하여
// distance 함수를 호출하여 그 다음 도시는 어디로 갈지 구분 및 최솟값을 계산하고,
// cost[cur][next]를 이용하여 일단 ( 현재 도시 ~ 다음으로 가는 도시 ) 의 비용을 더해준다.
//
// Tip...	 if (int(vis & (1 << next)) != 0)
// 이 부분 int형으로 형변환 안해주면 백준온라인 채점 시 틀린다. ( if (vis & (1 << next)) 는 된다. 뭐지... 얘는 자동 형변환 됨... )
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

int cost[17][17];
int dist[1 << 17][16];
int N;
const int INF = 1e9 + 1;

int distance(int vis, int cur) {
	if (vis == (1 << N) - 1)
		return cost[cur][0];

	int &ret = dist[vis][cur];
	if (ret != -1)
		return ret;

	ret = INF;

	for (int next = 0; next < 16; next++) {
		if (int(vis & (1 << next)) != 0)
			continue;
		ret = min(ret, distance(vis | (1 << next), next) + cost[cur][next]);
	}
	return ret;
}

int main() {

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &cost[i][j]);
			if (cost[i][j] == 0)
				cost[i][j] = INF;
		}
	}
	
	memset(dist, -1, sizeof(dist));
	printf("%d\n", distance(1, 0));

	return 0;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////