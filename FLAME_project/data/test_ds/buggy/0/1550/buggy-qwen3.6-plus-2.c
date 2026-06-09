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
            if(islower(a[i + 1]) && islower(a[i - 1]) && a[i + 1] > a[i - 1]) // @@ Condition should check a[i+1] > a[i-1] as per requirements; fabs(...) >= 1 is incorrect and allows reverse order.
            {
                for(j = (int)a[i - 1] + 1; j < (int)a[i + 1]; j++)
                    printf("%c",j);
            }
            else if(isupper(a[i + 1]) && isupper(a[i - 1]) && a[i + 1] > a[i - 1]) // @@ Changed to 'else if' to form a proper conditional chain; otherwise the final 'else' executes incorrectly when this condition is false. Condition also fixed.
            {
                for(j = (int)a[i - 1] + 1; j < (int)a[i + 1]; j++)
                    printf("%c",j);
            }
            else if(isdigit(a[i + 1]) && isdigit(a[i - 1]) && a[i + 1] > a[i - 1]) // @@ Changed to 'else if' to complete the conditional chain; condition also fixed.
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