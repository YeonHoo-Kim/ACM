// 1436.cpp
// 영화감독 숌

#include<iostream>

using namespace std;

int name[100000];

int main() {

	int N, num = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		if (num % 1000 == 666 && num >= 666) {
			for (int j = 0; j < 1000; j++)
				name[i + j] = num * 1000 + j;
			i += 999;
		}
		else if (num % 100 == 66 && num >= 66) {
			for (int j = 0; j < 100; j++)
				name[i + j] = num * 1000 + 600 + j;
			i += 99;
		}
		else if (num % 10 == 6 && num >= 6) {
			for (int j = 0; j < 10; j++)
				name[i + j] = num * 1000 + 660 + j;
			i += 9;
		}
		else
			name[i] = num * 1000 + 666;
		num++;
	}
	cout << name[N-1] << "\n";
	return 0;
}