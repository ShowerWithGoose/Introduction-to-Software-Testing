#include<stdio.h>
#include<string.h>
int judge(char x, char y)
{
    if((x>='a'&&x<='z')||(y>='a'&&y<='z'))
        return 1;
    if((x>='A'&&x<='Z')||(y>='A'&&y<='Z'))
        return 1;
    if((x>='0'&&x<='9')||(y>='0'&&y<='9'))
        return 1;
    else 
        return 0;
}
int main()
{
    char first[1500];
    int len;
    gets(first); // @@ [Using gets() is unsafe and deprecated; may cause compilation error with modern compilers that remove gets()]
    len=strlen(first);
    for(int i=0;i<len;i++)
    {
        if((first[i]=='-')&&judge(first[i+1], first[i-1])) // @@ [Logic error: judge() does not correctly verify that both characters are of the same type and valid; also accesses first[i-1] when i=0 leading to out-of-bounds read]
        {
            for(int k=1;k<first[i+1]-first[i-1];k++) // @@ [If first[i+1] <= first[i-1], loop condition fails or causes incorrect behavior; also accesses first[i+1] when i = len-1 (out-of-bounds)]
            printf("%c",first[i-1]+k);
        }
        else
        printf("%c",first[i]);        
    }
    return 0;
}