#include<stdio.h>
#include<string.h>
int main()
{
    char s[105]={'\0'};
    gets(s); // @@ [gets() is unsafe and removed from C11 standard; use fgets() instead]
    int n=strlen(s);
    if(s[0]=='0')
    {
        int x=0,y=2;
        while(s[y]=='0')
        {
            x++;
            y++;
        }
        char *p=s+y+1;
        printf("%c.%se-%d",s[y],p,x+1); // @@ [When the number is exactly "0.0", s[y] may be '\0' and p points to garbage, causing undefined behavior; also, for numbers like "0.001", the exponent calculation x+1 may be incorrect because it doesn't account for the leading zeros after the decimal point correctly]
    }
    else if(s[0]!='0')
    {
        printf("%c.",s[0]);
        int x=0,y=1;
        while(s[y]!='.')
        {
            printf("%c",s[y]);
            x++;
            y++;
        }
        printf("%se%d",s+y+1,x); // @@ [This prints the entire remaining string after the decimal point, including trailing zeros if any, but the problem states no trailing zeros; also, for numbers like "10.0", the exponent x is 1 (since only one digit '0' before decimal), but should be 1 for "1.0e1", but the output format may be wrong because it doesn't handle the case where the number has no decimal point or is an integer]
    }
    return 0;
}