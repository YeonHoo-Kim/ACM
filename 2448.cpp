// 2448번

// 출력하는 삼각형을 3부분으로 나누어서 재귀를 이용한 출력 (위, 왼, 오른)
// 윗 삼각형의 제일 윗부분을 기준으로 시작하여 아래로 점점 그려나간다

#include<cstdio>

char star[3072][6144];

void triangle(int n, int x, int y) {

	if (n == 3) {
		star[y][x] = '*';
		star[y + 1][x - 1] = '*';
		star[y + 1][x + 1] = '*';
		star[y + 2][x - 2] = '*';
		star[y + 2][x - 1] = '*';
		star[y + 2][x] = '*';
		star[y + 2][x + 1] = '*';
		star[y + 2][x + 2] = '*';
		return;
	}
	triangle(n / 2, x, y);
	triangle(n / 2, x - (n / 2), y + (n / 2));
	triangle(n / 2, x + (n / 2), y + (n / 2));
}

int main() {

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < 2 * n; j++)
			if (j == 2 * n - 1)
				star[i][j] = '\0';
			else
				star[i][j] = ' ';

	triangle(n, n - 1, 0);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2 * n - 1; j++)
			printf("%c", star[i][j]);
		printf("\n");
	}
	return 0;

	return 0;

}