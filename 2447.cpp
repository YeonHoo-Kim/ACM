// 2447.cpp
// º°Âï±â - 10

#include<cstdio>

char star[6562][6562] = { 0 };

int main() {

	int n, val, tval, exp = 0;
	scanf("%d", &n);
	val = n;
	while (n != 1) {
		n /= 3;
		exp++;
	}
	tval = val / 3;
	while (exp != 0) {
		int k1, k2, kf1, kf2;
		for (k1 = val / 2 + 1; k1 > 0; k1 -= tval * 3) {}
		for (k2 = val / 2 + 1; k2 > 0; k2 -= tval * 3) {}
		k1 += tval * 3;	k2 += tval * 3;
		kf1 = k1; kf2 = k2;
		for (k1 = kf1; k1 < val; k1 += tval * 3)
			for (k2 = kf2; k2 < val; k2 += tval * 3)
				for (int i = k1 - (tval / 2); i <= k1 + (tval / 2); i++)
					for (int j = k2 - (tval / 2); j <= k2 + (tval / 2); j++)
						star[i][j] = ' ';
		
		tval /= 3;
		exp--;
	}
	for (int i = 1; i <= val; i++){
		for (int j = 1; j <= val; j++) {
			if (star[i][j] == 0)
				printf("*");
			else
				printf("%c", star[i][j]);
		}
		printf("\n");
	}

	return 0;
}