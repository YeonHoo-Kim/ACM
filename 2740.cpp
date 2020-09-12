// 2740.cpp
// 행렬 곱셈 (small)

#include<iostream>

using namespace std;

const int MAX = 100;
int A[MAX][MAX];
int B[MAX][MAX];
int C[MAX][MAX] = { 0 };

int main() {

	int N, M, K;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int num;
			cin >> num;
			A[i][j] = num;
		}
	}
	cin >> M >> K;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < K; j++) {
			int num;
			cin >> num;
			B[i][j] = num;
		}
	}
	for (int i = 0; i < N; i++)
		for (int j = 0; j < K; j++)
			for (int k = 0; k < M; k++)
				C[i][j] += A[i][k] * B[k][j];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < K; j++) {
			cout << C[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}