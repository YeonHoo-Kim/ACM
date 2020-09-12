// 2042.cpp
// 구간 합 구하기
//
// 세그먼트 트리의 개념을 이해했다면 바로 풀 수 있는 문제

#include<iostream>
#include<vector>
using ll = long long;
using namespace std;

struct seg {
	int n, half;
	vector<ll> item;
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

void update(int idx, ll x) {
	idx = idx + tree.half - 1;
	tree.item[idx] = x;
	idx >>= 1;
	while (idx) {
		tree.item[idx] = tree.item[idx * 2] + tree.item[idx * 2 + 1];
		idx >>= 1;
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, M, K;
	vector<int> input;

	cin >> N >> M >> K;

	input.resize(N);
	tree = seg(N);

	for (int i = 0; i < N; i++)
		cin >> input[i];

	tree.init(input);

	for (int i = 0; i < M + K; i++) {
		int a, b;
		ll c;
		cin >> a >> b >> c;
		if (a == 1)
			update(b, c);
		else
			cout << sum(b, c) << "\n";
	}

	return 0;
}