#include<stdio.h>
#include<string.h>


int main()
{
    int x1,x2,x3;
    char s1,s2,s3;
	x1=0;s1='+';
	while(1)
	{
		scanf("%d %c",&x2,&s2);
		while(s2=='*'||s2=='/') //处理乘除 
		{
			scanf("%d %c",&x3,&s3);
			if(s2=='*')
			x2=x2*x3;
			else
			x2=x2/x3;
			
			s2=s3;// 运算符移向下一个 
		}
		if(s1=='+')
		    x1=x1+x2;
		else
		    x1=x1-x2;
		
		    s1=s2;// 运算符移向下一个 
		if(s2=='=')
		{
			printf("%d\n",x1);
			break;
		}
	}
	
	return 0;
}



