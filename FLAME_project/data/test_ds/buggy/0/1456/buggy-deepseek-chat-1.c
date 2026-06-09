#include<stdio.h>
int main()
{
    char c, s[1000];
    int i=0;
    gets(s);
    while(s[i]!='\0')
    {
        putchar(s[i]);
        if(s[i+1]=='-'&&s[i]<s[i+2]&&s[i]>=65&&s[i]<=90&&s[i+2]>=65&&s[i]<=90) // @@ [Error: The condition checks s[i]<=90 instead of s[i+2]<=90, so it incorrectly validates the second character's range using the first character's value. For input "B-e", s[i]='B' (66), s[i+2]='e' (101), the condition s[i+2]>=65&&s[i]<=90 becomes 101>=65&&66<=90 which is true, causing expansion when it should not, because 'B' and 'e' are different types.]
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