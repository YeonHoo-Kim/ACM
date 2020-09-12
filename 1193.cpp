// 1193.cpp
// 분수찾기

#include<cstdio>

int main() {

	int X, n = 1, dif;
	scanf("%d", &X);
	while (1) {
		if (X <= n * (n + 1) / 2) {
			dif = n * (n + 1) / 2 - X;
			break;
		}
		n++;
	}
	if (n % 2 == 1)
		printf("%d/%d\n", dif + 1, n - dif);
	else
		printf("%d/%d\n", n - dif, dif + 1);
	return 0;
}