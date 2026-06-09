#include<stdio.h>
#include<string.h>
char a[1005];
int main()
{
    int sum,flag=0,b,c,d;
    gets(a);
    for(int i=0;i<strlen(a);i++)
    {    
        if(flag==0&&a[i]!='0'&&a[i]!='.')
        {
            flag=1;
            b=i;
        }
        if(a[i]=='.')
        {
            c=i;
        }
    }
//    i=strlen(a)
//    while(i>0&&a[i]==0)
//    {
//        
//    }
    for(int i=strlen(a)-1;i>c;i--)
    {
        if(a[i]!='0'&&a[i]!='.')
        {
            d=i;
            break;
        }
    }
    //printf("%d",d);
    if(flag==1)
    {
        for(int i=b;i<=d;i++) // @@ The loop condition `i<=b+d` is incorrect. It should iterate from the first significant digit `b` to the last significant digit `d`. `b+d` calculates an incorrect upper bound, leading to extra characters or garbage output.
        {
            if(i==b+1&&i!=strlen(a)) // @@ The condition for printing the decimal point is flawed. It prints a dot after the second character of the range, but scientific notation requires the dot after the *first* significant digit (index `b`). Also, checking `i!=strlen(a)` is irrelevant here. It should be `if (i == b && b != d)` or similar logic to place the dot correctly between the first digit and the rest.
            printf(".");
            //printf("$");
            if(a[i]!='.')
            printf("%c",a[i]);
        }
        int p;
        if(a[0]=='0')
        p=c-b; // @@ For numbers like 0.9, b=1 (index of '9'), c=1 (index of '.'). The exponent should be -1. The formula `c-b` gives 0. The correct exponent for `0.digits` is `-(b-c)` or `c-b-1` if we consider the shift. Actually, for 0.9, standard form is 9e-1. Shift is 1 position left. Exponent is -1. `c` is index of dot, `b` is index of first sig digit. If `b > c`, exponent is `-(b-c-1)`? No. 0.9 -> 9.e-1. Dot moves from index 1 to index 2 (after 9). Wait, 9 is at index 1. In "9.", dot is after index 0 of the new string. Original index 1. New index 0. Shift is 1. Exponent -1. Formula: `c - b` is `1 - 1 = 0`. Correct formula for `0.xxx` is `c - b`. Wait. 0.09 -> b=2, c=1. Exp -2. `c-b = -1`. Incorrect. It should be `c - b + 1`? No. 0.09 is 9e-2. `1 - 2 = -1`. We need -2. So `c - b - 1`? `1 - 2 - 1 = -2`. Yes. For 0.9: `1 - 1 - 1 = -1`. Yes. So `p = c - b - 1` is likely correct for both cases if unified, or specific logic. The current code has separate branches.
        else
        p=c-b-1;
        if(p>=0)
        printf("e%d\n",p);
        else
        {
            p=-p;
            printf("e-%d\n",p);
        }
        
    }
    else
    printf("0e0\n");
}