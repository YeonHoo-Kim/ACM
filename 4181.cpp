// 4181.cpp
// Monotone Chain Algorithm
#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;
const int MAX = 100001;
vector<pair<int, int>> v;
int lower[MAX], upper[MAX];

int ccw(int pre2, int pre1, int cur) {
	long long x1, y1, x2, y2, x3, y3, val;
	x1 = v[pre2].first;	y1 = v[pre2].second;
	x2 = v[pre1].first;	y2 = v[pre1].second;
	x3 = v[cur].first;		y3 = v[cur].second;
	val = x1 * y2 + x2 * y3 + x3 * y1 - x2 * y1 - x3 * y2 - x1 * y3;
	if (val > 0)
		return 1;
	else if (val == 0)
		return 0;
	else
		return -1;
}

int main() {

	ios::sync_with_stdio(stdin);
	cin.tie(0);
	int N, lidx = 0, uidx = 0, size;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a, b;
		char c;
		cin >> a >> b >> c;
		if (c == 'Y')
			v.push_back({ a,b });
	}
	sort(v.begin(), v.end());
	size = v.size();
	for (int i = 0; i < size; i++) {
		while (lidx >= 2 && ccw(lower[lidx - 2], lower[lidx - 1], i) < 0)
			lidx--;
		lower[lidx++] = i;
	}
	for (int i = size - 1; i >= 0; i--) {
		while (uidx >= 2 && ccw(upper[uidx - 2], upper[uidx - 1], i) < 0)
			uidx--;
		upper[uidx++] = i;
	}
	cout << lidx + uidx - 2 << "\n";
	for (int i = 0; i < lidx - 1; i++)
		cout << v[lower[i]].first << " " << v[lower[i]].second << "\n";
	for (int i = 0; i < uidx - 1; i++)
		cout << v[upper[i]].first << " " << v[upper[i]].second << "\n";
	return 0;
}