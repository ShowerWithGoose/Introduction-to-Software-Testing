#include<stdio.h>
int main()
{
    char str[100000],str1[10000]; // @@ [str1 is too small; input string can be up to 100000 characters and expansion may make it longer, causing buffer overflow]
    gets(str); // @@ [gets() is unsafe and deprecated; also, the problem expects reading until end of input string, but loop only runs 100 iterations regardless of actual length]
    int i,j;
    for(i=0,j=0;i<100;i++,j++) // @@ [loop only processes first 100 characters regardless of actual input length; should use strlen or check for '\0']
    {
        if(str[i]!='-')
        {
            str1[j]=str[i];
        }
        else if(str[i]=='-')
        {
            j--; // @@ [decrementing j here causes overwriting of previous character; logic is flawed because '-' itself should not be copied only when expanded, but this breaks indexing]
            if(str[i-1]-'a'>=0&&str[i+1]-'z'<=0&&str[i+1]-str[i-1]>0) // @@ [condition str[i+1]-'z'<=0 is incorrect; should check str[i+1] >= 'a' && str[i+1] <= 'z'; current condition allows non-lowercase chars like '{' (ASCII > 'z') to pass]
            {
                int n,t;
                n=str[i+1]-str[i-1];
                for(t=(int)str[i-1]+1;t<(int)str[i+1];t++)
                {
                    j++;
                    str1[j]=(char)t;
                }
            }
            else if(str[i-1]-'A'>=0&&str[i+1]-'Z'<=0&&str[i+1]-str[i-1]>0) // @@ [same issue: str[i+1]-'Z'<=0 is wrong; should be str[i+1] >= 'A' && str[i+1] <= 'Z']
            {
                int n,t;
                n=str[i+1]-str[i-1];
                for(t=(int)str[i-1]+1;t<(int)str[i+1];t++)
                {
                    j++;
                    str1[j]=(char)t;
                }
            }
            if(str[i-1]-'0'>=0&&str[i+1]-'9'<=0&&str[i+1]-str[i-1]>0) // @@ [same issue: str[i+1]-'9'<=0 is wrong; should be str[i+1] >= '0' && str[i+1] <= '9'; also this block is not in else-if chain, so may execute after letter expansions]
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
    puts(str1); // @@ [str1 is not null-terminated, leading to undefined behavior when printed with puts()]
 }