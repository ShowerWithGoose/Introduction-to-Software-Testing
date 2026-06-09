#include<stdio.h>
int cmp(char a,char b)
{
	if(a>='a'&&b>='a'&&a<='z'&&b<='z'&&a<b)
	return 1;
	if(a>='A'&&b>='A'&&a<='Z'&&b<='Z'&&a<b)
	return 1;
	if(a>='0'&&b>='0'&&a<='9'&&b<='9'&&a<b)
	return 1;
	return 0;
}
int main()
{
	char str[1000],ch[1000];int k=0,i=0;
	scanf("%s",str);
	for(i=0;str[i]!='\0';i++)
	{
		if(str[i]=='-'&&cmp(str[i-1],str[i+1])!=0)
		{
			int m=1;
			if(cmp(str[i-1],str[i+1])==1)
			for(m=1;m<str[i+1]-str[i-1];m++)
			{
				ch[k]=str[i-1]+m;
				k++;
			}
		}
		else
		{
			ch[k]=str[i];
			k++;
		}	
	}
	ch[k]='\0';
	puts(ch);
	return 0;
 } 

