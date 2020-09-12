// 2533.cpp
// 사회망 서비스(SNS)
// 참고 : https://raararaara.blog.me/
// 
// early adapter 이면 1, 아니면 0으로 표현하자.
// tree 구조로 할 때는 parent node가 child node에게 다음과 같은 방식으로 영향을 준다.
// 1. parent node가 0인 경우 child node 는 반드시 1이다.
// 2. parent node가 1인 경우 child node 는 0, 1 둘 다 가능하다.
// 문제에서는 최소 early adapter 수를 찾기에 위의 2번을 다음과 같이 바꾼다.
// 2 : parent node가 1인 경우 child node 는 0, 1 중 early adapter가 최소인 경우로 고른다.
// 
// 위와 같은 규칙이 있기에 dp를 꺼내고 다음과 같은 규칙을 정해주자.
// dp[i][0] : i번째 노드가 0일 때, i를 root로 하는 subtree들의 최소 early adapter 수
// dp[i][1] : i번째 노드가 1일 때, i를 root로 하는 subtree들의 최소 early adapter 수
// (서브트리에서 노드가 1개인 경우 : dp[i][0] = 0, dp[i][1] = 1이 된다. (그냥 early adapter 수를 적으면 됨))
// dp는 DFS를 이용하여 구해나간다. (코드 참고)
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
const int MAX = 1000001;
vector<int> tree[MAX];
int dp[MAX][2];

void find(int cur, int pre) {
	dp[cur][0] = 0;
	dp[cur][1] = 1;
	for (unsigned int i = 0; i < tree[cur].size(); i++) {
		int next = tree[cur][i];
		if (next != pre) {
			find(next, cur);
			dp[cur][0] += dp[next][1];
			dp[cur][1] += min(dp[next][0], dp[next][1]);
		}
	}
}

int main() {

	int N;
	cin >> N;
	for (int i = 1; i < N; i++) {
		int a, b;
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	find(1, 0);
	printf("%d\n", min(dp[1][0], dp[1][1]));
	return 0;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////