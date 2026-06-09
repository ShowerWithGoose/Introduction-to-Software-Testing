#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include<math.h>
char x[100000];
int main()
{
scanf("%s",x);
int i,h=1,j,len,t,g;
len=strlen(x);
for(i=0;i<len;i++)
{
	if(x[i]=='.')
	t=i;
	if(x[i]!='.'&&x[i]!='0'&&h==1)
	{
		g=i;
		h=2;
	}
}
printf("%c",x[g]);
if(g!=len-1)
printf(".");
for(i=g+1;i<len;i++)
{
if(i==t)
continue;
else
printf("%c",x[i]);
}
printf("e");
if(t>g)
printf("%d",t-g-1);
else
printf("%d",t-g);
	return 0;
}


