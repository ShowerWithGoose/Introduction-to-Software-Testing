#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h> 

int main()
{
    char a[1000];
    gets(a); // @@ [Using gets() is unsafe and deprecated; however, the main logical errors are elsewhere.]
    int i,j;
    for(i = 0; i < strlen(a); i++)
    {
        if(a[i] == '-')
        {
            if(islower(a[i + 1]) && islower(a[i - 1]) && fabs(a[i - 1] - a[i + 1]) >= 1) // @@ [Condition uses absolute difference >=1, which allows reverse ranges like 'd-a' to expand incorrectly; should require a[i+1] > a[i-1]. Also, accessing a[i-1] when i=0 causes undefined behavior.]
            {
                for(j = (int)a[i - 1] + 1; j < (int)a[i + 1]; j++)
                    printf("%c",j);
            }
            if(isupper(a[i + 1]) && isupper(a[i - 1]) && fabs(a[i - 1] - a[i + 1]) >= 1) // @@ [Same issue: uses absolute value and doesn't ensure a[i+1] > a[i-1]; also unsafe access when i=0.]
            {
                for(j = (int)a[i - 1] + 1; j < (int)a[i + 1]; j++)
                    printf("%c",j);
            }
            if(isdigit(a[i + 1]) && isdigit(a[i - 1]) && fabs(a[i - 1] - a[i + 1]) >= 1) // @@ [Same problem: allows invalid reverse expansions and unsafe access at i=0.]
            {
                for(j = (int)a[i - 1] + 1; j < (int)a[i + 1]; j++)
                    printf("%c",j);
            }
            else
                printf("-"); // @@ [This else only pairs with the last if (isdigit), not the entire group. So if the first or second condition fails but the third passes, it still prints the expansion AND may print '-' incorrectly. Should use else if chain and handle non-matching cases properly.]
        }
        else
            printf("%c",a[i]);
    }
    return 0;    
}