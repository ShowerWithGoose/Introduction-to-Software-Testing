#include <stdio.h>
char str[10000];
int main()
{
    gets(str);
    int i=1,j;
    if(str[0]=='0')
    {
        for(i=2;str[i]=='0';i++);
        if(str[i+1]=='\0') // @@ The condition checks the character after the first non-zero digit. For input "0.9", i becomes 2 (pointing to '9'). str[i+1] is '\0'. The code enters this block, prints '9', but fails to print the exponent part "e-1". It should handle the exponent calculation and printing here or ensure the else block logic is correct for single significant digits. Actually, the logic for calculating exponent is flawed. For 0.9, the first non-zero is at index 2. The exponent should be -(i-1) = -1. The current code misses printing "e" and the exponent in this branch.
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
            printf("%d",i-1); // @@ The exponent sign is wrong. For numbers less than 1 (starting with 0.), the exponent should be negative. Here it prints a positive value. It should be printf("-%d", i-1); or similar logic to make it negative. Also, the previous if branch missed the exponent entirely.
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