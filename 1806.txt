// 1806.cpp
// 부분합 문제 긴 하지만 굳이 하나하나 범위마다의 부분합을 구해서 비교할 필요없이 
// 그냥 S보다 작으면 뒤로 더해나가고 S보다 크면 앞에서 빼보고를 반복하여
// 길이가 최소일 때를 찾아내었다.

// 예시 (다음과 같은 입력 시)
// 10 15
// 5 1 3 5 10 7 4 9 2 8
// 
// 먼저 5에서 시작한다. sum = 5
// sum < S (S는 15) 이므로 뒤의 1을 더한다.	(즉, 부분합이 5+1 = 6 이 되는 것)
// sum = 6, sum < S 이므로 뒤의 3을 더한다.	(부분합 = 9)
// sum = 9, sum < S 이므로 뒤의 5를 더한다.	(부분합 = 14)
// sum = 14, sum < S 이므로 뒤의 10을 더한다.	(부분합 = 24)
// sum = 24, sum >= S 이므로 앞의 5를 뺀다.	(부분합 = 19)
// sum = 19, sum >= S 이므로 앞의 1을 뺀다.	(부분합 = 18)
// sum = 18, sum >= S 이므로 앞의 3을 뺀다.	(부분합 = 15)	<= 이부분이 제일 최소 길이 2로 처음으로 인식!
// sum = 15, sum >= S 이므로 앞의 5을 뺀다.	(부분합 = 10)
// ... 계속 반복한다.
//
// tip : 예외처리 찾기가 생각보다 복잡... 수열의 앞부분의 첫 숫자가 이미 S보다 크게 된 경우는 그냥 바로 min = 1로 처리하였다.

#include<cstdio>

int num[100000];

int main() {

	int N, S, curNum, len = 0, min = -1, sum = 0, i, j;
	scanf("%d %d", &N, &S);
	for (i = 0; i < N; i++)
		scanf("%d", &num[i]);

	i = 0;	j = 0;
	while (1) {
		if (i == 0) {
			sum = num[0];
			len++;
		}
		
		if (sum < S) {
			i++;
			sum += num[i];
			len++;
		}
		else if (sum >= S && i == j) {
			min = 1;
			break;
		}
		else {
			sum -= num[j];
			j++;
			len--;
		}

		if (sum >= S && min == -1)
			min = i - j + 1;

		if (sum >= S && min > len)
			min = len;

		if (i >= N || j >= N)
			break;
	}
	if (min == -1)
		printf("0\n");
	else
		printf("%d\n", min);

	return 0;
}

// 다른코드
#include<iostream>

using namespace std;

int arr[100001], psum[100001];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, S, ans = 100001, l = 0, r = 1, tmp;
	cin >> N >> S;
	for (int i = 1; i <= N; i++)
		cin >> arr[i];
	psum[0] = 0;
	psum[1] = arr[1];
	for (int i = 1; i <= N; i++)
		psum[i] = psum[i - 1] + arr[i];
	while (l != N || r != N) {
		if (psum[r] - psum[l] >= S) {
			tmp = r - l;
			if (ans > tmp)
				ans = tmp;
			if (r == l)
				r++;
			else
				l++;
		}
		else if (psum[r] - psum[l] > S)
			l++;
		else if (psum[r] - psum[l] < S && r != N)
			r++;
		else
			l++;
	}
	if (ans != 100001)
		cout << ans;
	else
		cout << 0;
	return 0;
}