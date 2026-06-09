#include<stdio.h>
int main()
{
    char str[100000],str1[10000];
    gets(str); // @@ Using gets is unsafe and deprecated; also, it does not handle buffer overflow, but more critically, it does not null-terminate str1 after operations.
    int i,j;
    for(i=0,j=0;i<100;i++,j++) // @@ Hardcoded loop limit 100; should iterate until the end of string (str[i] != '\0'). Also, incrementing j unconditionally leads to incorrect indexing after expansion.
    {
        if(str[i]!='-')
        {
            str1[j]=str[i];
        }
        else if(str[i]=='-')
        {
            j--; // @@ Decrementing j without considering i==0 leads to out-of-bounds access on str[i-1] and also corrupts index logic.
            if(str[i-1]-'a'>=0&&str[i+1]-'z'<=0&&str[i+1]-str[i-1]>0) // @@ Condition incomplete: only checks lower bound for first and upper bound for second; should check both characters fully in [a-z] (e.g., 'a'>= and <= 'z' for both). Also missing check that both are in same case range.
            {
                int n,t;
                n=str[i+1]-str[i-1];
                for(t=(int)str[i-1]+1;t<(int)str[i+1];t++)
                {
                    j++;
                    str1[j]=(char)t;
                }
            }
            else if(str[i-1]-'A'>=0&&str[i+1]-'Z'<=0&&str[i+1]-str[i-1]>0) // @@ Same issue as above for uppercase letters.
            {
                int n,t;
                n=str[i+1]-str[i-1];
                for(t=(int)str[i-1]+1;t<(int)str[i+1];t++)
                {
                    j++;
                    str1[j]=(char)t;
                }
            }
            if(str[i-1]-'0'>=0&&str[i+1]-'9'<=0&&str[i+1]-str[i-1]>0) // @@ Same issue for digits; also this should be an else-if to avoid multiple expansions when not all conditions are mutually exclusive (though unlikely here).
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
    puts(str1); // @@ No null terminator added to str1; puts will read beyond the valid data until a null byte, causing undefined behavior.
 }