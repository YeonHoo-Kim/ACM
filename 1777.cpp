// 1777.cpp
// 순열복원
//
// 먼저 1849번 순열 문제를 풀어보고 오면 이 문제도 풀 수 있음
// 설명은 생략한다.

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


int getIdx(int node, int ns, int ne, int val) {
	if (ns == ne)
		return node - tree.half;
	else {
		int mid = (ns + ne) / 2;
		if (tree.item[node * 2 + 1] >= val)
			return getIdx(node * 2 + 1, mid + 1, ne, val);
		else
			return getIdx(node * 2, ns, mid, val - tree.item[node * 2 + 1]);
	}
}

void update(int node, int ns, int ne, int idx, int x) {
	if (ns == ne)
		tree.item[node] = x;
	else {
		int mid = (ns + ne) / 2;
		if (idx <= mid)
			update(node * 2, ns, mid, idx, x);
		else
			update(node * 2 + 1, mid + 1, ne, idx, x);
		tree.item[node] = tree.item[node * 2] + tree.item[node * 2 + 1];
	}
}

int a[100001], b[100001];

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	vector<int> tmp;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> a[i];
		tmp.push_back(1);
	}
	tree = seg(N);
	tree.init(tmp);

	for (int i = N; i >= 1; i--) {
		int idx = getIdx(1, 1, tree.half, a[i] + 1);
		b[idx] = i;
		update(1, 1, tree.half, idx + 1, 0);
	}

	for (int i = 0; i < N; i++)
		cout << b[i] << " ";
	return 0;
}