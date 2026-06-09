#include<stdio.h>
int main()
{
    char str[100000],str1[10000]; // @@ [str1 is too small; input string can be up to 100000 characters, but str1 only has 10000, risking buffer overflow during expansion]
    gets(str); // @@ [gets() is unsafe and deprecated; also, it may read beyond array bounds if input exceeds 99999 characters]
    int i,j;
    for(i=0,j=0;i<100;i++,j++) // @@ [loop only runs 100 iterations regardless of actual input length; should use strlen(str) or check for '\0']
    {
        if(str[i]!='-')
        {
            str1[j]=str[i];
        }
        else if(str[i]=='-')
        {
            j--; // @@ [decrementing j here causes the previous character (before '-') to be overwritten in some cases, which is incorrect]
            if(str[i-1]-'a'>=0&&str[i+1]-'z'<=0&&str[i+1]-str[i-1]>0) // @@ [condition is wrong: 'str[i+1] - 'z' <= 0' allows any character <= 'z', not just lowercase letters; should check both ends are in [a-z]]
            {
                int n,t;
                n=str[i+1]-str[i-1];
                for(t=(int)str[i-1]+1;t<(int)str[i+1];t++)
                {
                    j++;
                    str1[j]=(char)t;
                }
            }
            else if(str[i-1]-'A'>=0&&str[i+1]-'Z'<=0&&str[i+1]-str[i-1]>0) // @@ [same issue: 'str[i+1] - 'Z' <= 0' allows non-uppercase chars; should ensure both are in [A-Z]]
            {
                int n,t;
                n=str[i+1]-str[i-1];
                for(t=(int)str[i-1]+1;t<(int)str[i+1];t++)
                {
                    j++;
                    str1[j]=(char)t;
                }
            }
            if(str[i-1]-'0'>=0&&str[i+1]-'9'<=0&&str[i+1]-str[i-1]>0) // @@ [same logical error: 'str[i+1] - '9' <= 0' includes non-digit chars; should check both in [0-9]. Also, this should be 'else if' to avoid overlapping with letter cases]
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