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
                if(judge==1) // @@ [Incorrect condition: prints a decimal point on every digit after the first, causing multiple dots; should only print dot exactly once after the first non-zero digit.]
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
                if(judge==1) // @@ [Same issue: prints a decimal point incorrectly after the second digit instead of after the first, and also causes extra dots when multiple digits exist.]
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
                printf("."); // @@ [Prints an additional decimal point, leading to two dots in the output (one from the while loop and one here). Should not print a dot here if already placed correctly.]
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