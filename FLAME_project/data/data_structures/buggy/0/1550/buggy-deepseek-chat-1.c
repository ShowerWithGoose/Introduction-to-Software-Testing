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
            if(islower(a[i + 1]) && islower(a[i - 1]) && fabs(a[i - 1] - a[i + 1]) >= 1)
            {
                for(j = (int)a[i - 1] + 1; j < (int)a[i + 1]; j++)
                    printf("%c",j);
            }
            if(isupper(a[i + 1]) && isupper(a[i - 1]) && fabs(a[i - 1] - a[i + 1]) >= 1) // @@ This should be else if, not if. Using if causes the else on line 27 to only attach to this condition, so when the first condition (islower) is true, the else still executes and prints '-', incorrectly adding a dash.
            {
                for(j = (int)a[i - 1] + 1; j < (int)a[i + 1]; j++)
                    printf("%c",j);
            }
            if(isdigit(a[i + 1]) && isdigit(a[i - 1]) && fabs(a[i - 1] - a[i + 1]) >= 1) // @@ This should also be else if, not if. Same issue as above: when islower or isupper conditions are true, this if is skipped but the else still runs, causing extra '-' to be printed.
            {
                for(j = (int)a[i - 1] + 1; j < (int)a[i + 1]; j++)
                    printf("%c",j);
            }
            else
                printf("-");
        }
        else
            printf("%c",a[i]);
    }
    return 0;    
}