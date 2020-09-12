// 2581.cpp
// ¼Ò¼ö

#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int main() {

	int M, N, sum = 0, mini, cnt = 0;
	scanf("%d %d", &M, &N);
	mini = N;
	for (int i = M; i <= N; i++) {
		int j;
		if (i == 1)
			continue;
		for (j = 2; j <= sqrt(i); j++) {
			if (i%j == 0)
				break;
		}
		if (j > sqrt(i)) {
			cnt++;
			sum += i;
			mini = min(mini, i);
		}
	}
	if (cnt > 0)
		printf("%d\n%d\n", sum, mini);
	else
		printf("-1\n");
	return 0;
}