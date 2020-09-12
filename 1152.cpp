// 1152번 단어의 개수

// 공백 포함을 위해 %[^\n] 사용
// 입력 상태가 "  a b c  " 이러한 경우 등 공백이 다양하게 들어가는 경우에 대한 예외 case의 구분이 중요


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