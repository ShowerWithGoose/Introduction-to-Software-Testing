#include<stdio.h>
#include<string.h>
int judge(char x, char y)
{
    if((x>='a'&&x<='z')||(y>='a'&&y<='z')) // @@ Error: Should check both x and y are lowercase; currently returns true if either is lowercase, allowing mixed cases.
        return 1;
    if((x>='A'&&x<='Z')||(y>='A'&&y<='Z')) // @@ Error: Similar issue for uppercase; should require both are uppercase.
        return 1;
    if((x>='0'&&x<='9')||(y>='0'&&y<='9')) // @@ Error: Similar for digits; should require both are digits.
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
        if((first[i]=='-')&&judge(first[i+1], first[i-1])) // @@ Error: No check that i-1>=0 and i+1<len to avoid out-of-bounds access. Also judge lacks condition right > left; without that, equal or smaller cases incorrectly enter block and omit '-'.
        {
            for(int k=1;k<first[i+1]-first[i-1];k++) // @@ Error: If first[i+1] <= first[i-1], loop does nothing but '-' is not printed; should only expand when right > left.
            printf("%c",first[i-1]+k);
        }
        else
        printf("%c",first[i]);        
    }
    return 0;
}