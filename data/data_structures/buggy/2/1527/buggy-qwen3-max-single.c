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
    if(array[y1]=='-')    x1=-1; // @@ [This logic incorrectly assumes that a '-' at position y1 is a unary minus, but in the context of the main loop, the first term is already consumed by zhengshu(), so any '-' encountered here is actually a binary operator, not a sign. This leads to incorrect handling of subtraction and misinterpretation of operators as signs.]
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
    gets(array); // @@ [The function 'gets' is unsafe and has been removed from modern C standards (since C11). Many compilers no longer support it, leading to a compilation error. It should be replaced with 'fgets'.]
    int b=0;
    int i,j;
    for(i=0,j=0;array[i]!=0;i++)
    {
        if(array[i]!=' ')    array[j++]=array[i]; 
    }
    array[j]=0;
    int sum=zhengshu(&b);
    while(array[b]!='=')
        {sum+=chengchu(&b); // @@ [The logic assumes every subsequent term is added, but 'chengchu' may return a negative value to represent subtraction. However, because the initial parsing in 'chengchu' treats '-' as a unary sign rather than an operator, and the main loop always adds the result of 'chengchu', expressions like "5 - 1" become "5 + (-1)" only if '-' is correctly interpreted. But due to flawed operator handling in 'chengchu', this fails. Moreover, after the first number, the next character is an operator, but 'chengchu' expects to start with an optional '-', which breaks on '+' or other operators. This causes incorrect parsing when encountering '+'.]
        }
    printf("%d",sum);
    return 0;
}