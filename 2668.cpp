// 2668.cpp
// 숫자고르기

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
vector<int> num[101], ans;
bool visit[101];
void dfs(int s, int cur) {
	int next = num[cur][0];
	if (visit[s] && s == next)
		ans.push_back(s);
	else if (!visit[next]) {
		visit[cur] = true;
		dfs(s, next);
	}
}

int main() {

	ios::sync_with_stdio(stdin);
	cin.tie(0);
	int n, res = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		num[i].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		for (int i = 1; i <= n; i++)
			visit[i] = false;
		dfs(i, i);
	}
	cout << ans.size() << "\n";
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << "\n";
	return 0;
}


