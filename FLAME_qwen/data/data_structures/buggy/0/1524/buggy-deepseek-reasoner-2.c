#include<stdio.h>
#include<ctype.h>
char s[10000]; 
int pd(char a,char b)
{
    if('a'<=a&&a<='z'&&'a'<=b&&b<='z')
    return 1;
    if('A'<=a&&a<='Z'&&'A'<=b&&b<='Z')
    return 1;
    if('0'<=a&&a<='9'&&'0'<=b&&b<='9')
    return 1;
    return 0;
}
int main()
{    
    int cha=0;
    gets(s);
    for(int i=0;s[i]!='\0';i++)
    {
        if(s[i]=='-')
        {
            if(pd(s[i-1],s[i+1])==1) // @@ Error: Missing boundary checks for s[i-1] and s[i+1] (potential out-of-bounds access). Also, missing else clause to print '-' when expansion condition fails (e.g., different types or second char not greater).
            {
                cha=0;
                cha=s[i+1]-s[i-1]-1; // @@ Error: Potential out-of-bounds access if indices are not valid, though this line is within the block that already accessed them.
                if(cha>0)
                {
                    for(int k=1;k<=cha;k++)
                    {
                        printf("%c",s[i-1]+k);
                    }
                }
            }
        }else
        {
            printf("%c",s[i]);
        }
    }
    return 0;
}