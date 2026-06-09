#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include<stdlib.h>
int main()
{
    char num[105];
    scanf("%s",&num); // @@ Using &num is incorrect; num is already a pointer to the first element of the array. Should be scanf("%s", num);
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
        printf("%c",num[sumb+1]); // @@ If the input is "0.00123", sumb becomes 2 (index of first non-zero after decimal), but sumb+1 may be beyond string length or point to '.'; logic fails to skip the decimal point correctly.
        if((sumb+2)==strlen(num))
        {
            printf("e-%d",sumb);
        }
        else
        {
            printf(".");
            for(k=sumb+2;k<=strlen(num);k++) // @@ Loop condition k<=strlen(num) accesses out-of-bounds memory (valid indices are 0 to strlen(num)-1). Should be k < strlen(num).
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
        printf("e%d",suma); // @@ 'suma' counts digits before '.', but if input is like "123.45", it counts '2' and '3' (i=1,2), so suma=2, exponent should be 2, which is correct. However, if input has no decimal point (not per problem spec), this fails. But per problem, input always has digits before and after '.', so maybe okay. However, logic doesn't handle case like "1.23" correctly: suma=0, outputs e0, but should be e0 — actually correct. But overall logic fragile.
    }
    
}