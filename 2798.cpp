// 2798.cpp
// ∫Ì∑¢¿Ë
#include<cstdio>
#include<cstdlib>

int card[101];

int main() {
	int N, M, sum, res = -1;
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++)
		scanf("%d", &card[i]);
	for (int i = 1; i <= N; i++) {
		for (int j = i + 1; j <= N; j++) {
			for (int k = j + 1; k <= N; k++) {
				sum = card[i] + card[j] + card[k];
				if (res == -1)
					res = sum;
				if (abs(res - M) > abs(sum - M) && sum <= M)
					res = sum;
			}
		}
	}
	printf("%d\n", res);
	return 0;
}