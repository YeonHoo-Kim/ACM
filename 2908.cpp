// 2908�� ���

// �׳� �Ųٷ� ũ�� ���ϱ� (�� �ڸ��� �� �����Ͽ� ���ڸ����� ũ�� ��)

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