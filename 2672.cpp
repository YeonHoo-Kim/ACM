// 2672.cpp
// 여러 직사각형의 전체 면적 구하기
//
// 그냥 단순하게 (0~1000.0) * (0~1000.0) 의 이차원 면적에 해당되는 이차원 배열 area[10001][10001]에서 직사각형이
// 면적을 차지할 때는 true로 표시하여 계산해보았다. (채점시 맞았습니다 가능 : 2019.10.2 기준, 아래 코드 참고)
//
// 그러나 마음에 안든다. 그래서 찾아봄 (출처 : https://kthng.tistory.com/42)
// 정리해보면 그냥 모든 직사각형들의 꼭지점을 기준으로 가로 세로의 연장선을 그려준다.
//  
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include<iostream>

using namespace std;

bool area[10001][10001];

int main() {

	ios::sync_with_stdio(stdin);
	cin.tie(0);
	int N, cnt = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		double a, b, c, d;
		int x, y, w, h;
		cin >> a >> b >> c >> d;
		x = (int)(a * 10);
		y = (int)(b * 10);
		w = (int)(c * 10);
		h = (int)(d * 10);
		for (int j = x; j < x + w; j++)
			for (int k = y; k < y + h; k++)
				area[j][k] = true;
	}
	for (int i = 0; i < 10001; i++)
		for (int j = 0; j < 10001; j++)
			if (area[i][j])
				cnt++;
	if (cnt % 100 == 0)
		printf("%d\n", cnt / 100);
	else
		printf("%.2lf\n", ((double)cnt) / 100);
	return 0;
}