#include<stdio.h>
#include<string.h>
int judge(char x, char y)
{
    if((x>='a'&&x<='z')||(y>='a'&&y<='z')) // @@ The logic is incorrect. It returns 1 (true) if EITHER character is a lowercase letter, regardless of whether they are the same type. For "B-e", 'e' is lowercase, so this returns 1, triggering expansion incorrectly. It should check if BOTH are lowercase, OR both are uppercase, OR both are digits.
        return 1;
    if((x>='A'&&x<='Z')||(y>='A'&&y<='Z')) // @@ Similarly, this returns 1 if EITHER is uppercase. This branch is also logically flawed for the same reason as above.
        return 1;
    if((x>='0'&&x<='9')||(y>='0'&&y<='9')) // @@ Similarly, this returns 1 if EITHER is a digit.
        return 1;
    else 
        return 0;
}
int main()
{
    char first[1500];
    int len;
    gets(first);
    len=strlen(first);
    for(int i=0;i<len;i++)
    {
        if((first[i]=='-')&&judge(first[i+1], first[i-1])) // @@ Because judge() is flawed, this condition evaluates to true for "B-e" (since 'e' is lowercase), leading to incorrect expansion. Additionally, it doesn't check if first[i+1] > first[i-1].
        {
            for(int k=1;k<first[i+1]-first[i-1];k++)
            printf("%c",first[i-1]+k);
        }
        else
        printf("%c",first[i]);        
    }
    return 0;
}