#include<stdio.h>
#include<string.h>
char str[200];
int ab[200];
char cd[200];
void Zhuan(char s[],int a[]);
void zhuan(char s[],char b[]);
void squeez(char s[],char c);
int cal(int a,int b,char c);
int sum(int b[],int n);
int Sign(char a);
int main()
{
	int i,m,n=0;
	int j=1;
	int k=0;
	int flag=0;
	int box[200]={0};
	gets(str);
	squeez(str,' ');
	m=strlen(str);
	Zhuan(str,ab);
	zhuan(str,cd);
	box[0]=ab[0];
	for(i=0;i<m-1;i++)
	{
		if(str[i]<'0'&&str[i]!='-')
		{
			k++;
			break;
		}
	}
	if(k==0)
	{
		squeez(str,'=');
		printf("%s\n",str);
	}
	else
	{
		m=strlen(cd);
		for(i=0;i<m;i++)
		{	
			if(Sign(cd[i])>Sign(cd[i+1]))
			{
				box[n]=cal(box[n],ab[i+1],cd[i]);
			}
			else if(Sign(cd[i])<Sign(cd[i+1]))
			{
				n++;
				box[n]=ab[i+1];
				if(cd[i]=='-')
				box[n]=box[n]*(-1);
			}
			else
			{
				box[n]=cal(box[n],ab[i+1],cd[i]);
			}
		}
		printf("%d",sum(box,n));
	}
	printf("\n");
	return 0;
}
void Zhuan(char s[],int a[])
{
	int i,j=0,n;
	int k=0;
	int w=0;
	n=strlen(s);
	for(i=0;i<n;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
		a[j]=10*a[j]+s[i]-'0';	
		w++;
		if(s[i]>='0'&&s[i]<='9'&&s[i+1]>='0'&&s[i+1]<='9')
		w--;
		}
		else
		{	
			j+=w;
			w=0;
			continue;
		}
	}
}
void squeez(char s[],char c)
{
	int i,j,k;
	for(i=j=0;s[i]!='\0';i++)
	if(s[i]!=c)
	{
	s[j++]=s[i];
	}
	s[j]='\0';
}
int Sign(char a)
{
	if(a=='+'||a=='-')
	return 1;
	if(a=='*'||a=='/')
	return 2;
}
int sum(int b[],int n)
{
	int sum=0;
	int i;
	for(i=0;i<=n;i++)
	sum+=b[i];
	return sum;
}
void zhuan(char s[],char b[])
{
	int i,j,k;
	k=strlen(s);
	for(i=0,j=0;i<k;i++)
	{
		if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/')
		{
			b[j]=s[i];
			j++;
		}
	}
}
int cal(int a,int b,char c)
{
	if(c=='+')
	return (a+b);
	if(c=='-')
	return (a-b);
	if(c=='*')
	return (a*b);
	if(c=='/')
	return a/b;	
}

