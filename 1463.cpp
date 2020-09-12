// 1463.cpp
// 1로 만들기
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <algorithm>
using namespace std;

int f(int a) {
	if (a <= 1)
		return  0;
	return min(f(a / 2) + a % 2 + 1, f(a / 3) + a % 3 + 1);
}

int main() {
	int a; 
	scanf("%d", &a);
	printf("%d", f(a));
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include<iostream>
#include<queue>

using namespace std;

queue<pair<int,int>> q;

int BFS(int num) {
	q.push({ num, 0 });
	while (!q.empty()) {
		num = q.front().first;
		int cnt = q.front().second;
		if (num == 1)
			return cnt;
		q.pop();
		if (num % 3 == 0)
			q.push({ num / 3, cnt + 1 });
		if(num%2 == 0)
			q.push({ num / 2, cnt + 1 });
		q.push({ num - 1, cnt + 1 });
	}
}

int main() {
	ios::sync_with_stdio(stdin);
	cin.tie(0);
	int N;
	cin >> N;
	cout << BFS(N) << "\n";
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////