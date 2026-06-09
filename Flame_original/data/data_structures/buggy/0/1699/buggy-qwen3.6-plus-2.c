#include<stdio.h>
int main()
{
    char str[100000],str1[10000];
    gets(str); // @@ gets() is removed in C11 standard, causing compilation errors in modern strict environments; use fgets() or scanf() instead.
    int i,j;
    for(i=0,j=0;i<100;i++,j++) // @@ Hardcoded loop bound 100 ignores actual string length and null terminator, leading to out-of-bounds access and incorrect processing.
    {
        if(str[i]!='-')
        {
            str1[j]=str[i];
        }
        else if(str[i]=='-')
        {
            j--;
            if(str[i-1]-'a'>=0&&str[i+1]-'z'<=0&&str[i+1]-str[i-1]>0) // @@ Logic error: range check is incomplete (missing upper/lower bounds) and accesses str[-1] when i=0, causing undefined behavior.
            {
                int n,t;
                n=str[i+1]-str[i-1];
                for(t=(int)str[i-1]+1;t<(int)str[i+1];t++)
                {
                    j++;
                    str1[j]=(char)t;
                }
            }
            else if(str[i-1]-'A'>=0&&str[i+1]-'Z'<=0&&str[i+1]-str[i-1]>0) // @@ Logic error: same incomplete range check and potential out-of-bounds access.
            {
                int n,t;
                n=str[i+1]-str[i-1];
                for(t=(int)str[i-1]+1;t<(int)str[i+1];t++)
                {
                    j++;
                    str1[j]=(char)t;
                }
            }
            if(str[i-1]-'0'>=0&&str[i+1]-'9'<=0&&str[i+1]-str[i-1]>0) // @@ Logic error: should be 'else if' to prevent multiple expansions, and range check is incomplete.
            {
                int n,t;
                n=str[i+1]-str[i-1];
                for(t=(int)str[i-1]+1;t<(int)str[i+1];t++)
                {
                    j++;
                    str1[j]=(char)t;
                }
            }
        }
    }
    puts(str1); // @@ str1 is not null-terminated, causing undefined behavior at runtime; must add str1[j] = '\0'; before output.
 }