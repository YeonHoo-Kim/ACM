// 2492.cpp
// 보석
//
// 한 점을 기준으로 4사분면을 모두 비교했다가 십자가에 후두려맞은 문제...
// 그냥 두 점 골라서 왼쪽 위 교점을 찾고 그 점에서 정사각형을 그려서 최대한의 포함되는 점들 개수 일일히 세는 문제
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int MAX = 101;
vector<pair<int, int>> dot;
int main() {

	ios::sync_with_stdio(stdin);
	cin.tie(0);
	int N, M, T, K, n, x1, y1, x2, y2, lx, ly, ansx, ansy, maxCount = 0, cnt;
	cin >> N >> M >> T >> K;
	for (int t = 0; t < T; t++) {
		int a, b;
		cin >> a >> b;
		dot.push_back({ a,b });
	}
	n = dot.size();
	for (int i = 0; i < n; i++) {
		x1 = dot[i].first;	y1 = dot[i].second;
		for (int j = 0; j < n; j++) {
			x2 = dot[j].first;	y2 = dot[j].second;
			cnt = 0;
			lx = x1 < x2 ? x1 : x2;
			ly = y1 > y2 ? y1 : y2;
			for (int k = 0; k < n; k++) {
				int a = dot[k].first, b = dot[k].second;
				if (lx <= a && a <= lx + K && ly - K <= b && b <= ly)
					cnt++;
			}
			if (maxCount < cnt) {
				maxCount = cnt;
				ansx = lx;	ansy = ly;
			}
		}
	}
	if (ansx + K > N && ansy - K < 0) { ansx = N - K;	ansy = K; }
	else if (ansx + K > N) { ansx = N - K; }
	else if (ansy - K < 0) { ansy = K; }
	
	cout << ansx << " " << ansy << "\n";
	cout << maxCount << "\n";
	return 0;
}