#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h> 

int main()
{
    char a[1000];
    gets(a); // @@ [Using gets() is unsafe and may cause buffer overflow; also, the reference uses scanf which stops at whitespace, while gets reads entire line including spaces—though not directly causing WA here, it's problematic. However, the main logic errors are below.]
    int i,j;
    for(i = 0; i < strlen(a); i++)
    {
        if(a[i] == '-')
        {
            if(islower(a[i + 1]) && islower(a[i - 1]) && fabs(a[i - 1] - a[i + 1]) >= 1) // @@ [Condition uses absolute difference >=1, but problem requires that the character after '-' is greater than the one before. Also, accessing a[i-1] when i=0 leads to undefined behavior (out-of-bound read).]
            {
                for(j = (int)a[i - 1] + 1; j < (int)a[i + 1]; j++)
                    printf("%c",j);
            }
            if(isupper(a[i + 1]) && isupper(a[i - 1]) && fabs(a[i - 1] - a[i + 1]) >= 1) // @@ [Same issue: uses absolute value instead of checking a[i+1] > a[i-1], and doesn't prevent out-of-bound access when i=0. Also, multiple if blocks instead of else-if causes overlapping checks.]
            {
                for(j = (int)a[i - 1] + 1; j < (int)a[i + 1]; j++)
                    printf("%c",j);
            }
            if(isdigit(a[i + 1]) && isdigit(a[i - 1]) && fabs(a[i - 1] - a[i + 1]) >= 1) // @@ [Same logical error: should check a[i+1] > a[i-1], not absolute difference. Also, no bounds check for i=0 or i at end.]
            {
                for(j = (int)a[i - 1] + 1; j < (int)a[i + 1]; j++)
                    printf("%c",j);
            }
            else
                printf("-"); // @@ [This else only pairs with the last if (isdigit), not the whole group. So if the first or second condition fails but the third also fails, it prints '-', but if any earlier condition matches, it expands AND may still print '-' if later conditions fail. This causes incorrect output like keeping '-' in some cases or duplicating expansions.]
        }
        else
            printf("%c",a[i]);
    }
    return 0;    
}