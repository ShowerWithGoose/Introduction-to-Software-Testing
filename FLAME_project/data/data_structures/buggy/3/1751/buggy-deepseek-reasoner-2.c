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
    } // @@ Missing null terminator for num1; should have num1[j]='\0'; after the loop.
    for(i+=1,j=0;num[i]!='\0';i++)
    {
        num2[j++]=num[i];
    } // @@ Missing null terminator for num2; should have num2[j]='\0'; after the loop.
    
    int a=(int)strlen(num1); // @@ Undefined behavior: num1 is not null-terminated.
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
            for(i=0;num2[i]!='\0';i++) // @@ Loop condition uses non-null-terminated num2, may read garbage.
            {
                if(num2[i]!='0')
                {
                    break;
                }
            }
            int k=i;
            printf("%c",num2[k]);
            if(num2[k+1]!='\0') // @@ Depends on null terminator; num2 not terminated, condition likely true erroneously.
            {
                printf(".");
            }
            for(i+=1;num2[i]!='\0';i++) // @@ Same problem: num2 not null-terminated.
            {
                printf("%c",num2[i]);
            }
            printf("e-%d",k+1);
        }
    }
    else
    {
        printf("%c.",num1[0]);
        for(i=1;num1[i]!='\0';i++) // @@ num1 not null-terminated, loop may go out of bounds.
        {
            printf("%c",num1[i]);
        }
        for(i=0;num2[i]!='\0';i++) // @@ num2 not null-terminated.
        {
            printf("%c",num2[i]);
        }
        printf("e%d",a-1);
    }
    return 0;
}