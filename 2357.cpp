// 2357.cpp
// 최솟값과 최댓값
//
// 그냥 귀찮아서 segtree 두종류 (최대, 최소) 만들어서 각각을 item에 저장하도록 함, 이후엔 segtree 방식대로 가져오면 됨

#include<iostream>
#include<algorithm>
#include<vector>
using ll = long long;
using namespace std;

struct segMin {
	int n, half;
	vector<int> item;
	segMin(int n = 0) :n(n) {
		for (half = 1; half < n; half <<= 1);
		item.resize(half * 2);
	}
	void init(vector<int>& arr) {
		for (int i = 0; i < n; i++)
			item[i + half] = arr[i];
		for (int i = n; i < half; i++)
			item[i + half] = 1e9 + 1;
		for (int i = half - 1; i >= 0; i--)
			item[i] = min(item[i * 2], item[i * 2 + 1]);
	}
} mintree;

struct segMax {
	int n, half;
	vector<int> item;
	segMax(int n = 0) :n(n) {
		for (half = 1; half < n; half <<= 1);
		item.resize(half * 2);
	}
	void init(vector<int>& arr) {
		for (int i = 0; i < n; i++)
			item[i + half] = arr[i];
		for (int i = n; i < half; i++)
			item[i + half] = 0;
		for (int i = half - 1; i >= 0; i--)
			item[i] = max(item[i * 2], item[i * 2 + 1]);
	}
} maxtree;

int getMin(int l, int r) {
	int res = 1e9 + 1;
	l += mintree.half;	r += mintree.half;
	while (l <= r) {
		if (l % 2)
			res = min(res, mintree.item[l++]);
		if (!(r % 2))
			res = min(res, mintree.item[r--]);
		l >>= 1;	r >>= 1;
	}
	return res;
}

int getMax(int l, int r) {
	int res = 0;
	l += maxtree.half;	r += maxtree.half;
	while (l <= r) {
		if (l % 2)
			res = max(res, maxtree.item[l++]);
		if (!(r % 2))
			res = max(res, maxtree.item[r--]);
		l >>= 1;	r >>= 1;
	}
	return res;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, M;
	cin >> N >> M;

	mintree = segMin(N);
	maxtree = segMax(N);

	vector<int>num;

	for (int i = 0; i < N; i++) {
		int t;
		cin >> t;
		num.push_back(t);
	}

	mintree.init(num);
	maxtree.init(num);

	while (M--) {
		int a, b;
		cin >> a >> b;
		cout << getMin(a - 1, b - 1) << " " << getMax(a - 1, b - 1) << "\n";
	}
	return 0;
}