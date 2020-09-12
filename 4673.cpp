// 4673번 self number 골라내기

// 배열 전체를 0으로 초기화한 뒤
// 배열의 index 가 self number 가 아닌 경우 값을 1로 지정하였다. 
// 이후 값이 0인 배열의 index들을 출력

#include<cstdio>

int main() {

	int i = 0, self[10036] = { 0 };

	for (i = 0; i < 10000; i++)
		self[i + (i / 1000) % 10 + (i / 100) % 10 + (i / 10) % 10 + i % 10] = 1;

	for (i = 1; i <= 10000; i++)
		if (self[i] == 0)
			printf("%d\n",i);

	return 0;
}