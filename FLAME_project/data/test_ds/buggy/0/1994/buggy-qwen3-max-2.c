#include<stdio.h>
#include<string.h>
int judge(char x, char y)
{
    if((x>='a'&&x<='z')||(y>='a'&&y<='z))
        return 1; // @@ [This logic is incorrect: it returns 1 if either x or y is a lowercase letter, but expansion should only happen when both are of the same type. Also, it doesn't check if they are the same category (e.g., both lowercase, both uppercase, or both digits).]
    if((x>='A'&&x<='Z')||(y>='A'&&y<='Z))
        return 1; // @@ [Same issue: returns 1 if either is uppercase, not requiring both to be uppercase.]
    if((x>='0'&&x<='9')||(y>='0'&&y<='9))
        return 1; // @@ [Same issue: returns 1 if either is a digit, not requiring both to be digits.]
    else 
        return 0;
}
int main()
{
    char first[1500];
    int len;
    gets(first); // @@ [Using gets() is unsafe and deprecated; however, the main logical error is elsewhere. More critically, the program does not validate that the characters around '-' are of the same type and in increasing order.]
    len=strlen(first);
    for(int i=0;i<len;i++)
    {
        if((first[i]=='-')&&judge(first[i+1], first[i-1])) // @@ [The judge function is flawed as explained above. Additionally, this condition does not check if first[i-1] < first[i+1], which is required for expansion. Also, accessing first[i-1] when i=0 leads to out-of-bounds access (undefined behavior).]
        {
            for(int k=1;k<first[i+1]-first[i-1];k++) // @@ [If first[i+1] <= first[i-1], this loop may run with negative or zero iterations, but more critically, without proper type matching and ordering checks, it may expand invalid ranges like 'B' to 'e', which crosses case boundaries.]
            printf("%c",first[i-1]+k);
        }
        else
        printf("%c",first[i]);        
    }
    return 0;
}