// 2920��

// �׳� ������ �����ؼ� ascending, descending, mixed �� ��츦 �����.

#include<cstdio>

int main() {

	int num[8],j;
	for (int i = 0; i < 8; i++)
		scanf("%d", &num[i]);
	
	for (j = 0; j < 7; j++) {
		if (num[j] > num[j + 1])
			break;
	}

	if (j == 7) {
		printf("ascending\n");
		return 0;
	}

	for (j = 0; j < 7; j++) {
		if (num[j] < num[j + 1])
			break;
	}

	if (j == 7) {
		printf("descending\n");
		return 0;
	}

	printf("mixed\n");
	return 0;
}