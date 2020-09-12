// 1517.cpp
// 버블정렬
//
// 머지정렬 과정에서 정렬을 해주는 개수를 적당히 세면 된다. 머지정렬에 대한 이해가 중요!
//
#include<iostream>
using ll = long long;
using namespace std;

int A[500001], sort[500001];
ll cnt = 0;

void merge(int l, int r) {
	int m = (l + r) / 2;
	int i = l, j = m + 1, k = l;
	while (i <= m && j <= r) {
		if (A[i] <= A[j])
			sort[k++] = A[i++];
		else {
			sort[k++] = A[j++];
			cnt += (ll)m - (ll)i + 1;
		}
	}
	while(i<=m)
		sort[k++] = A[i++];
	while(j<=r)
		sort[k++] = A[j++];
	for (int t = l; t <= r; t++)
		A[t] = sort[t];
}

void mergesort(int l, int r) {
	if (l < r) {
		int m = (l + r) / 2;
		mergesort(l, m);
		mergesort(m + 1, r);
		merge(l, r);
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> A[i];
	mergesort(1, N);
	cout << cnt;
	return 0;
}