// 2577번 숫자의 개수

// A*B*C 값에서 각 자릿수마다 0~9가 얼마나 있는지 개수 구하기
// 그냥 각 자리수마다 구분해서 해당 값과 같은 index를 갖는 배열을 +1 해줘서 개수를 센다.


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