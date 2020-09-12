// 1018.cpp
// 체스판 다시 칠하기

#include<iostream>
#include<algorithm>

using namespace std;

char board[51][51];
char b1[8][8] = { {'B','W','B','W','B','W','B','W'},
					{'W','B','W','B','W','B','W','B'},
					{'B','W','B','W','B','W','B','W'},
					{'W','B','W','B','W','B','W','B'},
					{'B','W','B','W','B','W','B','W'},
					{'W','B','W','B','W','B','W','B'},
					{'B','W','B','W','B','W','B','W'},
					{'W','B','W','B','W','B','W','B'} };
char b2[8][8] = { {'W','B','W','B','W','B','W','B'},
					{'B','W','B','W','B','W','B','W'},
					{'W','B','W','B','W','B','W','B'},
					{'B','W','B','W','B','W','B','W'},
					{'W','B','W','B','W','B','W','B'},
					{'B','W','B','W','B','W','B','W'},
					{'W','B','W','B','W','B','W','B'},
					{'B','W','B','W','B','W','B','W'} };

int main() {

	int N, M, res = 64;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> board[i][j];

	for (int i = 0; i <= N - 8; i++) {
		for (int j = 0; j <= M - 8; j++) {
			int b1cnt = 0, b2cnt = 0;
			for (int n = 0; n < 8; n++) {
				for (int m = 0; m < 8; m++) {
					if (board[n + i][m + j] != b1[n][m])
						b1cnt++;
					if (board[n + i][m + j] != b2[n][m])
						b2cnt++;
				}
			}
			res = min(res, b1cnt > b2cnt ? b2cnt : b1cnt);
		}
	}
	printf("%d\n", res);
	return 0;
}