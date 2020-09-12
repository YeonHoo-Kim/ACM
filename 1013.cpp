// 1013.cpp
// Contact
// Finite Automata를 사용한 문제

#include<iostream>
#include<string>
using namespace std;
// 문제에서 찾는 string이 아니면 바로 Final State로 보내버린다(index : 9)
//							input 0		input 1
// 0 : Start State (S0)		7			1		
// 1 : "1"					2			9			
// 2 : "10"					3			9
// 3 : "100~"				3			4
// 4 : "100~1"				7			5					
// 5 : "100~1~"				6			5					 
// 6 : "100~1~0"			3			8					input : 0의 경우
// 7 : "0"					9			8					ex : 1000110001
// 8 : "01"					7			1					input : 1의 경우 01 이후 다시 100~1~ 이 들어오는 경우 고려
// 9 : Final State (F)		9			9					ex : 01100010
int FA[10][2] = { {7,1},{2,9},{3,9},{3,4},{7,5},{6,5},{3,8},{9,8},{7,1},{9,9} };
int main() {

	ios::sync_with_stdio(stdin);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		string str;
		int n = 0;
		cin >> str;
		for (int i = 0; i < str.size(); i++)
			n = FA[n][str[i] - '0'];
		if (n == 4 || n == 5 || n == 8)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}
