// 1006.cpp
// 습격자 초라기

#include<iostream>
#include<algorithm>

using namespace std;

const int INF = 1000000007;
const int MAX = 10001;
int enemy[MAX][2];
int a[MAX], b[MAX], c[MAX];

int main() {

	int T;
	cin >> T;
	while (T--) {
		int N, W, res = INF;
		cin >> N >> W;
		for (int i = 0; i < N; i++)
			cin >> enemy[i][0];
		for (int i = 0; i < N; i++)
			cin >> enemy[i][1];
		a[0] = 0;	b[0] = 1;	c[0] = 1;
		if (N == 1) {										// N = 1 
			if (enemy[0][0] + enemy[0][1] <= W)
				res = 1;
			else
				res = 2;
		}
		else {												// 1	~	N
			for (int i = 0; i < N; i++) {					// N+1	~	2N
				a[i + 1] = min(b[i] + 1, c[i] + 1);
				if (enemy[i][0] + enemy[i][1] <= W)
					a[i + 1] = min(a[i + 1], a[i] + 1);
				if (i > 0 && enemy[i - 1][0] + enemy[i][0] <= W && enemy[i - 1][1] + enemy[i][1] <= W)
					a[i + 1] = min(a[i + 1], a[i - 1] + 2);
				if (i < N - 1) {
					b[i + 1] = a[i + 1] + 1;
					if (enemy[i][0] + enemy[i + 1][0] <= W)
						b[i + 1] = min(b[i + 1], c[i] + 1);
					c[i + 1] = a[i + 1] + 1;
					if (enemy[i][1] + enemy[i + 1][1] <= W)
						c[i + 1] = min(c[i + 1], b[i] + 1);
				}
			}
			res = min(res, a[N]);

			if (enemy[0][0] + enemy[N - 1][0] <= W) {		//	N 1		~	N-1
				a[1] = 1;	b[1] = 2;						//	  N+1	~	2N-1 2N
				if (enemy[0][1] + enemy[1][1] <= W)
					c[1] = 1;
				else
					c[1] = 2;
				for (int i = 1; i < N; i++) {
					a[i + 1] = min(b[i] + 1, c[i] + 1);
					if (enemy[i][0] + enemy[i][1] <= W)
						a[i + 1] = min(a[i + 1], a[i] + 1);
					if (i > 0 && enemy[i - 1][0] + enemy[i][0] <= W && enemy[i - 1][1] + enemy[i][1] <= W)
						a[i + 1] = min(a[i + 1], a[i - 1] + 2);
					if (i < N - 1) {
						b[i + 1] = a[i + 1] + 1;
						if (enemy[i][0] + enemy[i + 1][0] <= W)
							b[i + 1] = min(b[i + 1], c[i] + 1);
						c[i + 1] = a[i + 1] + 1;
						if (enemy[i][1] + enemy[i + 1][1] <= W)
							c[i + 1] = min(c[i + 1], b[i] + 1);
					}
				}
				res = min(res, c[N - 1] + 1);
			}
			if (enemy[0][1] + enemy[N - 1][1] <= W) {		//	   1	~	N-1   N
				a[1] = 1;	c[1] = 2;						// 2N N+1	~	2N-1
				if (enemy[0][0] + enemy[1][0] <= W)
					b[1] = 1;
				else
					b[1] = 2;
				for (int i = 1; i < N; i++) {
					a[i + 1] = min(b[i] + 1, c[i] + 1);
					if (enemy[i][0] + enemy[i][1] <= W)
						a[i + 1] = min(a[i + 1], a[i] + 1);
					if (i > 0 && enemy[i - 1][0] + enemy[i][0] <= W && enemy[i - 1][1] + enemy[i][1] <= W)
						a[i + 1] = min(a[i + 1], a[i - 1] + 2);
					if (i < N - 1) {
						b[i + 1] = a[i + 1] + 1;
						if (enemy[i][0] + enemy[i + 1][0] <= W)
							b[i + 1] = min(b[i + 1], c[i] + 1);
						c[i + 1] = a[i + 1] + 1;
						if (enemy[i][1] + enemy[i + 1][1] <= W)
							c[i + 1] = min(c[i + 1], b[i] + 1);
					}
				}
				res = min(res, b[N - 1] + 1);
			}
			if (enemy[0][0] + enemy[N - 1][0] <= W && enemy[0][1] + enemy[N - 1][1] <= W) {
				a[1] = 0;	b[1] = 1;	c[1] = 1;			//	N  1	~	N-1
				for (int i = 1; i < N; i++) {				//	2N N+1	~	2N-1
					a[i + 1] = min(b[i] + 1, c[i] + 1);
					if (enemy[i][0] + enemy[i][1] <= W)
						a[i + 1] = min(a[i + 1], a[i] + 1);
					if (i > 0 && enemy[i - 1][0] + enemy[i][0] <= W && enemy[i - 1][1] + enemy[i][1] <= W)
						a[i + 1] = min(a[i + 1], a[i - 1] + 2);
					if (i < N - 1) {
						b[i + 1] = a[i + 1] + 1;
						if (enemy[i][0] + enemy[i + 1][0] <= W)
							b[i + 1] = min(b[i + 1], c[i] + 1);
						c[i + 1] = a[i + 1] + 1;
						if (enemy[i][1] + enemy[i + 1][1] <= W)
							c[i + 1] = min(c[i + 1], b[i] + 1);
					}
				}
				res = min(res, a[N - 1] + 2);
			}
		}
		cout << res << "\n";
	}
	return 0;
}