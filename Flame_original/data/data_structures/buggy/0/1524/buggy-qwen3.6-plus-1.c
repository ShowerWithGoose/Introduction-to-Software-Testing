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
    gets(s); // @@ gets is unsafe and deprecated, may cause buffer overflow; fgets is recommended
    for(int i=0;s[i]!='\0';i++)
    {
        if(s[i]=='-') // @@ When i=0, s[i-1] accesses out-of-bounds memory, causing undefined behavior
        {
            if(pd(s[i-1],s[i+1])==1) // @@ Missing check for s[i+1] > s[i-1]; expansion should only occur if right char is greater
            {
                cha=0;
                cha=s[i+1]-s[i-1]-1; // @@ Calculates intermediate chars, but combined with k<=cha causes s[i+1] to be printed twice
                if(cha>0) // @@ If s[i+1] <= s[i-1], cha <= 0 and '-' is skipped instead of being printed unchanged
                {
                    for(int k=1;k<=cha;k++) // @@ Loop condition should be k < s[i+1]-s[i-1] to print only characters strictly between bounds
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