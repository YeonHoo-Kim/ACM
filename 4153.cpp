// 4153.cpp
// Á÷°¢»ï°¢Çü

#include<cstdio>
#define SWAP(x,y){int t; t=x;x=y;y=t;}
int main() {

	int a, b, c;
	while (1) {
		scanf("%d %d %d", &a, &b, &c);
		if (a == 0 && b == 0 && c == 0)
			break;
		if (c < a)
			SWAP(c, a);
		if (c < b)
			SWAP(c, b);
		if (c*c == a * a + b * b)
			printf("right\n");
		else
			printf("wrong\n");
	}
	return 0;
}