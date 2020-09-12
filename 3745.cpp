// 3745.cpp
// 오름세
//
// lis longest increasing sequence 구하는 문제
//
// segment tree를 이용하여 구하는 방법을 구현하였고 아래의 과정을 따른다.
//
// 1. 현재 수보다 앞에있고, 작은 값을 갖는 수로 끝나는 LIS 길이 중에서 비교
// 2. 값이 작은 것부터 LIS 갱신
//	- 현재 index보다 작은 index들의 LIS중 최대를 뽑아내기 (구간 중 최대, 0~index-1)
//	- 구한 최대 LIS 길이 +1로 세그먼트 트리에 update
// 3. 값이 같다면 인덱스가 큰 것부터 LIS 갱신
//	- 인덱스가 작은 것 부터 갱신 시 같은 수 참조할 수 있는 오류 발생! (1 1 1 의 경우 LIS가 원래는 1 인데 이 방식으로 하면 3이 됨)
//
// 예시
// 5 2 1 4 5 3 
//
// 위의 수열을 sorting 해주면 1 2 3 4 5 5 가 된다.
// 
// segment tree에서는 5 2 1 4 5 3의 순서대로 segment tree의 leaf(바닥) 레벨에 각각의 LIS를 넣어준다. (item[8] ~ item[13], item[14] = 0, item[15] = 0)
// ex) item[10]은 3번째 이므로 1 직전 부분인 5 2 에서의 LIS값이 들어가야 한다.
//
// 이러한 과정은 위의 설명과 코드에 구현되어있으니 참고 

#include<iostream>
#include<vector>
#include<algorithm>
using ll = long long;
using namespace std;

struct seg {
	int n, half;
	vector<int> item;
	seg(int n = 0) :n(n) {
		for (half = 1; half < n; half <<= 1);
		item.resize(half * 2);
	}
	void init(vector<int>& arr) {
		for (int i = 0; i < n; i++)
			item[i + half] = arr[i];
		for (int i = n; i < half; i++)
			item[i + half] = 0;
		for (int i = half - 1; i > 0; i--)
			item[i] = max(item[i * 2], item[i * 2 + 1]);
	}
	void clear() {
		for (int i = 0; i < half * 2; i++)
			item[i] = 0;
	}
} tree;


int getMax(int l, int r) {
	int res = 0;
	l += tree.half;	r += tree.half;
	while (l <= r) {
		if (l % 2)
			res = max(res, tree.item[l++]);
		if (!(r % 2))
			res = max(res, tree.item[r--]);
		l >>= 1;	r >>= 1;
	}
	return res;
}

void update(int idx, int x) {
	idx = idx + tree.half;
	tree.item[idx] = x;
	idx >>= 1;
	while (idx) {
		tree.item[idx] = max(tree.item[idx * 2], tree.item[idx * 2 + 1]);
		idx >>= 1;
	}
}

int parr[100001];

int main() {

	freopen("input.txt", "r", stdin);
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	vector<pair<int,int>> p;
	while (cin >> N) {
		tree = seg(N);
		for (int i = 1; i <= N; i++) {
			cin >> parr[i];
			p.push_back({ parr[i], -i });
		}
		sort(p.begin(), p.end());
		update((-p[0].second) - 1, 1);
		for (int i = 1; i < N; i++) {
				update((-p[i].second) - 1, getMax(0, (-p[i].second) - 2) + 1);
		}
		cout << tree.item[1] << "\n";
		p.clear();
		tree.clear();
	}
	return 0;
}