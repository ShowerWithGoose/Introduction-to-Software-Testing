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
    gets(first); // @@ [Using gets() is unsafe and may cause compilation errors or warnings in modern compilers; also, the judge function logic is flawed—it should check that both characters are of the same type, not just that either one belongs to a category. Additionally, boundary checks for i-1 and i+1 are missing, leading to potential out-of-bounds access.]
    len=strlen(first);
    for(int i=0;i<len;i++)
    {
        if((first[i]=='-')&&judge(first[i+1], first[i-1])) // @@ [The judge function is called with arguments in wrong order (should be first[i-1], first[i+1]), but more critically, it does not ensure both characters are of the same type—e.g., 'a' and 'Z' would incorrectly return 1. Also, when i=0 or i=len-1, accessing first[i-1] or first[i+1] leads to undefined behavior.]
        {
            for(int k=1;k<first[i+1]-first[i-1];k++) // @@ [No validation that first[i+1] > first[i-1]; if not, loop condition fails or behaves unexpectedly. Also, if characters are not of same type (due to flawed judge), expansion still occurs incorrectly.]
            printf("%c",first[i-1]+k);
        }
        else
        printf("%c",first[i]);        
    }
    return 0;
}