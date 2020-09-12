#include<cstdio>

int fibonacci(int n) {
	int f=0, s=1, result;
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else
		for (int i = 2; i <= n; i++) {
			result = f + s;
			f = s;
			s = result;
		}
	return result;
}

int main() {

	int i=0,size;
	scanf("%d", &size);
	while(i!=size) {
		int num;
		scanf("%d", &num);
		if (num == 0) {
			printf("%d %d\n", 1,0);
		}
		else {
			printf("%d %d\n", fibonacci(num - 1), fibonacci(num));
		}
		i++;
	}

	return 0;
}