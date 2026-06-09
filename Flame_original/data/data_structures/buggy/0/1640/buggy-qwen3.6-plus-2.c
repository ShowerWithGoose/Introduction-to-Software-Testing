#include<string.h>
#include<stdio.h>
int main()
{
    char s[1000];
    int i=0,j;
    
    gets(s); // @@ gets() is deprecated/removed in C11 and may cause compilation errors; use fgets() instead.
    for(i=0;i<strlen(s);i++)
    {
        if(s[i]!='-'||s[i-1]>=s[i+1]) printf("%c",s[i]); // @@ Accessing s[i-1] when i=0 causes out-of-bounds error. Also, logical flaw: when s[i]=='-' and types differ but s[i-1]<s[i+1], it falls through without printing '-', losing the character.
        else if(s[i-1]<'z'+1&&s[i-1]>'a'-1&&s[i+1]<'z'+1&&s[i+1]>'a'-1) // @@ Accessing s[i+1] when i points to the last character causes out-of-bounds error.
        {
            for(j=s[i-1]+1;j<s[i+1];j++)
            printf("%c",j);
        }
        else if(s[i-1]<'Z'+1&&s[i-1]>'A'-1&&s[i+1]<'Z'+1&&s[i+1]>'A'-1) // @@ Accessing s[i+1] when i points to the last character causes out-of-bounds error.
        {
            for(j=s[i-1]+1;j<s[i+1];j++)
            printf("%c",j);
        }
        else if(s[i-1]<'9'+1&&s[i-1]>'0'-1&&s[i+1]<'9'+1&&s[i+1]>'0'-1) // @@ Accessing s[i+1] when i points to the last character causes out-of-bounds error.
        {
            for(j=s[i-1]+1;j<s[i+1];j++)
            printf("%c",j);
        }
    } // @@ Missing else block to print s[i] when expansion conditions are not met, causing '-' to be omitted in invalid expansion cases.
    return 0;
}