// 1615.cpp
// 교차개수세기
//
// Bipartite Graph를 이해해보자. (이분그래프) 왼쪽끼리 or 오른쪽끼리는 연결 x ,  반드시 연결한다면 왼쪽과 오른쪽 연결
// 문제의 난이도 상 교점이 중복된다고 생각하진 않는다.
//
// 문제에있는 예시를 보자
// 5 6
// 1 5
// 2 2
// 3 2
// 4 3
// 5 1
// 5 3
//
// 왼쪽 점을 1부터 차례대로 5까지 볼 때 오른쪽 점이 큰 수 였다가 작은 수가 오면 교점이 특정 조건의 선분 개수만큼 생기는 것을 알 수 있다.
// 따라서 오른쪽 점과 연결 된 점들의 개수를 파악하면 되고, 이를 단계적으로 보면 아래와 같다.
// 		(1,5)	(2,2)	(3,2)	(4,3)	(5,1)	(5,3)
//       오른쪽 점
// 	1	0	0	0	0	1	1
// 선분	2	0	1	2	2	2	2
// 개수	3	0	0	0	1	1	2
// 	4	0	0	0	0	0	0
// 	5	1	1	1	1	1	1
// 교점수		0	1	2	3	7	8		따라서 교점은 8개
//
// 위에서 선분개수를 세그먼트 트리의 leaf 노드에 넣어서 계속 update 해주면서 교점 개수를 구하면 된다.

#include<iostream>
#include<vector>
#include<algorithm>
using ll = long long;
using namespace std;

struct seg {
	int n, half;
	vector<int> item;
	seg(int n = 0) :n(n) {
		for (half = 1; half < n; half <<= 1);
		item.resize(half * 2);
	}
	void init(vector<int>& arr) {
		for (int i = 0; i < n; i++)
			item[i + half] = arr[i];
		for (int i = n; i<half; i++)
			item[i + half] = 0;
		for (int i = half - 1; i >= 0; i--)
			item[i] = item[i * 2] + item[i * 2 + 1];
	}
} tree;


ll sum(int l, int r) {
	ll res = 0;
	l += tree.half;	r += tree.half;
	l--;	r--;
	while (l <= r) {
		if (l % 2)
			res += tree.item[l++];
		if (!(r % 2))
			res += tree.item[r--];
		l >>= 1;	r >>= 1;
	}
	return res;
}

void update(int idx) {
	idx = idx + tree.half - 1;
	tree.item[idx]++;
	idx >>= 1;
	while (idx) {
		tree.item[idx] = tree.item[idx * 2] + tree.item[idx * 2 + 1];
		idx >>= 1;
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, M;
	ll ans = 0;
	cin >> N >> M;
	vector<pair<int, int>> input;
	tree = seg(N);
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		input.push_back({ a,b });
	}
	sort(input.begin(), input.end());
	for (int i = 0; i < M; i++) {
		update(input[i].second);
		ans += sum(input[i].second + 1, N);
	}
	cout << ans;
	return 0;
}