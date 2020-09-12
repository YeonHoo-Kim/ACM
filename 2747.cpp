// 2747.cpp
// 피보나치 수

#include<iostream>

using namespace std;

const int div_by = 1000000;
long long mat[2][2] = { {0,1},
				  {1,1} };
long long tmp[2][2];
long long res[2][2];

int main() {

	long long n;
	int flag = 0;
	cin >> n;
	n--;
	if (n == 0)
		cout << 1 << "\n";
	else {
		while (n != 0) {
			if (n % 2 == 1) {
				if (flag == 0) {
					for (int i = 0; i < 2; i++)
						for (int j = 0; j < 2; j++)
							res[i][j] = mat[i][j];
					flag = 1;
				}
				else {
					for (int i = 0; i < 2; i++) {
						for (int j = 0; j < 2; j++) {
							tmp[i][j] = res[i][j];
							res[i][j] = 0;
						}
					}
					for (int i = 0; i < 2; i++)
						for (int j = 0; j < 2; j++)
							for (int k = 0; k < 2; k++)
								res[i][j] = (res[i][j] + (tmp[i][k] * mat[k][j])/* % div_by*/)/* % div_by*/;
				}
			}
			tmp[0][0] = (mat[0][0] * mat[0][0]) /*% div_by*/ + (mat[0][1] * mat[1][0])/* % div_by*/;
			tmp[0][1] = (mat[0][0] * mat[0][1]) /*% div_by*/ + (mat[0][1] * mat[1][1]) /*% div_by*/;
			tmp[1][0] = (mat[1][0] * mat[0][0]) /*% div_by*/ + (mat[1][1] * mat[1][0]) /*% div_by*/;
			tmp[1][1] = (mat[1][0] * mat[0][1]) /*% div_by*/ + (mat[1][1] * mat[1][1]) /*% div_by*/;
			for (int i = 0; i < 2; i++)
				for (int j = 0; j < 2; j++)
					mat[i][j] = tmp[i][j]/* % div_by*/;
			n >>= 1;
		}
		cout << res[1][1] << "\n";
	}
	return 0;
}