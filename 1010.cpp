//1010��

//�⺻������ �������̴� ���չ����̳� int���� ������ �ʰ��ع����� 30! �̹Ƿ� dp�� ������Ѵ�.

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