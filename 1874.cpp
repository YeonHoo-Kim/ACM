#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	vector<int> v;
	vector<char> ans;
	stack<int> s;

	int n, t, i;
	cin >> n;
	for (i = 1; i <= n; i++) {
		cin >> t;
		v.push_back(t);
	}
	
	t = 0;	i = 1;
	s.push(i);
	ans.push_back('+');
	i++;
	while (t < n) {
		if (s.empty() || (s.top() != v[t])) {
			if (i > n) {
				cout << "NO\n";
				return 0;
			}
			s.push(i);
			ans.push_back('+');
			i++;
		}
		else if (s.top() == v[t]) {
			s.pop();
			ans.push_back('-');
			t++;
		}
	}
	
	for (i = 0; i < ans.size(); i++) {
		cout << ans[i] << "\n";
	}

	return 0;
}