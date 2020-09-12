// 2231.cpp
// ºÐÇØÇÕ

#include<cstdio>

int data[1000001];
int main() {

	int N;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		data[i] = i + (i / 1000000) + (i / 100000) % 10 + (i / 10000) % 10 + (i / 1000) % 10 + (i / 100) % 10 + (i / 10) % 10 + i % 10;
		if (data[i] == N) {
			printf("%d\n", i);
			return 0;
		}
	}
	printf("0\n");
	return 0;
}