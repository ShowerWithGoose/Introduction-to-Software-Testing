#include<stdio.h>
#include<string.h>
int main()
{
    char a[100];
    int i,j;
    fgets(a,100,stdin);
    for(i=0;i<strlen(a);i++)
    {
        if(a[i]=='-')
        {
            if((a[i-1]>='a')&&(a[i-1]<='z'))
            {
                // @@ The code fails to check if the character after '-' (a[i+1]) is of the same type (lowercase) and greater than a[i-1]. For input "B-e", a[i-1] is 'B' (not lowercase), so this block is skipped, but the logic for handling invalid expansions is missing entirely.
                for(j=a[i-1]+1;j<a[i+1];j++)
                {printf("%c",j);}
            }
            else if((a[i-1]>='A')&&(a[i-1]<='Z'))
            {
                // @@ The code fails to check if the character after '-' (a[i+1]) is of the same type (uppercase) and greater than a[i-1]. For input "B-e", a[i-1] is 'B' (uppercase), so this block is entered. However, a[i+1] is 'e' (lowercase). The loop runs from 'C' to 'd', producing incorrect output. It should verify that a[i+1] is also uppercase and > a[i-1] before expanding.
                for(j=a[i-1]+1;j<a[i+1];j++)
                {printf("%c",j);}
            }
            else if((a[i-1]>='0')&&(a[i-1]<='9'))
            {
                // @@ Similar to above, it lacks validation that a[i+1] is a digit and greater than a[i-1].
                for(j=a[i-1]+1;j<a[i+1];j++)
                {printf("%c",j);}
            }
            // @@ Missing else clause to handle cases where expansion is invalid (different types or not increasing). In these cases, the '-' should be printed as is. Currently, if none of the if/else-if conditions are met (or even if they are met but shouldn't have been due to missing checks), the '-' is consumed and not printed, or incorrect expansion occurs. Specifically for "B-e", the second block executes incorrectly. If we fix the conditions, we need an else to print '-'.
        }
        else
        {printf("%c",a[i]);}
    }
    return 0;
}