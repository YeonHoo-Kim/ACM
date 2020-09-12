#include<cstdio>

int inCircle(int x, int y, int cx, int cy, int cr) {
	
	if ((x - cx)*(x - cx) + (y - cy)*(y - cy) < cr*cr)
		return -1;
	else
		return 1;
}

int main() {

	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		
		int x1, y1, x2, y2, n, start, end, result=0;

		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		scanf("%d", &n);

		for (int j = 0; j < n; j++) {
			
			int cx, cy, r;
			
			scanf("%d %d %d", &cx, &cy, &r);

			start = inCircle(x1, y1, cx, cy, r);
			end = inCircle(x2, y2, cx, cy, r);

			if (start*end < 0)
				result++;

		}
		printf("%d\n", result);
	}
	return 0;
}