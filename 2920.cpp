// 2920번

// 그냥 각각을 구분해서 ascending, descending, mixed 의 경우를 만든다.

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