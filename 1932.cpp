// 1932.cpp
// 정수 삼각형

#include<iostream>
#include<algorithm>

using namespace std;

const int MAX = 501;
int tri[MAX][MAX];
int dp[MAX][MAX];

int main() {
	int n, res;
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j <= i; j++)
			cin >> tri[i][j];
	dp[0][0] = tri[0][0];
	for (int i = 1; i < n; i++) {
		dp[i][0] = dp[i - 1][0] + tri[i][0];
		for (int j = 1; j < i; j++) {
			dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + tri[i][j];
		}
		dp[i][i] = dp[i - 1][i - 1] + tri[i][i];
	}
	res = dp[n - 1][0];
	for (int i = 1; i < n; i++)
		res = max(res, dp[n - 1][i]);
	cout << res << "\n";
	return 0;
}