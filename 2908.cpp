// 2908번 상수

// 그냥 거꾸로 크기 비교하기 (각 자리수 별 구분하여 뒷자리부터 크기 비교)

#include<cstdio>

void print(int a) {
	printf("%d", a % 10);
	printf("%d", (a / 10) % 10);
	printf("%d\n", a / 100);
}

int main() {

	int a, b;

	scanf("%d %d", &a, &b);

	if (a % 10 > b % 10)
		print(a);
	else if (a % 10 < b % 10)
		print(b);
	else {
		if ((a / 10) % 10 > (b / 10) % 10)
			print(a);
		else if ((a / 10) % 10 < (b / 10) % 10)
			print(b);
		else {
			if (a / 100 > b / 100)
				print(a);
			else if (a / 100 < b / 100)
				print(b);
			else
				print(a);
		}
	}

	return 0;
}