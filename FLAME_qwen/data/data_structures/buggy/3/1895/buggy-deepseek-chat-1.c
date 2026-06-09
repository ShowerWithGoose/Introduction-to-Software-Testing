#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include<stdlib.h>
int main()
{
    char num[105];
    scanf("%s",&num); // @@ Error: scanf with %s expects a char* argument, but &num is char(*)[105]. Should be num (without &).
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
        printf("%c",num[sumb+1]); // @@ Error: When sumb is the count of leading zeros, num[sumb+1] may be out of bounds if the number is "0.xxx" (e.g., "0.5" has sumb=1, num[2] is '5', correct; but for "0.0" or "0" it may access invalid index). Also, for input like "0.001", sumb=1, num[2]='0', but the first non-zero digit is at index 4, so this logic is incorrect.
        if((sumb+2)==strlen(num))
        {
            printf("e-%d",sumb);
        }
        else
        {
            printf(".");
            for(k=sumb+2;k<=strlen(num);k++) // @@ Error: Loop condition k<=strlen(num) accesses num[strlen(num)] which is out of bounds (null terminator). Should be k<strlen(num).
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
        printf("e%d",suma);
    }
    
}