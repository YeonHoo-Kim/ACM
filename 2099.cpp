// 2099.cpp
// The game of death
//
// 단순히 인접행렬을 만들고 n번 건너가는 만큼 행렬을 n제곱 해주면 된다. ( 여기서 n제곱을 시간복잡도 O(logn) 크기로 해주는 게 point ! )

#include<cstdio>

const int MAX = 201;
int mat[MAX][MAX] = { 0 };
int res[MAX][MAX];
int tmp[MAX][MAX];

int main() {

	int N, K, M, cnt = 0, flag = 0;
	scanf("%d %d %d", &N, &K, &M);

	for (int i = 0; i < N; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		mat[i][x - 1] = 1;
		mat[i][y - 1] = 1;
	}
	while (K != 0) {
		if (K % 2 == 1) {
			if (flag == 0) {
				for (int i = 0; i < N; i++)
					for (int j = 0; j < N; j++)
						res[i][j] = mat[i][j];
				flag = 1;
			}
			else {
				for (int i = 0; i < N; i++)
					for (int j = 0; j < N; j++)
						tmp[i][j] = 0;
				for (int i = 0; i < N; i++) {
					for (int j = 0; j < N; j++) {
						for (int k = 0; k < N; k++) {
							if (mat[i][k] * res[k][j] > 0) {
								tmp[i][j] = 1;
								break;
							}
							else
								tmp[i][j] = 0;
						}
					}
				}
				for (int i = 0; i < N; i++)
					for (int j = 0; j < N; j++)
						res[i][j] = tmp[i][j];
			}
		}
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				tmp[i][j] = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				for (int k = 0; k < N; k++) {
					if (mat[i][k] * mat[k][j] > 0) {
						tmp[i][j] = 1;
						break;
					}
					else
						tmp[i][j] = 0;
				}
			}
		}
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				mat[i][j] = tmp[i][j];
		K = K >> 1;
		cnt++;
	}
	for (int i = 0; i < M; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		if (res[a - 1][b - 1] == 1)
			printf("death\n");
		else
			printf("life\n");
	}
	return 0;
}