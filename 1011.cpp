// 1011.cpp
// Fly me to the Alpha Centauri

#include<cstdio>

int main() {

	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; t++) {
		int x, y;
		long long dist, n = 1;
		scanf("%d %d", &x, &y);
		dist = y - x;
		while (1) {
			if (dist <= n * n) {
				printf("%lld\n", 2 * n - 1);
				break;
			}
			else if (dist <= n * (n + 1)){
				printf("%lld\n", 2 * n);
				break;
			}
			n++;
		}
	}
	return 0;
}