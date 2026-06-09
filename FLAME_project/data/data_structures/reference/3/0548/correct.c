#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
char s[120];
int main()
{
int b[120];
int ws=0,zf=0,bj=0,q=0,k=0,zs,i=0;
gets(s);
for(int i=0;i<strlen(s);i++)
{if(s[0]=='-')
zf=1;
if(s[i]=='.')
bj=1;
if(bj==1)
ws++;
if(s[i]!='0'&&s[i]!='-'&&s[i]!='.')
q=1;
if(q==1&&s[i]!='.')
b[k++]=s[i] - '0';
}
ws--;
if(zf==1)
printf("-");
for(i==0;i<k;i++)
{
if(i==1)
printf(".%d",b[i]);
else printf("%d",b[i]);
}
zs=k-1-ws;
printf("e%d",zs);
return 0;}

