#include<stdio.h>
#include<string.h>
char s[100005],a[100005],stack2[100005];
int stack1[100005];
int cal(int a,char c,int b)
{
	if(c=='*') return a*b;
	if(c=='/') return a/b;
	if(c=='+') return a+b;
	if(c=='-') return a-b;
}
int main()
{
	int i,j=0,sum=0,num1=0,num2=0;
	gets(s);
	for(i=0;s[i]!='=';i++)
	if(s[i]!=' ') a[j++]=s[i];
	a[j]='\0';
	i=0;
	while(i<j)
	{
		sum=0;
		while(a[i]>='0'&&a[i]<='9')  
		{
			sum=sum*10+a[i]-'0';
			i++;
		}
		if(stack2[num2]=='*'||stack2[num2]=='/')
		{
		    sum=cal(stack1[num1],stack2[num2],sum);
		    num2--;num1--;
		}
		stack1[++num1]=sum;
		if(a[i]!='\0') stack2[++num2]=a[i];
		i++;
	}
//	for(i=1;i<=num1;i++)
//	printf("%d\n",stack1[i]);
	sum=stack1[1];
	for(i=2;i<=num1;i++)
	{
//		printf("%d%c%d\n",sum,stack2[i-1],stack1[i]);
		sum=cal(sum,stack2[i-1],stack1[i]);
	}
	printf("%d",sum);
	return 0;
 } 



