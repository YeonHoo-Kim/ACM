// 5622�� ���̾�

// �׳� �ԷµǴ� �빮�ڵ� ����, �ش� ���̾� �����µ� �ɸ��� �ð��� �����ش�.
// ���������� ��ȭ��ȣ ���� ��, 1�� 0 �� ���� �Է��϶�°���...(�Է��ϴ� ��찡 ���µ�)

#include<cstdio>

int main() {

	char str[15] = { 0 };
	int i = 0, time = 0;
	scanf("%s", str);

	while (str[i] != '\0') {
		if (str[i] >= 'A'&&str[i] <= 'C')
			time += 3;
		if (str[i] >= 'D'&&str[i] <= 'F')
			time += 4;
		if (str[i] >= 'G'&&str[i] <= 'I')
			time += 5;
		if (str[i] >= 'J'&&str[i] <= 'L')
			time += 6;
		if (str[i] >= 'M'&&str[i] <= 'O')
			time += 7;
		if (str[i] >= 'P'&&str[i] <= 'S')
			time += 8;
		if (str[i] >= 'T'&&str[i] <= 'V')
			time += 9;
		if (str[i] >= 'W'&&str[i] <= 'Z')
			time += 10;
		i++;
	}
	printf("%d\n", time);
	return 0;
}