#include<stdio.h>
#include<string.h>
int judge(char x, char y)
{
    if((x>='a'&&x<='z')||(y>='a'&&y<='z')) // @@ error: should use && to ensure both are lowercase, not OR; this incorrectly returns 1 for mixed types
        return 1;
    if((x>='A'&&x<='Z')||(y>='A'&&y<='Z')) // @@ error: should use && to ensure both are uppercase
        return 1;
    if((x>='0'&&x<='9')||(y>='0'&&y<='9')) // @@ error: should use && to ensure both are digits
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
        if((first[i]=='-')&&judge(first[i+1], first[i-1]))
        {
            for(int k=1;k<first[i+1]-first[i-1];k++)
            printf("%c",first[i-1]+k);
        }
        else
        printf("%c",first[i]);        
    }
    return 0;
}