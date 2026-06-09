#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include<stdlib.h>
int main()
{
    char num[105];
    scanf("%s",&num); // @@ [Using &num is incorrect; num is already a pointer to char array, should be scanf("%s", num);]
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
        printf("%c",num[sumb+1]); // @@ [If the input is "0.00123", sumb becomes 2 (index of first non-zero after decimal), but num[sumb+1] accesses '1', skipping the first significant digit incorrectly in some edge cases; also fails when there's only one significant digit left]
        if((sumb+2)==strlen(num))
        {
            printf("e-%d",sumb);
        }
        else
        {
            printf(".");
            for(k=sumb+2;k<=strlen(num);k++) // @@ [Loop condition k<=strlen(num) causes out-of-bounds access; should be k < strlen(num)]
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
        printf("e%d",suma); // @@ [suma counts digits before '.', but for numbers like "123.45", it gives e2 instead of e2 (correct), but logic fails for numbers without decimal point or with more complex formats; however primary errors are above]
    }
    
}