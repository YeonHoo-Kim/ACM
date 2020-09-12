// 17399.cpp
// 트리의 외심

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int MAX = 100005;
const int LOGMAX = 18;
vector<int> tree[MAX];
int par[MAX][LOGMAX] = { 0 };
int dep[MAX];

void dfs(int cur, int pre, int depth) {
	int n = 1, t = depth;
	dep[cur] = depth;
	par[cur][0] = pre;
	while (t > 1) {
		par[cur][n] = par[par[cur][n - 1]][n - 1];
		t >>= 1;
		n++;
	}
	for (unsigned int i = 0; i < tree[cur].size(); i++) {
		int next = tree[cur][i];
		if (next != pre)
			dfs(next, cur, depth + 1);
	}
}

int LCA(int a, int b) {
	int n, idx = 0, lca, res = a;
	if (dep[a] != dep[b]) {				// one side pull up
		if (dep[b] > dep[a]) {
			res = a;
			a = b;
			b = res;
		}
		n = dep[a] - dep[b];
		res = a;
		while (n != 0) {
			if (n % 2 == 1)
				res = par[res][idx];
			idx++;
			n >>= 1;
		}
	}
	if (res == b)						// each side pull up
		lca = res;
	else {
		idx = LOGMAX - 1;
		n = b;
		while (idx >= 0) {
			if (par[res][idx] != par[n][idx]) {
				res = par[res][idx];
				n = par[n][idx];
			}
			idx--;
		}
		lca = par[res][0];
	}
	return lca;
}

int getMid(int lca, int a, int b) {
	int n, res, idx = 0;
	n = (dep[a] - dep[lca] + dep[b] - dep[lca]) / 2;
	res = dep[a] > dep[b] ? a : b;
	idx = 0;
	while (n != 0) {
		if (n % 2 == 1)
			res = par[res][idx];
		idx++;
		n >>= 1;
	}
	return res;
}

bool isDistsame(int t, int a, int b, int c) {
	int distAB, distC, lca;
	if ((dep[a] + dep[b] - 2 * dep[t]) % 2 == 1)
		return false;
	distAB = (dep[a] + dep[b] - 2 * dep[t]) / 2;
	t = getMid(t, a, b);
	lca = LCA(t, c);
	distC = dep[t] + dep[c] - 2 * dep[lca];
	if (distAB == distC)
		return true;
	else
		return false;
}

int main() {

	ios::sync_with_stdio(false);
	//freopen("Input.txt", "r", stdin);
	cin.tie(NULL);
	int N, Q;
	cin >> N;
	N--;
	while (N--) {
		int a, b;
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	cin >> Q;
	dfs(1, 0, 0);
	while (Q--) {
		int A, B, C, t;
		cin >> A >> B >> C;
		t = LCA(A, B);
		if (isDistsame(t, A, B, C)) {
			t = getMid(t, A, B);
			cout << t << "\n";
			continue;
		}
		t = LCA(B, C);
		if (isDistsame(t, B, C, A)) {
			t = getMid(t, B, C);
			cout << t << "\n";
			continue;
		}
		t = LCA(A, C);
		if (isDistsame(t, A, C, B)) {
			t = getMid(t, A, C);
			cout << t << "\n";
			continue;
		}
		cout << "-1\n";
	}
	return 0;
}