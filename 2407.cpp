// 2407.cpp
// 조합
// 참고 : https://jaimemin.tistory.com/682
//
// 어설프게 100! 계산 혹은 그냥 파스칼 삼각형 dp로 숫자계산을 하면 long long을 아득히 초과해 버린다.
// 엄청나게 큰 수를 우린 string으로 저장해서 계산한다...

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
using lint = long long;
const int MAX = 101;
string dp[MAX][MAX];

string Add(string num1, string num2){

	lint sum = 0;
	string result;
	while (!num1.empty() || !num2.empty() || sum){
		if (!num1.empty()){
			sum += num1.back() - '0';
			num1.pop_back();
		}
		if (!num2.empty()){
			sum += num2.back() - '0';
			num2.pop_back();
		}
		result.push_back((sum % 10) + '0');
		sum /= 10;
	}
	reverse(result.begin(), result.end());
	return result;
}

string comb(int n, int r) {

	if (n == r || r == 0)
		return "1";
	string &res = dp[n][r];
	if (res != "")
		return res;
	res = Add(comb(n - 1, r - 1), comb(n - 1, r));
	return res;
}

int main(){

	ios::sync_with_stdio(stdin);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	cout << comb(n, m) << endl;
	return 0;
}