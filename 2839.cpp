// 2839��
//
// �� ������ ��� 	1. ��Ȯ�� ũ�� 5�� 3�� ���뿡 ������ܾ��Ѵ�.
//		2. ���� ���� �ּ�ȭ�ؾ��Ѵ�.
// ���� ���	29 = 5+5+5+5+5+3+1 �̹Ƿ� 1�� 3�� ���뿡 ��� ���� ���� �� ����.
// ����		29 = 5+5+5+5+3+3+3 ���� �� �����༭ �ؾ��Ѵ�.
//
// �� �� ������� �ּ�ȭ�Ϸ��� �ִ��� ũ�� 5�� ���븦 ���� ����ؼ� ��ƾ� �Ѵ�. 
// �׷��Ƿ� ��� �Է°�(3~5000)�� ���͵� ũ�Ⱑ 3�� ����� 0~4�� ����Ѵ�. 
// (5�� �̻� �� 15�� �뷮�� ũ�� 5�� ���� 3���� ����ϸ� �ǹǷ� => ����) 18 : 3*6 (x) / 5*3+3 (o) )
// ���� ũ�� 3�� ���븦 ����ϴ� ��� 5������ 5�ǹ���� ���� 0,3,6,9,12�� ������ ����.
// ������� 1247�� �뷮�� ���� ��, 1247 = 245*5 + 12 �̹Ƿ� (ũ�� 5 245��, ũ�� 3 4��) ����ϸ� �ȴ�.
// ���⼭ 0,3,6,9,12 �� 5�� ���� �������� 0,3,1,4,2 �� 5�� ���� ������ ���θ� �����ϱ⿡ 15 �̻��� �������� �ȵǴ� ���� ����.
// ��, -1���� ��µǾ�� �ϴ� ���� 15 �̸��� �ڿ��� �߿� ������ �Է��� ������ 3~5000 �̹Ƿ� 4,7�� �ȴ�.

#include<cstdio>

int main(){
    
    int N;
    scanf("%d",&N);
    
    if(N==4||N==7)
        printf("-1\n");
    else if(N%5==0)
        printf("%d\n",N/5);
    else if((N-3)%5==0)
        printf("%d\n",(N-3)/5+1);
    else if((N-6)%5==0)
        printf("%d\n",(N-6)/5+2);
    else if((N-9)%5==0)
        printf("%d\n",(N-9)/5+3);
    else
        printf("%d\n",(N-12)/5+4);
    return 0;
}