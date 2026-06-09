#include<stdio.h>
int main()
{
    char str[100000],str1[10000]; // @@ [str1 is too small; input string can be up to 100000 characters and expansion may make it longer, causing buffer overflow]
    gets(str); // @@ [gets() is unsafe and deprecated; also, the problem expects reading a single string possibly with spaces? But more critically, gets() may cause buffer overflow and is not allowed in modern C standards, leading to compilation errors in strict environments]
    int i,j;
    for(i=0,j=0;i<100;i++,j++) // @@ [loop only runs 100 iterations regardless of actual input length; should use strlen(str) or check for '\0']
    {
        if(str[i]!='-')
        {
            str1[j]=str[i];
        }
        else if(str[i]=='-')
        {
            j--; // @@ [decrementing j here causes the previous character (before '-') to be overwritten; but according to spec, we should keep the starting character and expand between, so this logic is flawed]
            if(str[i-1]-'a'>=0&&str[i+1]-'z'<=0&&str[i+1]-str[i-1]>0) // @@ [condition str[i+1]-'z'<=0 is incorrect; should check str[i+1] >= 'a' && str[i+1] <= 'z'; current condition allows any char <= 'z', including non-lowercase]
            {
                int n,t;
                n=str[i+1]-str[i-1];
                for(t=(int)str[i-1]+1;t<(int)str[i+1];t++)
                {
                    j++;
                    str1[j]=(char)t;
                }
            }
            else if(str[i-1]-'A'>=0&&str[i+1]-'Z'<=0&&str[i+1]-str[i-1]>0) // @@ [same issue: str[i+1]-'Z'<=0 allows any char <= 'Z', not just uppercase letters]
            {
                int n,t;
                n=str[i+1]-str[i-1];
                for(t=(int)str[i-1]+1;t<(int)str[i+1];t++)
                {
                    j++;
                    str1[j]=(char)t;
                }
            }
            if(str[i-1]-'0'>=0&&str[i+1]-'9'<=0&&str[i+1]-str[i-1]>0) // @@ [same issue: str[i+1]-'9'<=0 allows any char <= '9', including non-digits like '+' or letters]
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