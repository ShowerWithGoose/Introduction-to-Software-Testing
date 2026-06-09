#include<stdio.h>
int main()
{
    char c, s[1000];
    int i=0;
    gets(s);
    while(s[i]!='\0')
    {
        putchar(s[i]);
        if(s[i+1]=='-'&&s[i]<s[i+2]&&s[i]>=65&&s[i]<=90&&s[i+2]>=65&&s[i]<=90) // @@ [Error: The condition checks s[i]<=90 twice instead of s[i+2]<=90, so it incorrectly validates uppercase ranges. Also, it does not check that both characters are of the same type (e.g., 'B' and 'e' are different types but both satisfy the range checks due to this bug).]
        {
            for(c=s[i]+1;c<s[i+2];c++)
            {
                putchar(c);
            }
            i=i+2;
        }else if(s[i+1]=='-'&&s[i]<s[i+2]&&s[i]>=97&&s[i]<=122&&s[i+2]>=97&&s[i+2]<=122)
        {
            for(c=s[i]+1;c<s[i+2];c++)
            {
                putchar(c);
            }
            i=i+2;
        }else if(s[i+1]=='-'&&s[i]<s[i+2]&&s[i]>=48&&s[i]<=57&&s[i+2]>=48&&s[i+2]<=57)
        {
            for(c=s[i]+1;c<s[i+2];c++)
            {
                putchar(c);
            }
            i=i+2;
        }
        else{
            i++;
        }
    }
    return 0;
}