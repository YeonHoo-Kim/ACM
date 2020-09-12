// 17394.cpp
// 핑거 스냅

#include<iostream>
#include<algorithm>
#include<cmath>
#include<queue>

using namespace std;

const int MAX = 100001;
bool prime[MAX] = { 0 };
int psum[MAX] = { 0 };
int v[1000301];

int BFS(int cur, int a, int b) {
	v[cur] = 0;
	queue<int> q;
	q.push(cur);
	while (!q.empty()) {
		cur = q.front();
		q.pop();
		if (cur >= a && cur <= b) {
			if (prime[cur] == true)
				return v[cur];
		}
		if (v[cur / 2] == -1) {	
			q.push(cur / 2);
			v[cur / 2] = v[cur] + 1;
		}
		if (v[cur / 3] == -1) {
			q.push(cur / 3);
			v[cur / 3] = v[cur] + 1;
		}
		if (v[cur + 1] == -1) {
			q.push(cur + 1);
			v[cur + 1] = v[cur] + 1;
		}
		if (v[cur - 1] == -1 && cur>= 1) {
			q.push(cur - 1);
			v[cur - 1] = v[cur] + 1;
		}
	}
	return -1;
}


int main() {

	ios::sync_with_stdio(stdin);
	cin.tie(NULL);
	int T;
	cin >> T;
	for (int i = 2; i <= 100000; i++) {
		int flag = 0;
		for (int j = 2; j <= sqrt(i); j++)
			if (i%j == 0) {
				flag = 1;
				break;
			}
		if (flag == 0)
			prime[i] = true;
	}
	for (int i = 2; i <= 100000; i++) {
		if (prime[i] == true)
			psum[i] = psum[i - 1] + 1;
		else
			psum[i] = psum[i - 1];
	}
	while (T--) {
		int N, A, B;
		cin >> N >> A >> B;
		if (psum[B] - psum[A - 1] == 0)
			cout << "-1\n";
		else {
			for (int i = 0; i < 1000301; i++)
				v[i] = -1;
			if (N >= A && N <= B) {
				if (prime[N] == true)
					cout << "0\n";
				else
					cout << BFS(N, A, B) << "\n";
			}
			else
				cout << BFS(N, A, B) << "\n";
		}
	}
	return 0;
}