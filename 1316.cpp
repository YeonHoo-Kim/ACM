// 1316�� �׷�ܾ� üĿ

// �׳� �� string ���� ���� a~z ���� �� ���� ���ڸ� ���� �ִ��� check[26]�� ����
// a~z ���ڵ� �� 2�� �̻� ���� �ִ� ���ڸ� ���� �߷����� �̵��� �׷�Ǿ��ִ��� ������ �ִ����� �Ǻ��Ѵ�.

#include<cstdio>
#include<stdlib.h>

int main() {

	char **str;
	int n, num = 0, check[26], chk;

	scanf("%d", &n);
	
	str = (char**)malloc(n*sizeof(char*));
	for (int i = 0; i < n; i++) {
		for (int a = 0; a < 26; a++)
			check[a] = 0;

		str[i] = (char*)malloc(100 * sizeof(char));
		scanf("%s", str[i]);
		int j = 0;
		chk = 0;
		while (str[i][j] != '\0') {
			check[str[i][j] - 'a']++;
			j++;
		}
		for (j = 0; j < 26; j++) {
			if (check[j] > 1) {
				int k = 0;
				while (str[i][k+1] != '\0') {
					
					if (str[i][k] == j + 'a')
						check[j]--;

					if (str[i][0] == j + 'a' && str[i][1] != j + 'a'&& check[j]>0) {
						chk++;
						break;
					}

					if (str[i][k] == j + 'a'&&str[i][k + 1] != j + 'a' && check[j] > 0) {
						chk++;
						break;
					}

					k++;
				}
			}
		}
		if (chk == 0)
			num++;
	}
	
	printf("%d\n", num);

	return 0;
}