// 2292.cpp
// ¹úÁý

#include<cstdio>

int main() {
	int N, n = 1;
	scanf("%d", &N);
	while (1) {
		if (N <= 1 + (6 * (n - 1)*n / 2))	// (sum of 1 ~ n-1) * 6
			break;
		n++;
	}
	printf("%d\n", n);
	return 0;
}