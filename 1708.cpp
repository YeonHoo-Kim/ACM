// 1708.cpp
// 내가 생각한 방식
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;
const double INF = 1e9 + 7;
const int MAX = 100001;
vector<pair<int, int>> v;
vector<int> lower, upper;

double slope(int x1, int y1, int x2, int y2) {
	if (x2 - x1 == 0)
		return INF;
	else
		return ((double)(y2 - y1) / (double)(x2 - x1));
}

int ccw(int idx, int flag) {								// 그 다음 점에 대한 index를 return 하는 ccw (counter clockwise)
	double val;
	int res;
	if (flag == 0) {										// lower case를 위한 ccw
		res = idx + 1;
		for (unsigned int i = idx + 1; i < v.size(); i++) {
			int x1 = v[idx].first, y1 = v[idx].second;
			int x2 = v[i].first, y2 = v[i].second;
			double tval = slope(x1, y1, x2, y2);
			if (i == idx + 1)
				val = tval;
			else {
				if (val >= tval) {
					val = tval;
					res = i;
				}
			}
		}
	}
	else {													// upper case를 위한 ccw
		res = idx - 1;
		for (int i = idx - 1; i >= 0; i--) {
			int x1 = v[idx].first, y1 = v[idx].second;
			int x2 = v[i].first, y2 = v[i].second;
			double tval = slope(x1, y1, x2, y2);
			if (i == idx - 1)
				val = tval;
			else {
				if (val >= tval) {
					val = tval;
					res = i;
				}
			}
		}
	}
	return res;
}

int main() {

	ios::sync_with_stdio(stdin);
	cin.tie(0);
	int N, cnt = 0, cur = 0, next = 1;
	cin >> N;
	for (int i = 0; i < N; i++) {	// 점들을 받아온다.
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b });
	}
	sort(v.begin(), v.end());		// 점들을 x좌표, y좌표 순으로 정렬
	while (cur != N - 1) {			// lower case
		next = ccw(cur, 0);
		lower.push_back(cur);
		cur = next;
	}
	while (cur != 0) {				// upper case
		next = ccw(cur, 1);
		upper.push_back(cur);
		cur = next;
	}
	cout << lower.size() + upper.size() << "\n";	// lower, upper 들어간 점들의 개수 합
	return 0;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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
		cin >> a >> b;
		v.push_back({ a,b });
	}
	sort(v.begin(), v.end());
	size = v.size();
	for (int i = 0; i < size; i++) {
		while (lidx >= 2 && ccw(lower[lidx - 2], lower[lidx - 1], i) <= 0)
			lidx--;
		lower[lidx++] = i;
	}
	for (int i = size - 1; i >= 0; i--) {
		while (uidx >= 2 && ccw(upper[uidx - 2], upper[uidx - 1], i) <= 0)
			uidx--;
		upper[uidx++] = i;
	}
	cout << lidx + uidx - 2 << "\n";
	return 0;
}