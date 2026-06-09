#include<stdio.h>
#include<string.h>
int isDa(char ch)
{
	if(ch>='A'&&ch<='Z')
	return 1;
	return 0;
}
int isXiao(char ch)
{
	if(ch>='a'&&ch<='z')
	return 1;
	return 0;
}
int isNumber(char ch)
{
	if(ch>='0'&&ch<='9')
	return 1;
	return 0;
 } 
int main()
{
	char a[1000],b[10000],c;
	int i,j;
	scanf("%s",a);
	for(i=j=0;i<strlen(a);i++,j++)
	{
		if(a[i+1]!='-')
		b[j]=a[i];
		else if(a[i+1]=='-')
		{
			if((isDa(a[i])&&isDa(a[i+2]))||(isXiao(a[i])&&isXiao(a[i+2]))||(isNumber(a[i])&&isNumber(a[i+2])))
			{
			for(c=a[i];c<a[i+2];j++,c++)
			b[j]=c;
			i++;
			j--;}
			else
			b[j]=a[i];
		}
	}
	puts(b);
	return 0;
}

