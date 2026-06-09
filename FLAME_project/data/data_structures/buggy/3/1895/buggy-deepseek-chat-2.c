#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include<stdlib.h>
int main()
{
    char num[105];
    scanf("%s",&num);
    int i,k,suma=0,sumb=0;
    if(num[0]=='0')
    {
        sumb=1;
    }
    for(i=1;i<strlen(num);i++)
    {
        if(num[0]=='0')
        {
            if(num[i]=='0' && sumb==i-1)
            {
                sumb++;
                
            }
        }
        else
        {
            if(num[i]=='.')
            {
                break;
            }
            else
            {
                suma++;
                
            }
        }
    }
    //printf("%d\n%d\n",sumb,strlen(num));
    if(sumb!=0)
    {
        printf("%c",num[sumb+1]); // @@ Error: When the input is "0.00000009123456789012", sumb is 8 (counting leading zeros after decimal point), but num[sumb+1] is num[9] which is '9', correct. However, the exponent calculation is wrong: sumb counts the number of leading zeros after the decimal point, but the exponent should be -(sumb+1) because the first non-zero digit is at position sumb+1, so the exponent is -(sumb+1). For this input, sumb=8, so exponent should be -9, but the code outputs e-8.
        if((sumb+2)==strlen(num))
        {
            printf("e-%d",sumb); // @@ Error: Same exponent issue; should be e-%d with sumb+1.
        }
        else
        {
            printf(".");
            for(k=sumb+2;k<=strlen(num);k++)
            {
                printf("%c",num[k]);
            }
            printf("e-%d",sumb); // @@ Error: Same exponent issue; should be e-%d with sumb+1.
        }
    }
    else
    {
        printf("%c.",num[0]);
        for(k=1;k<strlen(num);k++)
        {
            if(num[k]!='.')
            {
                printf("%c",num[k]);
            }
        }
        printf("e%d",suma);
    }
    
}