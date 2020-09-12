// 2775.cpp
// 부녀회장이 될테야

#include<cstdio>

int num[15][15] = { 0 };
int main() {

	int T, sum;
	scanf("%d", &T);
	for (int i = 1; i <= 14; i++)
		num[0][i] = i;
	for (int i = 1; i <= 14; i++) {
		sum = 0;
		for (int j = 1; j <= 14; j++) {
			sum += num[i - 1][j];
			num[i][j] = sum;
		}
	}
	for (int t = 0; t < T; t++) {
		int k, n;
		scanf("%d %d", &k, &n);
		printf("%d\n", num[k][n]);
	}
	return 0;
}