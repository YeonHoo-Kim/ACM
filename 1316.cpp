// 1316번 그룹단어 체커

// 그냥 각 string 마다 각각 a~z 까지 몇 개의 문자를 갖고 있는지 check[26]에 저장
// a~z 문자들 중 2개 이상 갖고 있는 문자만 따로 추려내어 이들이 그룹되어있는지 떨어져 있는지를 판별한다.

#include<cstdio>
#include<stdlib.h>

int main() {

	char **str;
	int n, num = 0, check[26], chk;

	scanf("%d", &n);
	
	str = (char**)malloc(n*sizeof(char*));
	for (int i = 0; i < n; i++) {
		for (int a = 0; a < 26; a++)
			check[a] = 0;

		str[i] = (char*)malloc(100 * sizeof(char));
		scanf("%s", str[i]);
		int j = 0;
		chk = 0;
		while (str[i][j] != '\0') {
			check[str[i][j] - 'a']++;
			j++;
		}
		for (j = 0; j < 26; j++) {
			if (check[j] > 1) {
				int k = 0;
				while (str[i][k+1] != '\0') {
					
					if (str[i][k] == j + 'a')
						check[j]--;

					if (str[i][0] == j + 'a' && str[i][1] != j + 'a'&& check[j]>0) {
						chk++;
						break;
					}

					if (str[i][k] == j + 'a'&&str[i][k + 1] != j + 'a' && check[j] > 0) {
						chk++;
						break;
					}

					k++;
				}
			}
		}
		if (chk == 0)
			num++;
	}
	
	printf("%d\n", num);

	return 0;
}