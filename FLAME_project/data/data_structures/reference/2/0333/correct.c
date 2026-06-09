#include <stdio.h>
int main()
{
    int ret=0;
    int n1,n2;
    char s1='+';//初始运算符，把第一个运算结果加进最终结果
    char s2,s3;
    while (1)
    {
        scanf("%d %c",&n1,&s2);//输入前一个数和运算符
        while(s2=='*'||s2=='/')//计算乘除
        {
            scanf("%d %c",&n2,&s3);//输入后一个数和下一个运算符
            if(s2=='*')
			n1*=n2;
			else 
			n1/=n2;
            s2=s3;//把后一个运算符作为当前运算符
        }
        if(s1=='+')//结果加减
		ret+=n1;
        else if(s1=='-')
		ret-=n1;
 		s1=s2;//把后一个运算符作为当前运算符
 		if(s1=='=')//结束计算
		{
		 	printf("%d\n",ret);
			break;
		}
    }
    return 0 ;
}
 


