#include<stdio.h>

int jisuan(int a,char ch,int b);
int dushu();
char duzifu();

int jisuan(int a,char ch,int b)
{
	int jieguo;
	if(ch=='+')
		jieguo=a+b;
	else if(ch=='-')
		jieguo=a-b;
	else if(ch=='*')
		jieguo=a*b;	
	else
		jieguo=a/b;	
		
	return jieguo;		
}

int dushu()
{
	int num;
	scanf(" %d",&num);
	return num;
}

char duzifu()
{
	char ch;
	scanf(" %c",&ch);
	return ch;
}


int main()
{
	int a[2];
	char b[1];
	
	int num;
	char ch;
	
	a[0]=dushu();
	b[0]=duzifu();
	if(b[0]!='=')
		a[1]=dushu();
	while(b[0]!='=')
	{
		if(b[0]=='*'||b[0]=='/')
		{
			a[0]=jisuan(a[0],b[0],a[1]);
			b[0]=duzifu();
			if(b[0]!='=')
				a[1]=dushu();
		}
		else
		{
			ch=duzifu();
			if(ch=='+'||ch=='-'||ch=='=')
			{
				a[0]=jisuan(a[0],b[0],a[1]);
				b[0]=ch;
				if(ch!='=')
					a[1]=dushu();
			}
			else if(ch!='=')
			{
				num=dushu();
				a[1]=jisuan(a[1],ch,num);
			}
			else
				b[0]=ch;
		}
	}
	printf("%d",a[0]);
	
	return 0;
}



