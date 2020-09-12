// 2556 별찍기

// 그냥 정사각형 별찍기

#include <cstdio>
int main() {
    int num;
    scanf("%d",&num);
    for (int i = 1; i <= num; i++)
    {
        for (int j = 1; j <= num; j++)
            printf("*");
        printf("\n");
    }
    return 0;
}