// 18117.cpp
//
// 설명보단 출처 ㄱㄱ
// 출처 : https://sbrus1213.tistory.com/6

#include <iostream>
using namespace std;
using ll = long long;

ll modular(ll x, ll y, ll z) {
	ll res = 0;
	while (y) {
		if (y % 2)
			res = (res + x) % z;
		x = (x * 2) % z;
		y >>= 1;
	}
	return res;
}

ll multens(ll a, ll b, ll c) {
	ll t = 10, res = 1;
	while (b) {
		if (b % 2)
			res = modular(res, t, c);
		t = modular(t, t, c);
		b >>= 1;
	}
	res = modular(res, a, c);
	return res;
}

int main() {

	int T;
	cin >> T;
	while (T--) {
		ll a, b, i, res;
		int n;
		cin >> a >> b >> i >> n;
		res = multens(a, i - 1, b);
		for (int j = 0; j < n; j++) {
			cout << (int)((float)res / b * 10);
			res = modular(res, 10, b);
		}
		cout << "\n";
	}
	return 0;
}