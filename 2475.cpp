#include <iostream>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int a, sum = 0;
	for (int i = 0; i < 5; i++) {
		cin >> a;
		sum += (a * a);
	}
	cout << sum % 10 << "\n";
	return 0;
}