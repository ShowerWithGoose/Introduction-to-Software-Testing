#include<stdio.h>
#include<string.h>
int judge(char x, char y)
{
    if((x>='a'&&x<='z')||(y>='a'&&y<='z')) // @@ This should check that both x and y are lowercase letters, not using OR; also the condition is incorrect because it returns 1 even if only one is lowercase.
        return 1;
    if((x>='A'&&x<='Z')||(y>='A'&&y<='Z')) // @@ Same issue: should check that both are uppercase letters.
        return 1;
    if((x>='0'&&x<='9')||(y>='0'&&y<='9')) // @@ Same issue: should check that both are digits.
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
        if((first[i]=='-')&&judge(first[i+1], first[i-1])) // @@ Missing check that first[i+1] > first[i-1]; also judge function is incorrect as noted; additionally, no bounds check for i-1 and i+1 (potential out-of-range access).
        {
            for(int k=1;k<first[i+1]-first[i-1];k++)
            printf("%c",first[i-1]+k);
        }
        else
        printf("%c",first[i]);        
    }
    return 0;
}