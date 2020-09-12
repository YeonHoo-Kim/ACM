//1010번

//기본적으로 쉬워보이는 조합문제이나 int형의 범위를 초과해버리는 30! 이므로 dp를 써줘야한다.

#include <stdio.h>

int main() {

	int T;
	scanf("%d", &T);
    
    long long dp[31][31];
    for(int i=0;i<=30;i++){
            dp[i][0]=1; dp[i][i]=1;
    }
    for(int i=1;i<=30;i++){
        for(int j=1;j<=30;j++){
            dp[i][j] = dp[i-1][j-1]+dp[i-1][j];
        }
    }
    
	for (int k = 0; k < T; k++) {
        int N,M;
        scanf("%d %d",&N,&M);
        printf("%lld\n",dp[M][N]);
    }
    
	return 0;
}