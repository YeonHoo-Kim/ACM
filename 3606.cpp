// 3606.cpp
// Cellular Automaton
//
// 특수행렬은 시간복잡도 O(n^2 logK) 를 사용한다.
//
// 이 문제를 읽고 이해를 했다면 우리는 행렬의 제곱에서 쓰일 행렬이 특수한 규칙을 가짐을 알 수 있다.
//
// 예시 1의 경우 쓰이는 행렬은
// 1 1 0 0 1
// 1 1 1 0 0
// 0 1 1 1 0
// 0 0 1 1 1
// 1 0 0 1 1
//
// 과 같이 나타난다.
//
// 이는 제곱을 얼마나 하던간에 윗 행을 갖고 그 다음 아래의 행을 구할 수 있게 한다. (한 칸씩 뒤로 밀려 순환하는 구조)
// 즉, 하나의 행만 구하고 나머지 행들은 구한 행을 이용해서 표현 가능하기에 
// 기존의 시간복잡도 O(n^3 logK) 에서 O(n^2 logK) 로 줄일 수 있게 된다.

#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
ll mod;
int input[500];

struct mat {
	int size;
	vector<vector<ll> > item;
	mat(int n = 0) :size(n) {
		item.resize(n);
		for (int i = 0; i < n; ++i) item[i].resize(n);
	}
	mat operator * (const mat rhs) {
		mat temp(size);
		for (int i = 0; i < size; ++i) {
			for (int j = 0; j < size; ++j) {
				temp.item[0][j] += item[0][i] * rhs.item[i][j];
				temp.item[0][j] %= mod;
			}
		}
		for (int i = 1; i < size; i++) {
			for (int j = 0; j < size; j++) {
				if (i + j < size)
					temp.item[i][j + i] = temp.item[0][j];
				else
					temp.item[i][j + i - size] = temp.item[0][j];
			}
		}
		return temp;
	}
	mat identity() {
		mat res(size);
		for (int i = 0; i < size; ++i) res.item[i][i] = 1;
		return res;
	}
	mat exp(ll times) {
		mat res, tmp;

		res = mat(size).identity();
		tmp = *this;

		while (times) {
			if (times % 2)
				res = res * tmp;
			times >>= 1;
			tmp = tmp * tmp;
		}
		return res;
	}
};

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, d;
	ll m, k, sum;

	cin >> n >> m >> d >> k;
	mat tmp(n), ans(n);
	mod = m;
	for (int i = 0; i < n; i++) {
		for (int j = i - d; j <= i + d; j++) {
			if (j < 0)
				tmp.item[i][n + j] = 1;
			else if (j >= n)
				tmp.item[i][j - n] = 1;
			else
				tmp.item[i][j] = 1;
		}
	}
	ans = tmp.exp(k);

	for (int i = 0; i < n; i++)
		cin >> input[i];

	for (int i = 0; i < n; i++) {
		sum = 0;
		for (int j = 0; j < n; j++) {
			sum += ans.item[i][j] * input[j];
			sum %= m;
		}
		cout << sum << " ";
	}
	return 0;
}