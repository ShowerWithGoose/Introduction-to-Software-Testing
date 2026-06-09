#include<stdio.h>
int main()
{
	int a=1,n=0,j=0;
	char m,l;
	char ch[999],cm[999];
	gets(ch);
	for(n=0;ch[n]!='\0';n++)
	{
		if(ch[n]=='-'&&((ch[n-1]>=97&&ch[n-1]<=122&&ch[n+1]>=97&&ch[n+1]<=122&&ch[n-1]<ch[n+1]-1)||(ch[n-1]>=65&&ch[n-1]<=90&&ch[n+1]>=65&&ch[n+1]<=90&&ch[n-1]<ch[n+1]-1)||(ch[n-1]>=48&&ch[n-1]<=57&&ch[n+1]>=48&&ch[n+1]<=57&&ch[n-1]<ch[n+1]-1)))
		{
			m=ch[n-1];
			l=ch[n+1];
			for(a=1;a<l-m;a++)
			{
				cm[j]=cm[j-1]+1;
				j++;
			}
		}
		else {
			cm[j]=ch[n];
			j++;
		}
	}
	printf("%s",cm) ;
 } 

