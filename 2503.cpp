// 2503.cpp
// 숫자야구
//
// 완전탐색
//
#include <iostream>
#include <string>

using namespace std;

bool validation(string a) {
	int d = a.size();
	for (int i = 0; i < d; i++) {
		if (a[i] == '0') return false;
	}
	for (int i = 0; i < d - 1; i++) {
		for (int j = i + 1; j < d; j++) {
			if (a[i] == a[j]) return false;
		}
	}
	return true;
}

bool cmp(string a, string b, int strike, int ball) {
	int s_cnt = 0, b_cnt = 0;
	for (unsigned i = 0; i < a.size(); i++) {
		for (unsigned j = 0; j < b.size(); j++) {
			if (i == j && a[i] == b[j])
				s_cnt++;
			else if (a[i] == b[j])
				b_cnt++;
		}
	}
	if (strike == s_cnt && ball == b_cnt) return true;
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	bool number[1000] = { false }, first = true;
	int n, num, s, b, ans = 0;
	string num_str;
	string i_str;
	cin >> n;
	while (n--) {
		cin >> num >> s >> b;
		num_str = to_string(num);
		for (int i = 123; i < 1000; i++) {
			i_str = to_string(i);
			if (!validation(i_str)) continue;
			if (first) number[i] = cmp(i_str, num_str, s, b);
			else number[i] = number[i] && cmp(i_str, num_str, s, b);
		}
		first = false;
	}
	for (int i = 123; i < 1000; i++) {
		if (number[i]) ans++;
	}
	cout << ans;
	
	return 0;
}