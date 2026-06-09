#include <stdio.h>
#include <string.h>
int num=0;
int readnum()
{
	int a;
	scanf("%d",&a);
	return a;
}
int readop()
{
	char b;
	do
	{
		scanf("%c",&b);
	}
	while(b==' ');
	return b;
}
int H(char a,char b)
{
	if(a=='*'||a=='/')
		return 0;
	else if(b=='*'||b=='/')
		return 1;
	else
		return 0;
	
}
int F(int x,char a,int y)
{
	if(a=='*')
		return x*y;
	if(a=='/')
		return x/y;
	if(a=='+')
		return x+y;
	if(a=='-')
		return x-y;
}
int main ()
{
	char ch[1005];
	char ch0[1005];
	int chnum[1005];
	char chch[1005];
	int G[1005];
	int k=0;
	int num2=0;
	int m=0;
//	gets(ch);
	for(int i,j=0;i<strlen(ch);i++)
	{
		if(ch[i]!=' ')
		{
			ch0[j]=ch[i];
			j++;
		}
		if(ch0[i]>='0'&&ch0[i]<='9')
			num++;
		
	}
	if(num==(strlen(ch0)-1))
	{
		for(int k=0;k<strlen(ch0)-1;k++)
			printf("%c",ch0[k]);
	}
//	for(int i=0;i<strlen(ch0)-1;i++)
//	{
//		if(ch0[i]=='+'||ch0[i]=='-')
//		{
//			for(int j=1;j<strlen(ch0);j++)
//			{
//				if(ch0[i+j]=='+'||ch0[i+j]=='-')
//				{
//					printf("111");
//					num2++;
//					for(int k=1;k<j;k=k+2)
//					{
//						chnum[k]=1*ch0[i+k];
//						printf("%d\n",chnum[k]);
//					}
//					for(int k=2;k<j;k=k+2)
//					{
//						chch[k]=ch0[i+k];
//					
//					}
//					for(int k=1;k<j;k=k+2)
//					{
//						chnum[k+2]=F(chnum[k],chch[k+1],chnum[k+2]);
//					}
//					G[m]=chnum[k+j-1];
//					m++;
//					
//				}
//			}
//		}
//	}
	int a,b,c;
	char op1,op2;
	a=readnum();
	op1=readop();
	if(op1=='=')
	{
		printf("%d",a);
	}
	if(op1!='=')
	{
		b=readnum();
		op2=readop();
		if(op2=='=')
		{
			printf("%d",F(a,op1,b));
		}
		else{
			
			while(op2!='=')
			{
				c=readnum();
				if(H(op1,op2)==0)
				{
					a=F(a,op1,b);
					b=c;
					op1=op2;
				}
				else
				{
					b=F(b,op2,c);
					
				}
				op2=readop();
				
			}
			printf("%d",F(a,op1,b));
		}
	}
	return 0;
}

