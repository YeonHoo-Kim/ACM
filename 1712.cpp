// 1712.cpp
// 손익분기점

#include<cstdio>

int main() {

	int A, B, C, num = 1, dif;
	scanf("%d %d %d", &A, &B, &C);
	dif = A + (B - C);
	if (B >= C) {
		printf("-1\n");
		return 0;
	}
	num = A / (C - B) + 1;
	printf("%d\n", num);
	return 0;
}