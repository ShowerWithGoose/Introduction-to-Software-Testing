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
        e=-i+1; // @@ Error: The exponent calculation is incorrect. For input "0.00000009123456789012", i starts at 2 and counts zeros, so i becomes 8 after the loop (since there are 6 zeros after the decimal point). e = -8+1 = -7, but the expected exponent is -8. The correct formula should be e = -i+2 or e = -(i-1) to account for the decimal point and the leading zero.
        while(s[i]!='\0')
        {
            printf("%c",s[i]);
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
        j=2;
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