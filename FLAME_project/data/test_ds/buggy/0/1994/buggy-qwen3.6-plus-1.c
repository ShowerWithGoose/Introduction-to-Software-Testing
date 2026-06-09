#include<stdio.h>
#include<string.h>
int judge(char x, char y)
{
    if((x>='a'&&x<='z')||(y>='a'&&y<='z')) // @@ Logical error: uses || instead of &&, should ensure both characters are of the same type (lowercase)
        return 1;
    if((x>='A'&&x<='Z')||(y>='A'&&y<='Z')) // @@ Logical error: uses || instead of &&, should ensure both characters are of the same type (uppercase)
        return 1;
    if((x>='0'&&x<='9')||(y>='0'&&y<='9')) // @@ Logical error: uses || instead of &&, should ensure both characters are of the same type (digits)
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
        if((first[i]=='-')&&judge(first[i+1], first[i-1])) // @@ Missing condition: must also check first[i+1] > first[i-1] as per requirements to only expand when the right character is greater
        {
            for(int k=1;k<first[i+1]-first[i-1];k++)
            printf("%c",first[i-1]+k);
        }
        else
        printf("%c",first[i]);        
    }
    return 0;
}