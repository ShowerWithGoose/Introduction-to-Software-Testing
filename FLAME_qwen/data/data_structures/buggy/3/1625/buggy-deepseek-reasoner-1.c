#include <stdio.h>
#include <string.h>

int main()
{
    char s[105];
    gets(s); // @@ Deprecated function; may cause compilation error in strict standards.
    int len=strlen(s);
    
    int num1=0;
    int i=0;
    while(s[i]!='.')
    {
        i++;
        num1++;
    }
    if(num1>1)
    {
        printf("%c.",s[0]);
        for(i=1;i<len-1;i++) // @@ Loop bound should be i<len to include the last digit after decimal point.
        {
            if(s[i]!='.')
            printf("%c",s[i]);
        }
        printf("e%d",num1-1);
    }
    else if(num1=1&&s[0]!='0') // @@ Assignment (=) used instead of comparison (==); always true when s[0] != '0' but also changes num1 to 1.
    {
        for(i=0;i<len;i++)
        {
            printf("%c",s[i]);
        }
        printf("e0");
    }
    else
    {
        int num2=0;
        i=2;
        while(1)
        {
            if(s[i]!='0') 
            break;
            i++;
            num2++;
        }
        if(i==len-1)
        {
            printf("%ce-%d",s[i],num2+1);
        }
        else
        {
            printf("%c.",s[i]);
            while(i!=len-1)
            {
                i++;
                printf("%c",s[i]);
            }
            printf("e-%d",num2+1);
        }
    }
        
}