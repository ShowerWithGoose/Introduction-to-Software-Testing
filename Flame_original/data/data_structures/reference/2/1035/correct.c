#include<stdio.h>
char s[10000];
int get_num(int m,int n)
{
	int ans=0,i;
	for(i=m;i<=n;i++)
	{
		ans=ans*10+s[i]-'0';
	}
	return ans;
}
int mul_div(int m,int n)
{
	int begin=m,i,tmp=0,ans=1,flag=0;
	
	for(i=m;i<=n;i++)
	{
		if(s[i]=='*'||s[i]=='/'||i==n)   //注意边界，i==n之前也有一个值，但没有乘除号 
		{
			if(i==n) tmp=get_num(begin,n);
			else tmp=get_num(begin,i-1);
			//printf("tmp=%d\n",tmp);//
			begin=i+1;
			if(ans>0) ans*=tmp;
			else if(ans<0) ans=ans*(-1)/tmp;
			if(s[i]=='/') ans*=-1;     //用ans的符号来记录ans和tmp之间是乘还是除 
			flag=1;
		}
	}
	if(flag==0) ans=get_num(m,n);       //如果都是数字，中间没有符号的情况 
	return ans;
}

int main()
{
	
	gets(s);
	int a[10000];
	int i,j,k,begin,sum=0;
	for(i=0;i<1000;i++) a[i]=1;
	for(i=j=0;s[i]!='\0';i++)
		if(s[i]!=' ') s[j++]=s[i];
	s[j]='\0';                //删除空格 
	
	i=0,k=0,begin=0;
	while(s[i]!='\0')
	{
		if(s[i]=='+'||s[i]=='-'||s[i]=='=')
		{
			a[k++]*=mul_div(begin,i-1);
			begin=i+1;
			if(s[i]=='-') a[k]*=-1;    //如果为减号，则后面的数值乘以-1 
		}
		i++;
	}
	for(i=0;i<k;i++) sum+=a[i];
	printf("%d\n",sum);
	return 0;
}

