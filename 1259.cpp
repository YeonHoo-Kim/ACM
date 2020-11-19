#include <iostream>
#include <string>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	while (1) {
		string s;
		int n;
		cin >> s;
		if (s == "0") {
			break;
		}
		n = s.size();
		if (n == 1) {
			cout << "yes\n";
			continue;
		}
		for (int i = 0; i < n / 2; i++) {
			if (s.at(i) != s.at(n - 1 - i)) {
				cout << "no\n";
				break;
			}
			else if (i == n / 2 - 1) {
				cout << "yes\n";
			}
		}
	}

	return 0;
}