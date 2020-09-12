#include<stdio.h>
double Calculation(int a, int b, int c, int d, int e, int f)
{
	double num1,num2,num3,result;
	num1=((double)(((a-d)*(a-d))+((b-e)*(b-e))));//two circle's distance
	num2=((double)(c+f)*(c+f));//outside r
    num3=((double)(c-f)*(c-f));//inside r
	if((num1==0)&&(num3==0))
	{
		result=-1;//infinite
	}
	else if((num1>num2)||(num1<num3))
	{
		result=0;//0
	}
    else if((num1==num2)||(num1==num3))
	{
		result=1;//1
    }
	else
    {
		result=2;//2
	}

	return result;
}


int main()
{
	int a,i,answer;
	scanf("%d",&a);

	for(i=0; i<a; i++)
	{
		int x1,y1,r1,x2,y2,r2;
		scanf("%d %d %d %d %d %d",&x1,&y1,&r1,&x2,&y2,&r2);
		answer=Calculation(x1,y1,r1,x2,y2,r2);
		printf("%d\n",answer);
	}
	return 0;
}