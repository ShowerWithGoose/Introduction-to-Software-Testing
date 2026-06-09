#include<stdio.h>
char ch[105];
int main()
{
gets(ch);
int i,j,k;
for(i=0;ch[i]>='0'&&ch[i]<='9';i++)
;
j=i;
for(i=0;ch[i]=='0'||ch[i]=='.';i++)
;
k=i;
if(k<j)
{printf("%c.",ch[k]);
for(i=k+1;ch[i]!='\0';i++)
if(ch[i]!='.')
printf("%c",ch[i]);
printf("e%d",j-k-1);
}
else
{
    if(ch[k+1]!='\0')
        printf("%c.",ch[k]);
    else
        printf("%c",ch[k]);
for(i=k+1;ch[i]!='\0';i++)
printf("%c",ch[i]);
printf("e%d",j-k);
}
return 0;
}

