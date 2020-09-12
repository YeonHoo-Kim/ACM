// 2667.cpp
// 단지번호붙이기
#include<iostream>
#include<algorithm>

using namespace std;

char map[25][25];
bool v[25][25] = { 0 };
int dir[4][2] = { {1,0},{-1,0},{0,-1},{0,1} };
int s[314];					// 25 * 25 / 2 + 1 = 313
int N;

void dfs(int i, int j, int n) {
	int dx, dy;
	v[i][j] = true;
	map[i][j] = 0;
	s[n - 1]++;
	for (int k = 0; k < 4; k++) {
		dx = i + dir[k][0];
		dy = j + dir[k][1];
		if ((dx >= 0 && dx < N) && (dy >= 0 && dy < N) && v[dx][dy] == false && map[dx][dy] == '1')
			dfs(dx, dy, n);
	}
}

int main() {

	int cnt = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == '1') {
				cnt++;
				dfs(i, j, cnt);
			}
		}
	}
	sort(s, s + cnt);
	cout << cnt << "\n";
	for (int i = 0; i < cnt; i++)
		cout << s[i] << "\n";
	return 0;
}