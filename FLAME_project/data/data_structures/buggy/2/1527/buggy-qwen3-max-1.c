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
    if(array[y1]=='-')    x1=-1; // @@ [This incorrectly assumes a '-' at the start of a term is part of the first number in multiplication/division, but it should only apply to the very first number in the entire expression. In subsequent terms (after + or -), the sign is handled by the main loop, not here. This causes misinterpretation of negative factors in products/quotients.]
    *a=*a+1;
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
    int sum=zhengshu(&b);
    while(array[b]!='=')
        {sum+=chengchu(&b); // @@ [The main loop always adds the result of chengchu(), but chengchu() may represent a term that should be subtracted. The sign of the term (based on preceding '+' or '-') is not passed into chengchu(), and chengchu() itself tries to handle '-', leading to double handling or incorrect signs. The design fails to separate parsing of additive operators from multiplicative terms correctly.]
        }
    printf("%d",sum);
    return 0;
}