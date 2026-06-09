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
    gets(first); // @@ [Using 'gets' is unsafe and deprecated; may cause compilation error with modern compilers due to removal from standard library]
    len=strlen(first);
    for(int i=0;i<len;i++)
    {
        if((first[i]=='-')&&judge(first[i+1], first[i-1])) // @@ [The 'judge' function logic is incorrect: it returns 1 even when x and y are of different types (e.g., one lowercase and one digit). Also, accessing first[i-1] when i=0 leads to out-of-bounds read.]
        {
            for(int k=1;k<first[i+1]-first[i-1];k++) // @@ [Loop condition assumes first[i+1] > first[i-1], but no check ensures this; also, if first[i+1] <= first[i-1], loop runs incorrectly or not at all. Additionally, accessing first[i+1] when i = len-1 causes out-of-bounds read.]
            printf("%c",first[i-1]+k);
        }
        else
        printf("%c",first[i]);        
    }
    return 0;
}