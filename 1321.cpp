// 1321.cpp
// 군인
//
// 1849번, 1777번, 2243번을 풀었으면 당연히 풀 수 있는 문제
//
// 세그먼트 트리의 leaf 노드에 각 부대의 인원수를 넣고 세그먼트 트리에서는 부분합을 구현해두면 쉽게 풀 수 있는 문제다.

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
		if (tree.item[node * 2] >= val)
			return getIdx(node * 2, ns, mid, val);
		else
			return getIdx(node * 2 + 1, mid + 1, ne, val - tree.item[node * 2]);
	}
}

void update(int node, int ns, int ne, int idx, int x) {
	if (ns == ne)
		tree.item[node] += x;
	else {
		int mid = (ns + ne) / 2;
		if (idx <= mid)
			update(node * 2, ns, mid, idx, x);
		else
			update(node * 2 + 1, mid + 1, ne, idx, x);
		tree.item[node] = tree.item[node * 2] + tree.item[node * 2 + 1];
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, M, a, b, c, idx;
	vector<int> num;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a;
		num.push_back(a);
	}
	tree = seg(N);
	tree.init(num);

	cin >> M;
	while (M--) {
		cin >> a;
		if (a == 1) {
			cin >> b >> c;
			update(1, 1, tree.half, b, c);
		}
		else {
			cin >> b;
			idx = getIdx(1, 1, tree.half, b) + 1;
			cout << idx << "\n";
		}
	}
	return 0;
}