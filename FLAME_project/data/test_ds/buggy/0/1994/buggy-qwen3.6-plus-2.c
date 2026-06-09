#include<stdio.h>
#include<string.h>
int judge(char x, char y)
{
    if((x>='a'&&x<='z')||(y>='a'&&y<='z')) // @@ The logical operator '||' is incorrect; it should be '&&' to ensure both characters are lowercase. Additionally, the condition 'x > y' is missing to verify that the character after '-' is greater than the one before it.
        return 1;
    if((x>='A'&&x<='Z')||(y>='A'&&y<='Z')) // @@ The logical operator '||' is incorrect; it should be '&&' to ensure both characters are uppercase.
        return 1;
    if((x>='0'&&x<='9')||(y>='0'&&y<='9')) // @@ The logical operator '||' is incorrect; it should be '&&' to ensure both characters are digits.
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