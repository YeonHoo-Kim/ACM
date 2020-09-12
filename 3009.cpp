// 3009.cpp
// 네 번째 점

#include<cstdio>

int main() {

	int x = 0, y = 0, a, b;
	while (scanf("%d %d", &a, &b) != EOF) {
		x ^= a;	y ^= b;
	}
	printf("%d %d\n", x, y);
	return 0;
}