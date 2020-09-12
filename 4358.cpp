// 4358.cpp
// 생태학
//
// 입력에 뭐가 있는지 모르지만 꽤나 고생함
// trie를 이용하거나 map을 이용해서 구현할 수 있다.

#include <iostream>
#include <map>
#include <string>
using namespace std;
int N;
char str[31];
map<string, double> mp;
int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	while (cin.getline(str, 30)) {
		N += 1;
		mp[str]++;
	}
	cout << fixed;
	cout.precision(4);
	for (auto iter = mp.begin(); iter != mp.end(); iter++)
		cout << iter->first << ' ' << iter->second / N * 100.0 << '\n';
	return 0;
}