#include<cstdio>

int left[42] = { 0 };

int main() {

	int num, cnt = 0;
	for (int i = 0; i < 10; i++) {
		scanf("%d", &num);
		left[num % 42]++;
	}
	for (int i = 0; i < 42; i++)
		if (left[i] > 0)
			cnt++;
	printf("%d\n", cnt);
	return 0;
}