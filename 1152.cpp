// 1152�� �ܾ��� ����

// ���� ������ ���� %[^\n] ���
// �Է� ���°� "  a b c  " �̷��� ��� �� ������ �پ��ϰ� ���� ��쿡 ���� ���� case�� ������ �߿�


#include<cstdio>

int main() {

	char str[1000000] = { 0 };
	int n, i = 0;

	scanf("%[^\n]", str);

	if (str[0] != ' ')
		n = 1;
	else
		n = 0;
	i++;
	while (str[i] != 0) {
		if (str[i - 1] == ' '&&str[i] != ' ')
			n++;
		i++;
	}
	printf("%d\n", n);

	return 0;

}