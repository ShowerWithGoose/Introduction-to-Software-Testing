#include <stdio.h>
#include <string.h>
char array[6000]={0};
int zhengshu(int *a)
{
    int x=0,y=*a;
    for(;array[y]>='0'&&array[y]<='9';y++)
        x=10*x+array[y]-'0';
    *a=y;
    return x;
}
int chengchu(int *a)
{
    int x1=1,y1=*a;
    if(array[y1]=='-')    x1=-1;
    *a=*a+1; // @@ Unconditionally advancing the pointer here skips the character even if it is a digit, causing incorrect parsing of the first term. The increment should be conditional on the character being a sign.
    x1*=zhengshu(a);
    while(array[*a]=='*'||array[*a]=='/')
    {
        switch(array[*a])
        {
            case'*':*a=*a+1;x1*=zhengshu(a);break;
            case'/':*a=*a+1;x1/=zhengshu(a);break;
        }
    }
    return x1;
}
int main()
{
    gets(array);
    int b=0;
    int i,j;
    for(i=0,j=0;array[i]!=0;i++)
    {
        if(array[i]!=' ')    array[j++]=array[i]; 
    }
    array[j]=0;
    int sum=zhengshu(&b); // @@ This reads only a single number for the first term, ignoring possible multiplication/division operators that should be part of the first term. It should instead parse a full term (including '*' and '/') to correctly handle expressions like "1*2+3=".
    while(array[b]!='=')
        {sum+=chengchu(&b);
        }
    printf("%d",sum);
    return 0;
}