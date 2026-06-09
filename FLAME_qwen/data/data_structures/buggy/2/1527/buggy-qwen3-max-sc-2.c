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
    if(array[y1]=='-')    x1=-1; // @@ [This logic incorrectly assumes that a '-' at position y1 is part of the current term's sign, but in expressions like "5 - 2", the '-' is a binary operator, not a unary sign. This causes incorrect parsing of subtraction as negative numbers.]
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
    gets(array); // @@ [The function 'gets' is unsafe and has been removed from modern C standards (C11 onwards). Many compilers no longer support it, leading to a compilation error. It should be replaced with 'fgets'.]
    int b=0;
    int i,j;
    for(i=0,j=0;array[i]!=0;i++)
    {
        if(array[i]!=' ')    array[j++]=array[i]; 
    }
    array[j]=0;
    int sum=zhengshu(&b);
    while(array[b]!='=')
        {sum+=chengchu(&b); // @@ [The logic assumes every term after the first is added, but 'chengchu' may return a negative value only if it starts with '-', which is misinterpreted. Subtraction is not handled correctly because '-' is treated as part of the next term rather than an operator. This leads to wrong results like interpreting "5 - 2" as 5 + (-2) only if '-' is at start of term, but the loop structure doesn't account for standalone '-' operators properly.]
        }
    printf("%d",sum);
    return 0;
}