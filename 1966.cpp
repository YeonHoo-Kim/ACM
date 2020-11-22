#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> priorities, int location) {
	int answer = 0;
	int cnt[10] = { 0 }, n = priorities.size(), rank = 0, p = 9;
	queue<pair<int, int>> q;

	for (int i = 0; i < n; i++) {
		q.push({ priorities[i],i });
		cnt[priorities[i]]++;
	}

	while (!q.empty()) {
		if (cnt[p]) {
			if (q.front().first == p) {
				rank++;
				if (q.front().second == location) {
					return rank;
				}
				else {
					cnt[p]--;
					q.pop();
				}
			}
			else {
				q.push({ q.front().first, q.front().second });
				q.pop();
			}
		}
		else {
			p--;
		}
	}
	return -1;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int tc;
	cin >> tc;
	while (tc--) {
		int n, loc;
		vector<int> p;
		cin >> n >> loc;
		while (n--) {
			int t;
			cin >> t;
			p.push_back(t);
		}
		cout << solution(p, loc) << "\n";
	}

	return 0;
}