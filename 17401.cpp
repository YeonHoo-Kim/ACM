// 17401.cpp
// 일하는 세포

#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
ll mod = 1e9 + 7;
struct mat {
	int size;
	vector<vector<ll>> item;
	mat(int n = 0) :size(n) {
		item.resize(n);
		for (int i = 0; i < n; ++i) item[i].resize(n);
	}
	mat operator * (const mat rhs) {
		mat temp(size);
		for (int k = 0; k < size; ++k)
			for (int i = 0; i < size; ++i)
				for (int j = 0; j < size; ++j) {
					temp.item[i][j] += item[i][k] * rhs.item[k][j];
					temp.item[i][j] %= mod;
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
			times /= 2;
			tmp = tmp * tmp;
		}
		return res;
	}
};

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int T, N, D, modcnt, expcnt;
	mat qm, modm, ans;
	cin >> T >> N >> D;

	qm = mat(N).identity();
	modm = mat(N).identity();
	ans = mat(N).identity();
	modcnt = D % T;
	expcnt = D / T;

	while(T--){
		int M;
		mat m(N);
		cin >> M;
		while (M--) {
			int a, b, c;
			cin >> a >> b >> c;
			m.item[a - 1][b - 1] = c;
		}
		if (modcnt != 0) {
			modm = modm * m;
			modcnt--;
		}
		qm = qm * m;
	}

	if (D < T)
		ans = modm;
	else
		ans = qm.exp(expcnt) * modm;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << ans.item[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}