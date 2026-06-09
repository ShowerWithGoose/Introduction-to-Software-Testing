#include<stdio.h>
int main()
{
    char str[100000],str1[10000];
    gets(str); // @@ [Compilation Error: gets() is removed in the C11 standard and causes compilation failure in modern environments; use fgets() or scanf() instead]
    int i,j;
    for(i=0,j=0;i<100;i++,j++) // @@ [Logical Error: Hardcoded loop limit 100 instead of checking string termination (str[i] != '\0'), leading to out-of-bounds access and incorrect processing]
    {
        if(str[i]!='-')
        {
            str1[j]=str[i];
        }
        else if(str[i]=='-')
        {
            j--;
            if(str[i-1]-'a'>=0&&str[i+1]-'z'<=0&&str[i+1]-str[i-1]>0) // @@ [Logical/Runtime Error: Accessing str[i-1] when i=0 causes out-of-bounds read; lacks boundary checks for array indices]
            {
                int n,t;
                n=str[i+1]-str[i-1];
                for(t=(int)str[i-1]+1;t<(int)str[i+1];t++)
                {
                    j++;
                    str1[j]=(char)t;
                }
            }
            else if(str[i-1]-'A'>=0&&str[i+1]-'Z'<=0&&str[i+1]-str[i-1]>0) // @@ [Logical/Runtime Error: Same out-of-bounds risk when i=0; lacks boundary checks]
            {
                int n,t;
                n=str[i+1]-str[i-1];
                for(t=(int)str[i-1]+1;t<(int)str[i+1];t++)
                {
                    j++;
                    str1[j]=(char)t;
                }
            }
            if(str[i-1]-'0'>=0&&str[i+1]-'9'<=0&&str[i+1]-str[i-1]>0) // @@ [Logical Error: Should be 'else if' to prevent multiple expansions for the same '-'; also lacks boundary checks for i=0]
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
    puts(str1); // @@ [Runtime Error: str1 is not null-terminated, causing undefined behavior; add str1[j] = '\0'; before this line]
 }