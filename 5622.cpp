// 5622번 다이얼

// 그냥 입력되는 대문자들 마다, 해당 다이얼 돌리는데 걸리는 시간을 더해준다.
// 개인적으로 전화번호 누를 때, 1과 0 은 어찌 입력하라는건지...(입력하는 경우가 없는듯)

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