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
        if((first[i]=='-')&&judge(first[i+1], first[i-1])) // @@ [The judge function logic is incorrect: it returns 1 even when x and y are of different types (e.g., one digit and one letter), violating the requirement that both sides must be same type]
        {
            for(int k=1;k<first[i+1]-first[i-1];k++) // @@ [No check that first[i+1] > first[i-1]; if not, loop condition fails or causes negative/invalid behavior. Also, if i is 0 or i+1 is beyond string, accesses invalid memory]
            printf("%c",first[i-1]+k);
        }
        else
        printf("%c",first[i]);        
    }
    return 0;
}