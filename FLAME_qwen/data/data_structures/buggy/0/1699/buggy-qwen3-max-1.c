#include<stdio.h>
int main()
{
    char str[100000],str1[10000]; // @@ [str1 is too small; input string can be up to 100000 characters, but str1 only has 10000, leading to buffer overflow during expansion]
    gets(str); // @@ [gets() is unsafe and deprecated; also, it's not guaranteed to handle very long inputs safely, and may cause undefined behavior]
    int i,j;
    for(i=0,j=0;i<100;i++,j++) // @@ [loop only runs 100 iterations regardless of actual input length; should use strlen(str) or check for '\0']
    {
        if(str[i]!='-')
        {
            str1[j]=str[i];
        }
        else if(str[i]=='-')
        {
            j--; // @@ [decrementing j here causes the previous character (before '-') to be overwritten; should not decrement j]
            if(str[i-1]-'a'>=0&&str[i+1]-'z'<=0&&str[i+1]-str[i-1]>0) // @@ [condition is incorrect: str[i+1]-'z'<=0 means str[i+1] <= 'z', but doesn't ensure it's >= 'a'; also, mixing signed/unsigned comparisons can cause issues]
            {
                int n,t;
                n=str[i+1]-str[i-1];
                for(t=(int)str[i-1]+1;t<(int)str[i+1];t++)
                {
                    j++;
                    str1[j]=(char)t;
                }
            }
            else if(str[i-1]-'A'>=0&&str[i+1]-'Z'<=0&&str[i+1]-str[i-1]>0) // @@ [same issue as above: condition doesn't ensure both chars are uppercase letters]
            {
                int n,t;
                n=str[i+1]-str[i-1];
                for(t=(int)str[i-1]+1;t<(int)str[i+1];t++)
                {
                    j++;
                    str1[j]=(char)t;
                }
            }
            if(str[i-1]-'0'>=0&&str[i+1]-'9'<=0&&str[i+1]-str[i-1]>0) // @@ [should be 'else if' to match reference logic; also same condition flaw: doesn't ensure both are digits]
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
    puts(str1); // @@ [str1 is not null-terminated, so puts() may print garbage beyond intended output]
 }