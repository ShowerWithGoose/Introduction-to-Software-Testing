#include <stdio.h>
char str[10000];
int main()
{
    gets(str);
    int i=1,j;
    if(str[0]=='0')
    {
        for(i=2;str[i]=='0';i++);
        if(str[i+1]=='\0') // @@ The condition checks the character after the first non-zero digit. For input "0.9", i becomes 2 (str[2] is '9'). str[i+1] is str[3] which is '\0'. The code enters this block, prints only '9', and misses the exponent part. It should check if there are no more digits after the current one to decide if a decimal point is needed, but it must always print the exponent. The logic for handling the decimal point and exponent is flawed here.
        {
            printf("%c",str[i]);
        }
        else
        {
            printf("%c.",str[i]);
            for(j=i+1;str[j]!='\0';j++)
            {
                printf("%c",str[j]);
            }    
            printf("e");
            printf("%d",i-1); // @@ The exponent calculation is incorrect. For "0.9", the exponent should be -1. Here i is 2, so i-1 is 1. It should be -(i-1) or similar depending on how i is calculated relative to the decimal point position. Specifically, for 0.0...0d, the exponent is -(number of zeros + 1). Here i points to the first non-zero digit. The number of positions shifted is i-1 (from index 2 to index 1 is 1 shift? No. Index 2 is '9'. Decimal is at 1. Shift is 1. Exponent is -1. So -(i-1) would be -(2-1) = -1. Wait, the reference output says e-1. The code prints positive 1. So it needs a negative sign.
        }
    }
    else if(str[1]=='.')
    {
        for(i=0;str[i]!='\0';i++)
        {
            printf("%c",str[i]);
        }
        printf("e0");
    }
    else
    {
        for(i=0;str[i]!='.';i++);
        printf("%c.",str[0]);
        for(j=1;j<i;j++)
        {
            printf("%c",str[j]);
        }
        for(j=i+1;str[j]!='\0';j++)
        {
            printf("%c",str[j]);
        }
        printf("e");
        printf("%d",i-1);
    }
    return 0;
}