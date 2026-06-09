#include <stdio.h>
#include <math.h>
#include <string.h>
char arr[1000]={0};
void Suan(int a,int b,int c)
{
	int former=0,latter=0,sum=0;
	for(int i=a+1;i<b;i++)
	{
		former=former*10+arr[i]-'0';
	}
	for(int i=b+1;i<c;i++)
	{
		latter=latter*10+arr[i]-'0';
	}
	if(arr[b]=='*')
	{
		sum=former*latter;
		for(int i=c-1;i>a;i--)
		{
			arr[i]=sum%10+'0';
			sum/=10;
		}
	}
	if(arr[b]=='/')
	{
		sum=former/latter;
		for(int i=c-1;i>a;i--)
		{
			arr[i]=sum%10+'0';
			sum/=10;
		}
	}
}
void Suan2(int a,int b,int c)
{
	int former=0,latter=0,sum=0;
	for(int i=a+1;i<b;i++)
	{
		former=former*10+arr[i]-'0';
	}
	if(arr[0]=='-')
	former*=(-1);
	for(int i=b+1;i<c;i++)
	{
		latter=latter*10+arr[i]-'0';
	}
	if(arr[b]=='+')
	{
		sum=former+latter;
		if(sum<0)
		{
			arr[0]='-';
			sum*=(-1);
		}
		else if(sum>0)
		{
			arr[0]='+';
		}
		for(int i=c-1;i>a;i--)
		{
			arr[i]=sum%10+'0';
			sum/=10;
		}
	}
	if(arr[b]=='-')
	{
		sum=former-latter;
		if(sum<0)
		{
			arr[0]='-';
			sum*=(-1);
		}
		else if(sum>0)
		{
			arr[0]='+';
		}
		for(int i=c-1;i>a;i--)
		{
			arr[i]=sum%10+'0';
			sum/=10;
		}
	}
}
int main()
{
	int i,j,l,m[100]={0},time[100]={0},sign;
	char *pa=NULL;
	gets(arr+1);
	arr[0]='+';
	for(i=j=l=1;arr[i]!='\0';i++)
	{
		if(arr[i]!=' '&&arr[i]!='\t')
		arr[j++]=arr[i];
		if((arr[j-1]=='+'||arr[j-1]=='-'||arr[j-1]=='*'||arr[j-1]=='/')&&m[l-1]!=j-1)
		m[l++]=j-1;
	}
	arr[j]='\0';
	sign=l-1;
	m[sign+1]=j-1;
	for(l=1;l<=sign;l++)
	{
		if((arr[(m[l])]=='*'||arr[(m[l])]=='/')&&(!time[l]))
		{
			for(i=1;l-i>=0;i++)
			{
				if(!time[l-i])
				break;
			}
			for(j=1;l+j<=sign;j++)
			{
				if(!time[l+j])
				break;
			}
			Suan(m[l-i],m[l],m[l+j]);
			time[l]=1;
		}
	}
	for(l=1;l<=sign;l++)
	{
		if(arr[(m[l])]=='+'||arr[(m[l])]=='-')
		{
			for(i=1;l-i>=0;i++)
			{
				if(!time[l-i])
				break;
			}
			for(j=1;l+j<=sign;j++)
			{
				if(!time[l+j])
				break;
			}
			Suan2(m[l-i],m[l],m[l+j]);
			time[l]=1;
		}
	}
	if(arr[0]=='-')
	printf("-");
	arr[(m[sign+1])]='\0';
	for(i=1;i<m[sign+1]-1&&arr[i]=='0';i++)
	;
	pa=&arr[i];
	printf("%s",pa);
 	return 0;
}


