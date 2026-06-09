#include <stdio.h>
#include <string.h>
int main()
{	char str[1000];
	gets(str);
	int i,j;
	for(i=0,j=0;str[i]!='\0';i++)
	if(str[i]!=' ')
	str[j++]=str[i];
	str[j]='\0';//删去空格
	
	int a[1000]={0};//存所有数
	char b[1000];//存所有符号 
	
	int temp;
	int cnt1=0;
	int cnt2=0; 
	int sum=0;
	for(i=0;str[i]!='=';i++)
	{	if(str[i]>='0'&&str[i]<='9')
		{	temp=0;
			for(j=i;str[j]>='0'&&str[j]<='9';j++)
			{	
				temp=temp*10+str[j]-'0';//提取出数字	
			}
			a[++cnt1]=temp;
			i=j-1; 
		}
		else
		{	b[++cnt2]=str[i];//提取出符号 
		}
	}
	b[0]='0';//随便赋个值 
	if(cnt2==0)
	printf("%d",a[1]);//特殊情况 
	else
	{	for(i=1;i<=cnt2;i++)
		{	
			if(b[i]=='*')
			{	a[i+1]=a[i]*a[i+1];
				a[i]=0;
					if(b[i-1]=='+'||i==1)
					b[i]='+';
					else
					b[i]='-';
			 }
			else if(b[i]=='/')
			{	a[i+1]=a[i]/a[i+1];
				a[i]=0;
					if(b[i-1]=='+'||i==1)
					b[i]='+';
					else
					b[i]='-';
			} 
	 	}
	 	sum=a[1];
		for(i=1;i<=cnt2;i++)
		{	if(b[i]=='+')
			{	sum+=a[i+1];
			}
			else if(b[i]=='-')
			sum-=a[i+1];
		}
		printf("%d",sum); 
	} 
	return 0;
}

