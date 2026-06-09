#include<stdio.h>
#include<string.h>
int judge(char x, char y)
{
    if((x>='a'&&x<='z')||(y>='a'&&y<='z))
        return 1; // @@ [This logic is incorrect: it returns 1 if either x or y is a lowercase letter, but expansion should only happen when both are of the same type. Also, it doesn't ensure both are lowercase, leading to invalid expansions like 'B-e'.]
    if((x>='A'&&x<='Z')||(y>='A'&&y<='Z))
        return 1; // @@ [Same issue: returns 1 if either is uppercase, not requiring both to be uppercase. This causes mixed-case pairs like 'B-e' to be considered valid for expansion.]
    if((x>='0'&&x<='9')||(y>='0'&&y<='9))
        return 1; // @@ [Same flaw: returns 1 if either is a digit, not both. This would incorrectly allow expansions like '0-b'.]
    else 
        return 0;
}
int main()
{
    char first[1500];
    int len;
    gets(first); // @@ [Using gets() is unsafe and deprecated; however, the main logical error is elsewhere. The critical issue is that the program expands even when the two sides of '-' are of different types (e.g., 'B' (upper) and 'e' (lower)), because judge() returns 1 in such cases.]
    len=strlen(first);
    for(int i=0;i<len;i++)
    {
        if((first[i]=='-')&&judge(first[i+1], first[i-1]))
        {
            for(int k=1;k<first[i+1]-first[i-1];k++)
            printf("%c",first[i-1]+k); // @@ [This prints the expanded characters but skips printing the character after '-', and also fails to handle cases where no expansion should occur (like 'B-e'). Moreover, it doesn't check if the right character is greater than the left one before expanding.]
        }
        else
        printf("%c",first[i]);        
    }
    return 0;
}