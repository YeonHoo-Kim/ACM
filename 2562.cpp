#include<cstdio>

int main() {

	int maxi = 0, cur, num;
	for (int i = 1; i <= 9; i++) {
		scanf("%d", &num);
		if (num > maxi) {
			maxi = num;
			cur = i;
		}
	}
	printf("%d\n%d\n", maxi, cur);
	return 0;
}