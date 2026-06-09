#include <stdio.h>
int main()
{
    char s[1000]={0};
    int i=0;
    while(scanf("%c",&s[i])!=EOF)
    {
        i++;
    }
    int j;
    for(j=0;j<=i;j++) // @@ Error: loop should be j < i, otherwise it prints the null terminator.
    {
        if(s[j]!='-')
        printf("%c",s[j]);
        else
        {   if((s[j-1]>='0'&&s[j+1]<='9'&&s[j-1]<s[j+1])||(s[j-1]>='a'&&s[j+1]<='z'&&s[j-1]<s[j+1])||(s[j-1]>='A'&&s[j+1]<='Z'&&s[j-1]<s[j+1])) // @@ Error: conditions do not ensure that the left character is within the valid range (e.g., missing s[j-1]<='z' for lowercase). This may allow incorrect expansions.
            {
                int n=1;
                while(s[j-1]+n<=s[j+1]) // @@ Error: This prints the right character, but later the right character is printed again (since the for loop will process it and print it when it is not '-'). Need to skip printing the right character by incrementing j after the while loop.
                {
                    printf("%c",s[j-1]+n);
                    n++;
                }
            }
            else
            printf("%c",s[j]);
        }
    }
    return 0;
}