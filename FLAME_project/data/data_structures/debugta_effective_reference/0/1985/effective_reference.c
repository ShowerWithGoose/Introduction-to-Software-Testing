#include<stdio.h>
int main()
{
	int k=1,i=0,j=0;
	char m,l;
	char ch[999],s[999];
	gets(ch);
	for(i=0;ch[i]!='\0';i++)
	{
		if(ch[i]=='-'&&((ch[i-1]>=97&&ch[i-1]<=122&&ch[i+1]>=97&&ch[i+1]<=122&&ch[i-1]<ch[i+1]-1)||(ch[i-1]>=65&&ch[i-1]<=90&&ch[i+1]>=65&&ch[i+1]<=90&&ch[i-1]<ch[i+1]-1)||(ch[i-1]>=48&&ch[i-1]<=57&&ch[i+1]>=48&&ch[i+1]<=57&&ch[i-1]<ch[i+1]-1)))
		{
			m=ch[i-1];
			l=ch[i+1];
			for(k=1;k<l-m;k++)
			{
				s[j]=s[j-1]+1;
				j++;
			}
		}
		else {
			s[j]=ch[i];
			j++;
		}
	}
	printf("%s",s) ;
 } 

