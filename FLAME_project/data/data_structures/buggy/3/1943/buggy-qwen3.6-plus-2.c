#include<stdio.h>
#include<string.h>
int main()
{
    char c[100];
    gets(c);
    int num=0,flag=0,i=0,judge=0;
    if(strlen(c)==1)
    {
        printf("%c",c[0]);
        printf("e0");
    }
    else
    {
        if(c[0]=='0')
        {
            for(num=1,i=2;c[i]=='0';i++)
                num++;
            while(c[i]!='\0')
            {
                if(judge==1)
                    printf(".");
                judge++;
                printf("%c",c[i]);    
                i++;
            }
            printf("e-%d",num);
        }
        else
        {
            while(c[i]!='.'&&c[i]!='\0')
            {
                if(judge==1) // @@ The condition `judge==1` is intended to print the decimal point after the first digit, but `judge` is incremented immediately after checking. For the first digit (index 0), `judge` is 0, so it prints the digit. Then `judge` becomes 1. For the next character (which is '.'), `judge` is 1, so it prints '.', which is correct for the base format. However, the logic inside the loop prints characters one by one. If the number has multiple digits before the decimal point, e.g., "87899.", the loop runs for '8', '7', '8', '9', '9'.
                // Iteration 1: c[0]='8', judge=0. Prints '8'. judge becomes 1. i becomes 1.
                // Iteration 2: c[1]='7', judge=1. Prints '.'. judge becomes 2. Prints '7'. i becomes 2.
                // This results in "8.7..." which is incorrect. The decimal point should only appear once, after the first significant digit. The current logic inserts a dot before every digit after the first one inside the integer part loop.
                printf(".");
                judge++;
                printf("%c",c[i]);
                i++;
            }
            if(c[i]=='\0')
            {
                printf("e%d",judge-1);
            }
            else
            {
                printf("."); 
                for(i++;c[i]!='\0';i++)
                {
                    printf("%c",c[i]);
                }
                printf("e%d",judge-1);
            }
        }
    }
        

    return 0;
}