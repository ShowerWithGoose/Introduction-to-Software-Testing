#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define cin(k) scanf("%d",&k)
char ch[100005];
int l,dot,use;
signed main()
{
	scanf("%s",ch);
	int len=strlen(ch);
	if(ch[0]=='-')
	{
		l=1;
		for(int q=1;q<len;q++)
			ch[q-1]=ch[q];
		len--;
	}
	for(int q=0;q<len;q++)
		if(ch[q]=='.')
			dot=q;
	if(!dot)	dot=len;
	while(ch[use]=='0'||ch[use]=='.')
	{
		use++;
		if(use>len)
		{
			printf("0");
			return 0;
		}
	}
//printf("%d %d %d",l,dot,use);
	printf("%c",ch[use]);
	if(use<len-1)	printf(".");
	for(int q=use+1;q<len;q++)
		if(ch[q]!='.')
			printf("%c",ch[q]);
	printf("e%d",dot>use?dot-use-1:dot-use);
}

