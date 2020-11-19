#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool comp(string s1, string s2) {
	if (s1.size() == s2.size()) {
		return s1 < s2;
	}
	else {
		return s1.size() < s2.size();
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	string tmp;
	vector<string> s;
	cin >> n;

	while (n--) {
		cin >> tmp;
		s.push_back(tmp);
	}
	sort(s.begin(), s.end(), comp);

	n = s.size();

	cout << s[0] << "\n";
	for (int i = 1; i < n; i++) {
		if (s[i - 1] != s[i]) {
			cout << s[i] << "\n";
		}
	}

	return 0;
}