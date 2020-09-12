#include<cstdio>

int main() {

	int H, M;
	scanf("%d %d", &H, &M);

	if (M >= 45)
		printf("%d %d\n", H, M - 45);
	else {
		if (H > 0)
			printf("%d %d\n", H - 1, M + 15);
		else
			printf("%d %d\n", H + 23, M + 15);
	}
	return 0;
}