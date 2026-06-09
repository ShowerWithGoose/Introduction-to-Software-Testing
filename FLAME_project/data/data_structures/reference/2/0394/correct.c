
#include<stdio.h>  //先用数组将所有数字存起来 再用一个字符串组 将所有的运算符号存起来 然后根据运算符的优先级来进行计算 
#include<string.h>
#include<math.h>
void f(char s[])
{
	int i,j;
	for(i=j=0;s[i]!='\0';i++)
	if(s[i]!=' ')
	s[j++]=s[i];
	s[j]='\0';
}
int main ()
{		
	int i,j=0,k=0;
	char s[10000];
	char fu[10000];
	gets(s);
	f(s); //去空格 
	//puts(s);
	int shuzi[10000]={0};
	for(i=0;s[i]!='\0';i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{shuzi[k]+=s[i]-'0';
		 for(;s[i+1]>='0'&&s[i+1]<='9';i++)
		 {
		 	shuzi[k]*=10;
		 	shuzi[k]+=s[i+1]-'0';
		  } 
		  k++;
		}
	}
	//数字个数为k； 
	//for(i=0;i<3;i++)
	//printf("%d ",k);
	for(i=0;s[i]!='\0';i++)
	{
		if(s[i]=='*'||s[i]=='-'||s[i]=='+'||s[i]=='/')
		{
			fu[j++]=s[i];
		}
	 }
	 //printf("%d",k-j) ;
	 int ans=0,m,n;
	 for(i=0;i<j;i++)
	 {
	 	if(fu[i]=='*')
	 	{
	 		shuzi[i]*=shuzi[i+1];
		 
		 for(m=i+1;fu[m]=='*'||fu[m]=='/';m++)
		 {
		 	if(fu[m]=='*')
		 	shuzi[i]*=shuzi[m+1];
		 	else
		 	shuzi[i]/=shuzi[m+1];
		 }i=m;
		 }
		 if(fu[i]=='/')
	 	{
	 		shuzi[i]/=shuzi[i+1];
		 
		 for(m=i+1;fu[m]=='*'||fu[m]=='/';m++)
		 {
		 	if(fu[m]=='*')
		 	shuzi[i]*=shuzi[m+1];
		 	else
		 	shuzi[i]/=shuzi[m+1];
		 }i=m;
		 }
		 
	 }
	 for(i=0;i<j;i++){
	 	if(fu[i]=='+')
	 	ans+=shuzi[i+1];
	 	if(fu[i]=='-')
	 	ans-=shuzi[i+1];
	 }
	 ans+=shuzi[0];
	 printf("%d",ans);
	return 0;
}

