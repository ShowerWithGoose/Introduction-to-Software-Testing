#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
char str[100000];
int main(void){
    int i,k = 0,num = 0;
    gets(str);
    for(i = 0;i < strlen(str);i++)
    {
        if(str[i] != '.')
            num++;
        else if(str[i] == '.')
            break;
    }    
    if(num == 1)
    {
        if(str[0] == '0')
        {
            num = 0;
            for(i = 0;i < strlen(str);i++)
            {
                if(str[i] == '0'&&k>0)
                {
                    num--;
                }
                else if(str[i] != '.')
                {
                    printf("%c",str[i]);
                    k++;
                    if(k == 1&&i!=strlen(str)-1)
                    {
                        printf(".");
                    }
                } 
            }
            printf("e%d",num); // @@ The exponent calculation is incorrect. For input "0.9", the loop sets num=0 initially, then when encountering '9', it prints "9." and k becomes 1, but num remains 0, resulting in "9.e0" instead of "9e-1". The exponent should be -1 (the number of zeros after the decimal point plus one, negated).
        }
        else
        {
            printf("%se0",str); // @@ For input like "8.9876", this outputs "8.9876e0", but the expected output should be "8.9876e0" which is correct per the problem. However, for input "0.9", this branch is not taken because str[0]=='0', so the error is in the previous branch.
        }
    }
    else
    {
        for(i = 0;i < strlen(str);i++)
        {
            if(i == 1)
            {
                printf(".%c",str[i]); // @@ This incorrectly inserts a decimal point after the first digit. For input like "12.34", it prints "1.2.34" instead of "1.234e1". The logic for handling numbers with more than one digit before the decimal point is flawed.
            }
            else if(i != num)
            {
                printf("%c",str[i]);
            } 
        } 
        printf("e%d",num-1);
    }
    return 0;
}