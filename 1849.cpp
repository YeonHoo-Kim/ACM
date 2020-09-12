// 1849.cpp
// 순열
//
// 세그먼트 트리의 다양한 활용을 볼 수 있는 문제
//
// point : 결국 우리는 숫자 i의 앞에 i보다 큰 숫자가 몇 개가 있는지를 세그먼트 트리로 구해야 한다. (다른 방법도 가능하나 이 코드의 경우는)
// 
// 예시를 통해서 어떻게 하는지 보자
// 8
// 5 0 1 2 1 2 0 0 
//
// 8개의 수 (1~8) 의 배치를 구해야 한다.
// 이를 위해서 우리는 먼저 세그먼트 트리의 leaf node들을 모두 1로 초기화 하여 아래와 같은 상태의 세그먼트 트리를 만든다.
//
//				8
//			4		4
//		2	        2	      2		2
//	        1         1	1           1   1	1       1	      1
//					↑
// 
// 정답을 미리 보면 : 2 7 3 5 4 1 8 6 이므로 우리가 실질적으로 접근해야되는 부분은 위의 화살표 부분이다.
//
// 이를 위해 우린 세그먼트 트리 접근의 두 가지 방식 (top-down, bottom-up) 중 top-down을 사용한다.
// 
// 그러면 우리가 접근해야되는 node의 순서는 8->4->2->1 이 되므로 이를 세그먼트 트리의 node index 순서로 보면 1->3->6->13 이 된다.
// 
// 접근하는 방식은 다음과 같다. 함수 : getIdx(node, ns, ne, value)
// 1. getIdx(1, 1, 8, 6) : node는 항상 1부터 시작 / ns, ne 는 항상 1~8 범위이므로 항상 1, 8이 된다 / value는 입력받은 숫자, 처음은 5 + 1 = 6
// 2. 첫 접근이므로 우리는 1의 위치를 찾는 것이다. 그런데 value가 6 이므로 1 앞에는 1보다 큰 수가 5개 있고 그 다음에 1을 배치한다는 의미
// 3. 첫 접근이므로 우리는 8개의 숫자를 배치할 공간 8개 중 하나도 사용하지 않았음을 알 수 있다. (세그먼트 트리의 leaf 노드가 모두 1이므로)
// 4. 따라서 node = 1 일 때 우리는 tree.item[node*2] (기준 노드의 왼쪽 아래 노드)의 값을 value와 비교하여 공간의 수가 충분하면 왼쪽 아래로 가고, 공간의 수가 충분하지 않으면 오른쪽 아래로 간다.
// 5. 현재의 경우 필요공간은 6개라 볼 수 있다. (1보다 큰 수 5개와 1을 배치할 공간 1 총 6개)
// 6. 따라서 tree.item[2] = 4 는 6보다 작기에 node = 3 ( = node * 2 + 1) 으로 바꿔서 재귀호출한다. 
// 7. 이 때, 우리는 앞에(왼쪽 아래) 4개의 공간이 있다는 걸 알기에 value에서 그만큼 빼준다. (value - tree.item[node*2])
// 8. ns, ne 또한 각각의 위치에 맞게 변경 (코드 참고)
// 9. node = 3 일 때 tree.item[node*2] = tree.item[6] = 2 이므로 현재 받아온 value = 2 이므로 충분한 공간을 갖고 있기에 왼쪽 아래로 간다.
// 10. node = 6 인 경우도 위와 마찬가지로 하면 우리가 구하려는 index를 구할 수 있다.
//
// 위와같이 index를 구하여 1을 배치했다면 해당 index 위치의 세그먼트 트리의 node 값을 0으로 바꿔줘서 공간을 사용했다는 표시를 한다. 
//
// 즉, 정리하면 i번째 숫자를 배치하려 할 때 우리는 i번째 숫자보다 큰 수가 숫자 i앞에 얼마나 있는지 입력으로 알아오고, 
// 세그먼트 트리를 이용하여 사용된 공간과 사용되지 않은 공간을 비교하여 i가 어디 배치되어야 하는지 구한다.
//
// 예를들어 위의 예시에서 4를 배치하려할 때, 직전의 공간 상태는 다음과 같을 것이다. 
// 2 ㅁ 3 ㅁㅁ 1 ㅁㅁ
// 입력에 의해 4보다 앞에 있는 4보다 큰 수는 2개 이므로 왼쪽에서부터 비어있는 공간 ㅁ 두 개를 건너 뛴
// 2 ㅁ 3 ㅁㅁ 1 ㅁㅁ
//	  ↑
//	여기에 위치되어야 한다. 즉, 	2 ㅁ 3 ㅁ 4 1 ㅁㅁ 	가 된다.
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
			item[i] = item[i * 2] + item[i * 2 + 1];
	}
	void clear() {
		for (int i = 0; i < half * 2; i++)
			item[i] = 0;
	}
} tree;


int getIdx(int node, int ns, int ne, int val) {
	if (ns == ne)
		return node - tree.half;
	else {
		int mid = (ns + ne) / 2;
		if (tree.item[node * 2] >= val)
			return getIdx(node * 2, ns, mid, val);
		else
			return getIdx(node * 2 + 1, mid + 1, ne, val - tree.item[node * 2]);
	}
}

void update(int node, int ns, int ne, int idx, int x) {
	if (ns == ne)
		tree.item[node] = x;
	else {
		int mid = (ns + ne) / 2;
		if (idx <= mid)
			update(node * 2, ns, mid, idx, x);
		else
			update(node * 2 + 1, mid + 1, ne, idx, x);
		tree.item[node] = tree.item[node * 2] + tree.item[node * 2 + 1];
	}
}

int a[100001], b[100001];

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N;
	vector<int> tmp;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> a[i];
		tmp.push_back(1);
	}
	tree = seg(N);
	tree.init(tmp);

	for (int i = 1; i <= N; i++) {
		int idx = getIdx(1, 1, tree.half, a[i] + 1);
		b[idx] = i;
		update(1, 1, tree.half, idx + 1, 0);
	}

	for (int i = 0; i < N; i++)
		cout << b[i] << "\n";
	return 0;
}