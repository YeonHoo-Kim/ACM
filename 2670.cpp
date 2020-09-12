// 2670.cpp
// 연속부분최대곱

#include<iostream>
#include<algorithm>

using namespace std;
double dp[10001][2];
int main() {

	ios::sync_with_stdio(stdin);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		double a;
		cin >> a;
		if (i == 1)
			dp[i][0] = a;
		else {
			dp[i][0] = max(dp[i - 1][0] * a, a);
			dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]);
		}
	}
	printf("%.3lf\n", max(dp[n][0],dp[n][1]));
	return 0;
}