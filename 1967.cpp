// 1967.cpp
// 트리의 지름
//
// 트리의 지름이란? 트리에서 임의의 두 점 사이의 거리가 가장 긴 것을 의미한다. 
// 트리의 지름을 구하기 이전에 트리의 중요한 특징 중 하나인 "임의의 두 점 간의 경로는 오직 하나만 존재"함을 강조한다.
// 구하는 방법은 간단하게 dfs 두번 쓰면 된다.
// 원리를 설명하자면 2단계로 나뉜다.
// 1. 아무 점(1) 이나 하나 잡아서 이 점으로 부터 제일 멀리 떨어진 점 x를 구한다.
// 2. x로 부터 제일 멀리 떨어진 점 y를 구하여 x~y의 거리를 구한다. => 이 거리가 지름이 된다.
//
// 2번의 논리 "x~y가 지름이다" 에 대한 반례로 생각해볼 만한 것은 다음의 경우들이 있다.
// 1> x~y보다 거리가 긴 지점 x~b가 존재한다.
// 2> x~y보다 거리가 긴 지점 a~y가 존재한다.
// 3> x~y보다 거리가 긴 지점 a~b가 존재한다.
//
// 1> 의 경우 2번에서 x로 부터 제일 멀리 떨어진 점 y라 했기 때문에 x~b가 x~y보다 길 수 없다. ( 1> 불가능 )
// 2> 의 경우 다음의 그림을 보자. ( A~E 는 점들 사이의 거리를 표현하였다. )
//		 1
// 		 | (A)	        (E)
//	y ---------ㅁ--------ㅁ-------------- x
//	      (B)	      (C)	|(D)
//			a
// 거리들은 다음과 같다.	a~y : B+C+D	x~y : B+C+E	1~x : A+E		1~a : A+C+D	
// 1번에 의해 1~x > 1~a 이므로 E>C+D가 되어야 한다.
// 2> 이 맞다면 a~y > x~y 이므로 D>E 가 되어야 한다.
// 이 때 A~E는 거리 값들이므로 모두 양수이므로 E>C+D, D>E가 동시에 만족할 수 없다.
// 따라서 a~y > x~y 일 수 없다. (2> 불가능)
//
// 3> 의 경우도 다음의 그림을 보자. ( A~G 는 점들 사이의 거리를 표현하였다. )
//		             1
// 		             | (A)
//	y ----------ㅁ------ㅁ--------ㅁ-------------- x
//	       (B)  (F)|    (C)       (D)    |(G)     (E)
//		 a	           b
// 거리들은 다음과 같다. 1~x : A+D+E	1~b : A+D+G	x~y : B+C+D+E	x~a : F+C+D+E	a~b : F+C+D+G
// 1번에 의해 1~x > 1~b 이므로 E>G 이다.
// 2번에 의해 x~y > x~a 이므로 B>F 이다.
// 3> 이 맞다면 a~b > x~y 이므로 F+G>B+E 이다.
// 이 때, E>G, B>F 인데 F+G>B+E가 될 수 없으므로 불가능하다. (3> 불가능)
//
// 따라서 x~y가 트리의 지름임을 증명하였다.
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include<iostream>
#include<vector>

using namespace std;

const int MAX = 100001;
vector<pair<int, int>>v[MAX];
int ans = 0, x;

void find(int cur, int pre, int w) {
	if (ans < w) {
		ans = w;
		x = cur;
	}
	for (unsigned int i = 0; i < v[cur].size(); i++)
		if (v[cur][i].first != pre)
			find(v[cur][i].first, cur, w + v[cur][i].second);
}

int main() {

	int V;
	cin >> V;
	for (int i = 0; i < V - 1; i++) {
		int vCur, vNext, vVal;
		cin >> vCur >> vNext >> vVal;
		v[vCur].push_back({ vNext, vVal });
		v[vNext].push_back({ vCur, vVal });
	}
	find(1, 0, 0);
	ans = 0;
	find(x, 0, 0);
	cout << ans;
	return 0;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////