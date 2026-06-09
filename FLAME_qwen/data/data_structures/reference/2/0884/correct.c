#include<stdio.h>
#include<string.h>
int pd(char a,char b)
{
	if(b=='*'||b=='/')
	{
		if(a=='+'||a=='-')return 1;
		else return 0;
	}
	else 
	{
		if(a=='+'||a=='-')return 0;
		else return -1;
	}
}
int jisuan(int a,int b,char c)
{
	switch(c)
	{
		case '+':
			return a+b;
			break;
		case '-':
			return a-b;
			break;
		case '*':
			return a*b;
			break;
		case '/':
			return a/b;
			break;	
	}
}
int main()
{
	char in[1000],a[1000],b[1000];
    int c[1000],sizenum,sizeop,l,la,n,i,temp=0,flag,Tmp,j;
	gets(in);
	l=strlen(in);
	for(i=0;i<l;i++)
	if(in[i]!=' ')
	a[la++]=in[i];
	a[la]='\0';
	//puts(a);
	i=0;
	while(i<la)
	{
		if(a[i]<='9'&&a[i]>='0')
		{
			temp=temp*10+a[i]-'0';
		}
		else 
		{
			c[++sizenum]=temp;
			temp=0;
			if(!sizeop)
			b[++sizeop]=a[i];
			else 
			{
				flag=pd(b[sizeop],a[i]);
				while(flag!=1&&sizeop>0)
				{
					Tmp=jisuan(c[sizenum-1],c[sizenum],b[sizeop]);
					b[sizeop--]='\0';
					c[sizenum]=0;
					c[--sizenum]=Tmp;
					flag=pd(b[sizeop],a[i]);
				}
				b[++sizeop]=a[i];
			}
		}
		
		i++;
	}
	printf("%d",c[1]); 
	return 0;
}


