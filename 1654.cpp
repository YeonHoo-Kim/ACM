// 1654 랜선자르기
// 이분탐색 문제
//
// 정답 값을 좀 잘 받아와야 에러가 안생긴다...

#include <iostream>
#include <vector>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int K, N, max = 0;
	long long sum = 0, l = 1, r, m, ans;
	vector<int> lines;
	cin >> K >> N;
	while (K--) {
		int t;
		cin >> t;
		lines.push_back(t);
		sum +=(long long)t;
	}

	r = sum / (long long)N;
	while (l <= r) {
		m = (l + r) / 2;
		sum = 0;
		for (int i = 0; i < lines.size(); i++) {
			sum += (lines[i] / m);
		}
		if (sum >= (long long)N) {
			ans = m;
			l = m + 1;
		}
		else {
			r = m - 1;
		}
	}
	cout << ans << "\n";
	return 0;
}