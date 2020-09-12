// 7568.cpp
// µ¢Ä¡

#include<cstdio>

int w[51];
int h[51];

int main() {

	int N;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d %d", &w[i], &h[i]);

	for (int i = 1; i <= N; i++) {
		int cnt = 1;
		for (int j = 1; j <= N; j++) {
			if (w[i] < w[j] && h[i] < h[j])
				cnt++;
		}
		printf("%d ", cnt);
	}
	printf("\n");
	return 0;
}