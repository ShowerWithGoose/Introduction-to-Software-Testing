#include<stdio.h>
int main()
{
    char str[100000],str1[10000]; // @@ [str1 size 10000 is insufficient for potential expansions of large input; buffer overflow risk]
    gets(str); // @@ [gets is unsafe and may cause compilation error in C11; use fgets instead]
    int i,j;
    for(i=0,j=0;i<100;i++,j++) // @@ [loop bound should be based on string length (e.g., i < strlen(str) or str[i] != '\0'), not fixed 100]
    {
        if(str[i]!='-')
        {
            str1[j]=str[i];
        }
        else if(str[i]=='-')
        {
            j--; // @@ [unconditionally decrementing j corrupts indexing; should not be done here]
            if(str[i-1]-'a'>=0&&str[i+1]-'z'<=0&&str[i+1]-str[i-1]>0) // @@ [condition incomplete for lowercase check; missing upper bound for str[i-1] and lower bound for str[i+1]; also no bounds check (i>0, i<len-1)]
            {
                int n,t;
                n=str[i+1]-str[i-1];
                for(t=(int)str[i-1]+1;t<(int)str[i+1];t++)
                {
                    j++;
                    str1[j]=(char)t;
                }
            }
            else if(str[i-1]-'A'>=0&&str[i+1]-'Z'<=0&&str[i+1]-str[i-1]>0) // @@ [same issues as above for uppercase]
            {
                int n,t;
                n=str[i+1]-str[i-1];
                for(t=(int)str[i-1]+1;t<(int)str[i+1];t++)
                {
                    j++;
                    str1[j]=(char)t;
                }
            }
            if(str[i-1]-'0'>=0&&str[i+1]-'9'<=0&&str[i+1]-str[i-1]>0) // @@ [should be else if to avoid redundant checks; condition incomplete for digits; no bounds check]
            {
                int n,t;
                n=str[i+1]-str[i-1];
                for(t=(int)str[i-1]+1;t<(int)str[i+1];t++)
                {
                    j++;
                    str1[j]=(char)t;
                }
            }
        } // @@ [missing else branch to copy the '-' character when no expansion condition is met]
    }
    puts(str1); // @@ [str1 is not null-terminated; leads to undefined behavior]
 }