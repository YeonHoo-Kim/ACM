#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	vector<int> a, b;
	int n, m, t, l, r;
	cin >> n;
	while (n--) {
		cin >> m;
		a.push_back(m);
	}
	cin >> m;
	while (m--) {
		cin >> n;
		b.push_back(n);
	}

	sort(a.begin(), a.end());
	n = b.size();
	for (int i = 0; i < n; i++) {
		l = 0;	r = a.size() - 1;	t = 0;
		while (l <= r) {
			m = (l + r) / 2;
			if (a[m] > b[i]) {
				r = m - 1;
			}
			if (a[m] < b[i]) {
				l = m + 1;
			}
			if (a[m] == b[i]) {
				t = 1;
				cout << "1\n";
				break;
			}
		}
		if (t == 0) {
			cout << "0\n";
		}
	}

	return 0;
}