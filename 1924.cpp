// 1924번

// 요일 계산하기 문제
// 2007년 1월1일이 월요일이므로 이때부터 입력된 날짜까지의 일 수 차이를 계산하여 7로 나눈 나머지에 따라 요일 결정

#include<cstdio>

int main(){
    
    int x,y,count=0;
    int m_day[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    scanf("%d %d",&x,&y);
    if(x>1)
    	for(int i=0;i<x-1;i++)
        		count += m_day[i];
    count += y-1;
    switch(count%7){
        case 0:
            printf("MON\n");
            break;
        case 1:
            printf("TUE\n");
            break;
        case 2:
            printf("WED\n");
            break;
        case 3:
            printf("THU\n");
            break;
        case 4:
            printf("FRI\n");
            break;
        case 5:
            printf("SAT\n");
            break; 
        case 6:
            printf("SUN\n");
            break; 
    }
    
    return 0;
}