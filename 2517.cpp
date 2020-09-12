// 2517.cpp
// 달리기
//
// 세그먼트 트리의 다양한 활용
// 
// 1. 입력받은 능력치에 대한 오름차순으로 순위를 매긴다. (lower_bound 를 이용)
// 2. 세그먼트 트리에 입력된 값을 이용하여 자기 앞에 자신보다 능력치가 높은 사람이 몇 명이 있는지 구한다. ( getCnt 함수 )
// 3. 입력받은 순서대로 세그먼트 트리에 1을 update 한다. ( update(r, 1) )
//
// 예시
// 8
// 2 8 10 7 1 9 4 15 
// 가 입력된 경우
//
// 2 8 10 까지는 아래와 같이 세그먼트 트리에 입력이 되고 getCnt에서 반환하는 값은 1이 된다. (세그먼트 트리에서 가져오는 값은 0이므로)
//
//				3
//			1		2
//		1	       0	      1		1
//	     0               1        0      0    1      0        1     		0
//
// 7 에서는 다음과 같이 가져온다. 
//
//				3
//			1		2
//		1	       0	      1		1
//	     0               1        0      0    1      0        1     		0
//		 	           ↑				↑
// 7이 순위가 4등이므로	          4등부터			8등까지의 항목들을 모두 더한다. 
// 즉, 2명이 7보다 능력치가 좋은 앞에서 뛰는 사람들이라 할 수 있다.
//
// 이와 같은 방식으로 반복한다.
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
		for (int i = n; i < half; i++)
			item[i + half] = 0;
		for (int i = half - 1; i > 0; i--)
			item[i] = item[i * 2] + item[i * 2 + 1];
	}
	void clear() {
		for (int i = 0; i < half * 2; i++)
			item[i] = 0;
	}
} tree;


int getCnt(int l, int r) {
	int res = 0;
	l += tree.half;	r += tree.half;
	while (l <= r) {
		if (l % 2)
			res += tree.item[l++];
		if (!(r % 2))
			res = tree.item[r--];
		l >>= 1;	r >>= 1;
	}
	return res;
}

void update(int idx, int x) {
	idx = idx + tree.half;
	tree.item[idx] = x;
	idx >>= 1;
	while (idx) {
		tree.item[idx] = tree.item[idx * 2] + tree.item[idx * 2 + 1];
		idx >>= 1;
	}
}

int a[500001], b[500001];

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	tree = seg(N);
	for (int i = 0; i < N; i++) {
		cin >> a[i];
		b[i] = a[i];
	}
	sort(b, b + N);
	for (int i = 0; i < N; i++) {
		int r = lower_bound(b, b + N, a[i]) - b;
		cout << getCnt(r, tree.half - 1) + 1 << "\n";
		update(r, 1);
	}
	return 0;
}