// 2243.cpp
// 사탕상자
//
// 1849번 순열과 1777번 순열복원을 풀어봤다면 바로 풀 수 있는 문제
//
// 세그먼트 트리에 각 맛 레벨 (1~1,000,000) 에 해당되는 사탕의 개수를 1,000,000개의 leaf 노드에 저장한다.
// 세그먼트 트리에서는 각 leaf 노드들의 부분합을 구현해두고 top-down 기법으로 공간을 확보하여 idx를 구하고 
// update 또한 같은 방법으로 해주면 된다. (방식은 위의 1849번, 1777번 을 참고한다.)

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
};

int taste = 1e6;
seg tree(taste);

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

	int n, A, B, C, idx;
	cin >> n;
	while (n--) {
		cin >> A;
		if (A == 1) {
			cin >> B;
			idx = getIdx(1, 1, tree.half, B) + 1;
			cout << idx <<"\n";
			update(1, 1, tree.half, idx, -1);
		}
		else {
			cin >> B >> C;
			update(1, 1, tree.half, B, C);
		}
	}
	return 0;
}