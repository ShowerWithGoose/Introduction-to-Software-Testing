#include<stdio.h>
#include<string.h>
char start[100],nospace[100],calcu[100];
int number[100];
void removespace(char c[],char d[])
{
	int i=0,j=0;
	for(i=0,j=0;c[i]!='\0';i++,j++)
	{
	    if(c[i]!=' ')
	        d[j]=c[i];
	    else
	        j--;
	}
	d[j+1]='\0';       
}
int calculation(int a,int b,char c)
{
	if(c=='+')
	    return a+b;
	if(c=='-')
	    return a-b;
	if(c=='*')
	    return a*b;
	if(c=='/')
	    return a/b;
}
void swap(char a[])
{
	int i=0;
	char temp;
	for(i=0;i<strlen(a)/2;i++)
	{
		temp=a[i];
		a[i]=a[strlen(a)-i-1];
		a[strlen(a)-i-1]=temp;
	}
}
void download(char a[])
{
	int m=0,n=0,i,k,num=0;
	for(i=0;a[i]!='=';i++)
	{
		if(a[i]=='+'||a[i]=='-'||a[i]=='*'||a[i]=='/')
		{
			calcu[m]=a[i];
			m++;
		}
		else
		{
			num=0;
		    for(k=i;a[k]>='0'&&a[k]<='9';k++,i++)
			{
			    num=num*10+(a[k]-'0');	
			}	
			number[n]=num;
			n++;
			i--;
		}
	}
}
int main()
{
	int st,answer=0,flag=0;
	for(st=0;st<100;st++)
	    number[st]=-1;
	gets(start);
	removespace(start,nospace);
	download(nospace);
    int calnum=strlen(calcu);
    int numnum=strlen(calcu)+1;
    int gocal=0;
    for(gocal=0;gocal<strlen(calcu);gocal++)
    {
    	if(calcu[gocal]=='*'||calcu[gocal]=='/')
    	{
    		number[gocal]=calculation(number[gocal],number[gocal+1],calcu[gocal]);
    		gocal++;
    		for(;gocal+1<=strlen(calcu)+1;gocal++)
    		{
    			number[gocal]=number[gocal+1];
    			calcu[gocal-1]=calcu[gocal];
    			if(gocal==strlen(calcu))
    				number[gocal+1]=-1;
			}
			gocal=-1;
		}
	}
	answer=number[0];
	for(gocal=0;gocal<strlen(calcu);gocal++)
		answer=calculation(answer,number[gocal+1],calcu[gocal]);
	printf("%d",answer);
	return 0;
}   



