#include<stdio.h>
#include<string.h>
int main()
{
	char c[10000];
	gets(c);
	int i,ans=0,j=0,k=0,num[1000]={0},a=0;
	char f[1000]={'\0'};
	for(i=0;c[i]!='=';i++)
	{
		if(c[i]>='0'&&c[i]<='9')//这里不用另外写一个ipow的函数 
			a=a*10+c[i]-'0';
		else if(c[i]=='+'||c[i]=='-'||c[i]=='*'||c[i]=='/')
		{
			num[j++]=a;
			a=0;
			f[k++]=c[i];
		}
	} 
	num[j]=a;//要把最后一个数也存进去 
	if(k==0) printf("%d",num[0]);
	else 
	{
		for(i=0;i<k;i++)
		{
			if(f[i]=='/')//这里不用换两个数组重新存加减的式子 
			{
				num[i+1]=num[i]/num[i+1];
				num[i]=0;
				if(i==0) f[i]='+';
				else f[i]=f[i-1];
			}
			else if(f[i]=='*')
			{
				num[i+1]=num[i]*num[i+1];
				num[i]=0;
				if(i==0) f[i]='+';
				else f[i]=f[i-1];
			}
		}
		ans=num[0];//不能写进循环里 
		for(i=0;i<k;i++)
		{
			if(f[i]=='+') ans=ans+num[i+1];
			else ans=ans-num[i+1];
		}
		printf("%d",ans);
	}
	
	return 0;
}


