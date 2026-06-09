#include<stdio.h>

int main()
{
    int e,i,j;
    char s[150]={0};
    gets(s);
    if(s[0]=='0')
    {
        i=2;
        while(s[i]=='0')
        {
            i++;
        }
        e=-i+1;
        while(s[i]!='\0')
        {
            printf("%c",s[i]); // @@ Fails to insert a decimal point after the first significant digit when multiple significant digits exist
            i++;
        }
        printf("e%d",e);
    }
    else if(s[0]!='0'&&s[1]=='\0')
    printf("%ce0",s[0]);
    else
    {
        i=0;
        while(s[i]!='.')
        {
            i++;
        }
        e=i-1;
        j=2; // @@ Incorrect starting index; should be j=1 to include the digit immediately after the first one in the mantissa
        printf("%c.",s[0]);
        while(s[j]!='\0')
        {
            if(s[j]!='.')
            {
            printf("%c",s[j]);
            j++;
            }
            else
            j++;
        }
        printf("e%d",e);
    }
    return 0;
}