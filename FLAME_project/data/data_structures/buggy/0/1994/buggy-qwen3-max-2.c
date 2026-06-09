#include<stdio.h>
#include<string.h>
int judge(char x, char y)
{
    if((x>='a'&&x<='z')||(y>='a'&&y<='z))
        return 1; // @@ [This logic is incorrect: it returns 1 if either character is a lowercase letter, even if the other is not of the same type. The problem requires both characters to be of the same category (both lowercase, both uppercase, or both digits).]
    if((x>='A'&&x<='Z')||(y>='A'&&y<='Z))
        return 1; // @@ [Same issue: returns 1 if either is uppercase, regardless of the other. This allows mixed cases like 'B' and 'e' to pass, which should not be expanded.]
    if((x>='0'&&x<='9')||(y>='0'&&y<='9))
        return 1; // @@ [Same issue: returns 1 if either is a digit, even if the other isn't. This violates the requirement that both must be digits.]
    else 
        return 0;
}
int main()
{
    char first[1500];
    int len;
    gets(first); // @@ [Using gets() is unsafe and deprecated; however, the main logical error is elsewhere. More critically, the program does not validate that the character after '-' is greater than the one before it, nor that both are of the same type.]
    len=strlen(first);
    for(int i=0;i<len;i++)
    {
        if((first[i]=='-')&&judge(first[i+1], first[i-1]))
        {
            for(int k=1;k<first[i+1]-first[i-1];k++)
            printf("%c",first[i-1]+k); // @@ [This expands even when the two characters are of different types (e.g., 'B' and 'e'), because judge() incorrectly returns true. Also, it does not check if first[i+1] > first[i-1]; if not, it may loop with negative or zero iterations or cause undefined behavior. Additionally, it skips printing the original characters around '-', so the output misses the starting character and the ending character.]
        }
        else
        printf("%c",first[i]);        
    }
    return 0;
}