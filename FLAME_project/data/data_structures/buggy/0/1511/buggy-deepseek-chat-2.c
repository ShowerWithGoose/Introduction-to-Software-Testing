#include<stdio.h>
#include<string.h>
char c[10001];
int main()
{
    gets(c);

    for(int i=0;i<=strlen(c)-1;i++)
    {
        if(c[i]=='-'&&c[i-1]<c[i+1]) // @@ Error: When i=0, c[i-1] accesses out-of-bounds memory. Also, the condition should check that both sides are of the same type and the right character is greater than the left, but the order of checks is wrong; the type check should come first.
        {
            if((c[i-1]>='0'&&c[i-1]<='9')&&(c[i+1]>='0'&&c[i+1]<='9')||(c[i-1]>='a'&&c[i-1]<='z')&&(c[i+1]>='a'&&c[i+1]<='z')||(c[i-1]>='A'&&c[i-1]<='Z')&&(c[i+1]>='A'&&c[i+1]<='Z')) // @@ Error: Missing parentheses around the OR conditions, causing incorrect operator precedence. Also, the condition does not check that the characters are of the same type before comparing c[i-1] < c[i+1]; for example, 'B' < 'e' is true but they are different types, so no expansion should occur.
            {
                for(int j=1;j<(c[i+1]-c[i-1]);j++)
                {
                    printf("%c",c[i-1]+j);
                }
            }

        }

        else
        {
            printf("%c",c[i]); // @@ Error: When the '-' is not expanded, it should still be printed, but this prints all characters including the '-' when the condition fails. However, the main issue is that for input "B-e", the condition c[i-1]<c[i+1] is true ('B' < 'e'), but since they are different types, no expansion should happen. The code incorrectly enters the if block and then the inner if fails, so it goes to else and prints the '-', but the logic is flawed because it should not have entered the outer if at all.
        }
    }

    return 0;
}