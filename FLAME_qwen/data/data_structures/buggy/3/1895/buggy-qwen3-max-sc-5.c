#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include<stdlib.h>
int main()
{
    char num[105];
    scanf("%s",&num); // @@ [Using &num is incorrect; num is already a pointer to the first element of the array. Should be scanf("%s", num);]
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
        printf("%c",num[sumb+1]); // @@ [If the input is "0.00123", sumb becomes 2 (index of first non-zero after decimal), but num[sumb+1] accesses '1', skipping the correct first significant digit at num[sumb]. Also, if all digits after decimal are zero (though problem says no trailing zeros), this would access out-of-bound or wrong index.]
        if((sumb+2)==strlen(num))
        {
            printf("e-%d",sumb);
        }
        else
        {
            printf(".");
            for(k=sumb+2;k<=strlen(num);k++) // @@ [Loop condition k<=strlen(num) causes reading beyond string end; should be k < strlen(num). Also, starts printing from sumb+2, skipping one digit after the first significant digit.]
            {
                printf("%c",num[k]);
            }
            printf("e-%d",sumb);    
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
        printf("e%d",suma); // @@ [suma counts digits before decimal point excluding the first digit, but exponent should be (number of digits before decimal - 1). For "123.45", digits before decimal = 3, exponent should be 2, but suma = 2 (correct in this case). However, logic fails if there's no decimal point — but problem states input always has digits before and after decimal. Still, edge cases may fail.]
    }
    
}