// 2577�� ������ ����

// A*B*C ������ �� �ڸ������� 0~9�� �󸶳� �ִ��� ���� ���ϱ�
// �׳� �� �ڸ������� �����ؼ� �ش� ���� ���� index�� ���� �迭�� +1 ���༭ ������ ����.


#include<cstdio>

int main() {

	int a, b, c, res, i = 100000000;
	int num[10] = { 0 };

	scanf("%d %d %d",&a, &b, &c);

	res = a*b*c;

	while (1) {
		if (res / i == 0)
			i /= 10;
		else
			break;
	}

	while (i != 0) {
		num[res / i]++;
		res -= (res / i)*i;
		i /= 10;
	}
	for (i = 0; i < 10; i++)
		printf("%d\n", num[i]);
	return 0;
}