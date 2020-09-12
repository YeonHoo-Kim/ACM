// 17393.cpp
// 
// upper_bound 사용 시
#include<iostream>
#include<algorithm>

using namespace std;

const int MAX = 500001;
long long A[MAX];
long long B[MAX];

int main() {

	ios::sync_with_stdio(stdin);
	cin.tie(NULL);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> A[i];
	for (int i = 0; i < N; i++)
		cin >> B[i];
	for (int i = 0; i < N; i++)
		cout << upper_bound(B, B + N, A[i]) - (B + i + 1) << " ";
	cout << "\n";
	return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// upper_bound 미 사용 시
/*#include<iostream>
#include<algorithm>

using namespace std;

const int MAX = 500001;
long long A[MAX];
long long B[MAX];
int len[MAX];

int binSearch(int s, int e, long long num) {
	if (num >= B[e] || s == e)
		return e;
	else {
		int mid = (s + e + 1) / 2;
		if (num >= B[mid])
			binSearch(mid, e, num);
		else
			binSearch(s, mid-1, num);
	}
}

int main() {

	ios::sync_with_stdio(stdin);
	cin.tie(NULL);
	int N, idx;
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> A[i];
	for (int i = 0; i < N; i++)
		cin >> B[i];
	len[N - 1] = 0;
	for (int i = 0; i < N; i++) {
		idx = binSearch(0, N - 1, A[i]);
		if (idx <= i)
			cout << "0 ";
		else
			cout<<idx - i<<" ";
	}
	cout << "\n";
	return 0;
}*/