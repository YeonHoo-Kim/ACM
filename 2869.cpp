// 2869.cpp
// 달팽이는 올라가고 싶다

#include<cstdio>

int main() {

	int A, B, V;
	scanf("%d %d %d", &A, &B, &V);
	printf("%d\n", (V - A) % (A - B) == 0 ? (V - A) / (A - B) + 1 : (V - A) / (A - B) + 2);
	return 0;
}