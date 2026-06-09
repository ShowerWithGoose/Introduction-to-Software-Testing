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
    if(array[y1]=='-')    x1=-1; // @@ The logic for handling negative numbers or subtraction is flawed. It assumes a '-' always indicates a negative sign for the current term, but in an expression like "100 - 50", the '-' is a binary operator between terms. By consuming the '-' here and treating the next number as negative, it fails to correctly handle the precedence when this term is added/subtracted to the running sum in main. Specifically, `chengchu` should only handle * and / operators. The +/- operators should be handled in the main loop. If the previous operator was '-', the main loop should subtract the result of `chengchu`. This function incorrectly tries to absorb the sign.
    *a=*a+1; // @@ This advances the pointer past the '-' sign identified above. If there was no '-' (positive number), this skips the first digit of the number because `zhengshu` expects to start at the digit. Wait, if `array[y1]` is not '-', x1 remains 1. Then `*a` is incremented. If `array[*a]` was a digit, we just skipped it. This is a major bug. It should only increment if a sign was consumed.
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
        {sum+=chengchu(&b); // @@ This always adds the result of chengchu. It does not account for the operator (+ or -) that precedes the term returned by chengchu. The parser needs to read the operator before calling chengchu to decide whether to add or subtract.
        }
    printf("%d",sum);
    return 0;
}