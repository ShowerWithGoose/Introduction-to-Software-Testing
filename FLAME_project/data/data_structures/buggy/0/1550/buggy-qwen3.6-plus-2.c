#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h> 

int main()
{
    char a[1000];
    gets(a);
    int i,j;
    for(i = 0; i < strlen(a); i++)
    {
        if(a[i] == '-')
        {
            if(islower(a[i + 1]) && islower(a[i - 1]) && fabs(a[i - 1] - a[i + 1]) >= 1) // @@ The condition uses fabs which allows expansion when the second character is smaller than the first (e.g., z-a), violating the requirement that the character after '-' must be greater. Also, using multiple independent 'if' statements instead of 'else if' causes logic errors where multiple blocks might execute or the final 'else' attaches incorrectly.
            {
                for(j = (int)a[i - 1] + 1; j < (int)a[i + 1]; j++)
                    printf("%c",j);
            }
            if(isupper(a[i + 1]) && isupper(a[i - 1]) && fabs(a[i - 1] - a[i + 1]) >= 1) // @@ Same error as above: fabs allows reverse expansion, and independent 'if' means this block executes even if the previous lowercase block executed, leading to duplicate or incorrect output structure. It should be 'else if'.
            {
                for(j = (int)a[i - 1] + 1; j < (int)a[i + 1]; j++)
                    printf("%c",j);
            }
            if(isdigit(a[i + 1]) && isdigit(a[i - 1]) && fabs(a[i - 1] - a[i + 1]) >= 1) // @@ Same error as above: fabs allows reverse expansion, and independent 'if' breaks the mutual exclusivity required for the else clause below. It should be 'else if'.
            {
                for(j = (int)a[i - 1] + 1; j < (int)a[i + 1]; j++)
                    printf("%c",j);
            }
            else // @@ Because the previous checks are independent 'if's, this 'else' only pairs with the last 'if' (isdigit). If the lowercase or uppercase block executes, this else is skipped, but if none execute, it prints '-'. However, if lowercase matches but uppercase doesn't, it might print '-' incorrectly depending on flow. The main issue is the lack of 'else if' chain.
                printf("-");
        }
        else
            printf("%c",a[i]);
    }
    return 0;    
}