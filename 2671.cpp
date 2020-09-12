// 2671.cpp
// 잠수함식별
//
// regex를 이용한 FA 개념, 가능한 string 여부 확인 (regex_match)
#include<iostream>
#include<regex>
#include<string>

using namespace std;

int main() {

	regex re("(100+1+|01)+");
	cmatch m;
	string seq;
	cin >> seq;
	bool ans = regex_match(seq.c_str(), m, re);
	cout << (ans ? "SUBMARINE\n" : "NOISE\n");

	return 0;
}