// 17395.cpp
// 이진수 변환
#include<iostream>

using namespace std;

long long ans[51];

int main() {

	ios::sync_with_stdio(stdin);
	cin.tie(NULL);
	long long x0, tx, t = 1;
	int N, n = 0, i = 1;
	cin >> x0 >> N;
	tx = x0;
	ans[0] = x0;
	while (tx != 0) {
		if(tx%2 == 1)
			n++;
		tx >>= 1;
		t <<= 1;
	}
	t >>= 1;
	if (n < N)
		cout << "-1\n";
	else {
		tx = x0;
		while (i < N && n > 0) {
			if (ans[i-1] > t) {
				ans[i] = ans[i - 1] - t;
				i++;
			}
			tx >>= 1;
			t >>= 1;
		}
		ans[N] = 0;
		for (int i = 1; i <= N; i++)
			cout << ans[i] << " ";
		cout << "\n";
	}
	return 0;
}