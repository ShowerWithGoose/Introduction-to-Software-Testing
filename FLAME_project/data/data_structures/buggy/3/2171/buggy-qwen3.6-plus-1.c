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
            num = 0; // @@ [The variable 'num' is used to store the exponent. For 0.9, the exponent should be -1. Initializing it to 0 and failing to update it correctly leads to the wrong exponent.]
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
            printf("e%d",num); // @@ [For input 0.9, the loop prints "0.9" because the condition 'str[i] == '0' && k>0' is false for the first '0' (k=0) and true for nothing else, but the else-if prints non-dots. Wait, for 0.9: i=0 ('0'), k=0. str[0]=='0' && k>0 is false. str[0]!='.' is true. Prints '0'. k becomes 1. k==1 && i!=2 is true. Prints '.'. i=1 ('.'). Skipped. i=2 ('9'). str[2]=='0' false. str[2]!='.' true. Prints '9'. k becomes 2. Output so far "0.9". Exponent is 0. Result "0.9e0". The logic for handling 0.X cases where X is non-zero is flawed. It should skip the leading zero and decimal point, print the significant digits, and calculate the negative exponent correctly.]
        }
        else
        {
            printf("%se0",str);
        }
    }
    else
    {
        for(i = 0;i < strlen(str);i++)
        {
            if(i == 1)
            {
                printf(".%c",str[i]);
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