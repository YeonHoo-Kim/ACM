// 4948.cpp
// 베르트랑 공준

#include<iostream>
#include<cmath>

using namespace std;

int main() {

	while (1) {
		int n, cnt = 0;
		scanf("%d", &n);
		if (n == 0)
			break;
		for (int i = n + 1; i <= 2 * n; i++) {
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
				cnt++;
		}
		printf("%d\n", cnt);
	}
	return 0;
}