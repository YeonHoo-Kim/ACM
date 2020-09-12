// 1102번
// 발전소
//
// 2098번과 방식이 매우 흡사하다. ( dp를 이용하는 문제 )
// 
// cost[i][j] : 입력에서 받아오는 값들로 i 발전소를 가동하여 j 발전소를 고칠 때 (킬 때) 드는 비용을 저장한다.
// N : 발전소의 개수를 입력에서 받아온다.
// least : 적어도 몇 개의 발전소가 켜져야 되는지 입력에서 받아온다.
// cnt : 현재의 상태에서 발전소가 몇 개 켜져있는지를 갖는다.
// state : 어느 발전소들이 켜져있는지 저장한다. ( bitwise 방식을 이용 )
//          16      15      14     13      12      11      10       9       8       7        6       5       4        3       2       1 
//      ┌──┬──┬──┬──┬──┬──┬──┬──┬──┬──┬──┬──┬──┬──┬──┬──┐
//      │      │      │      │      │      │      │      │      │      │      │      │      │      │      │      │      │     =     state
//      └──┴──┴──┴──┴──┴──┴──┴──┴──┴──┴──┴──┴──┴──┴──┴──┘ 
// dp[state] : state를 기준으로 이 state 만큼 발전소가 켜지기 까지 들어가는 최소 비용 값을 저장한다.
// 
// 최소한의 비용을 계산하기 위하여 settings 함수를 구성하였고, 재귀를 이용하였다.
// settings(state) 호출 시 
// 먼저 return 해줄 값 ret에 대해서 다음과 같은 조건을 적용한다.
//
// int &ret = dp[state] 를 하여 
// ret 값에 dp[state] 값을 불러오고, ret값 변경 시 dp[state]에 적용이 되도록 한다.
// 
// cnt == least
// 문제에서 요구하는 최소한의 가동하는 발전소 개수를 만족했을 때, 0을 return 해준다. (더 이상 더할 비용이 없기에)
// 
// ret != -1
// ret 값 즉, dp[state] 값이 -1이 아닌 경우는 이미 이전에 계산을 한번 해 놓았다는 뜻으로 다시 계산할 필요가 없다.
// 따라서 그냥 dp[state] 값을 갖는 ret를 다시 return 해주면 된다. ( 사실상 이 방식으로 어마무시한 시간복잡도를 줄여준다. )
// 
// ret = INF 와 for문
// ret값이 -1인 경우에는 dp[state] 값이 한번도 구해진 적이 없다는 의미로 이번에 계산해줘야 한다.
// 이 계산은 이중 for문으로 계산해주는데 
// 먼저 어느 발전소를 킬지 state를 이용하여 켜지지 않은 발전소를 구분해 내고, 켜야 할 발전소를 고르면 ( next )
// 켜져 있는 발전소들 ( on ) 을 for문으로 이용하여 next를 한번씩 다 켜보고 그 중 비용이 최소인 것을 ret에 넣는다.
// 
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int cost[16][16];
int dp[1 << 17];
int N, least, cnt = 0;
const int INF = 1e9 + 7;


int settings(int state) {
	
	int &ret = dp[state];

	if (cnt == least)
		return 0;

	if (ret != -1)
		return ret;
	
	ret = INF;

	for (int next = 0; next < N; next++) {
		if (state & (1 << next))
			continue;
		for (int on = 0; on < N; on++) {
			if (state & (1 << on)) {
				cnt++;
				ret = min(ret, settings(state | (1 << next)) + cost[on][next]);
				cnt--;
			}
		}
	}
	return ret;
}

int main() {

	int state = 0, res;
	char c;
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%d", &cost[i][j]);
	
	fgetc(stdin);

	for (int i = 0; i < N; i++) {
		scanf("%c", &c);
		if (c == 'Y') {
			state |= (1 << i);
			cnt++;
		}
	}

	scanf("%d", &least);

	if (cnt >= least)
		printf("0\n");
	else {
		memset(dp, -1, sizeof(dp));

		res = settings(state);

		if (res == INF)
			printf("-1\n");
		else
			printf("%d\n", res);
	}

	return 0;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////