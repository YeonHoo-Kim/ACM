// 1929.cpp
// 소수 구하기

#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int main() {

	int M, N;
	scanf("%d %d", &M, &N);
	for (int i = M; i <= N; i++) {
		int j, flag = 0;
		if (i == 1)
			continue;
		for (j = 2; j <= sqrt(i); j++) {
			if (i%j == 0) {
				flag = 1;
				break;
			}
		}
		if (flag == 0)
			printf("%d\n", i);
	}
	return 0;
}