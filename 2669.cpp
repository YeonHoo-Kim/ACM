// 2669.cpp
// 직사각형 4개의 합집합 면적 구하기
#include<iostream>
using namespace std;
int area[101][101];
int main(){
	int res = 0;
	for (int i = 0; i < 4; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		for (int j = a; j < c; j++)
			for (int k = b; k < d; k++)
				area[j][k]++;
	}
	for (int i = 1; i <= 100; i++)
		for (int j = 1; j <= 100; j++)
			if (area[i][j] > 0)
				res++;
	cout << res << "\n";
	return 0;
}