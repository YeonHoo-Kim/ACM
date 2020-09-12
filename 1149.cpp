// 1149.cpp
// RGB거리
// dp[i][j] = i번째집을 j색으로 칠할때의 최솟값?
// dp[i][0] = min(dp[i-1][1],dp[i-1][2]) + price[i][0];

#include<iostream>
#include<algorithm>

using namespace std;

const int MAX = 1001;
const int INF = 1000000000;
int price[MAX][3];
int dp[MAX][3];
int main() {

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> price[i][0] >> price[i][1] >> price[i][2];
	dp[0][0] = price[0][0];	dp[0][1] = price[0][1];	dp[0][2] = price[0][2];
	for (int i = 1; i < n; i++) {
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + price[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + price[i][1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + price[i][2];
	}
	cout << min(dp[n - 1][0], dp[n - 1][1] > dp[n - 1][2] ? dp[n - 1][2] : dp[n - 1][1]) << "\n";
	return 0;
}