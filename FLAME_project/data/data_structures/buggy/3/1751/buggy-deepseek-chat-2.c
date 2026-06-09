#include<stdio.h>
#include<string.h>
int main()
{
    char num[105];
    char num1[105],num2[105];
    gets(num);
    int i=0,j=0;
    for(i=0,j=0;num[i]!='\0';i++)
    {
        if(num[i]!='.')
        {
            num1[j++]=num[i];
        }
        else
        {
            break;
        }
    }
    for(i+=1,j=0;num[i]!='\0';i++)
    {
        num2[j++]=num[i];
    }
    
    int a=(int)strlen(num1);
    if(a==1)
    {
        if(num1[0]!='0')
        {
            for(i=0;num[i]!='\0';i++)
            {
                printf("%c",num[i]);
            }
            printf("e0");
        }
        else if(num1[0]=='0')
        {
            for(i=0;num2[i]!='\0';i++)
            {
                if(num2[i]!='0')
                {
                    break;
                }
            }
            int k=i;
            printf("%c",num2[k]);
            if(num2[k+1]!='\0')
            {
                printf(".");
            }
            for(i+=1;num2[i]!='\0';i++) // @@ Error: The loop variable i is modified incorrectly. After the previous loop, i is the index of the first non-zero digit in num2. Here i+=1 increments i by 1, but then the loop condition uses num2[i] which may skip the first digit after the decimal point. It should start from k+1 instead of i+1.
            {
                printf("%c",num2[i]);
            }
            printf("e-%d",k+1);
        }
    }
    else
    {
        printf("%c.",num1[0]);
        for(i=1;num1[i]!='\0';i++)
        {
            printf("%c",num1[i]);
        }
        for(i=0;num2[i]!='\0';i++)
        {
            printf("%c",num2[i]);
        }
        printf("e%d",a-1);
    }
    return 0;
}