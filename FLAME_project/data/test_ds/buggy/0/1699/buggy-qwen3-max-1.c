#include<stdio.h>
int main()
{
    char str[100000],str1[10000];
    gets(str); // @@ [Using gets() is unsafe and deprecated; more critically, the loop bound 'i<100' may not process full input string]
    int i,j;
    for(i=0,j=0;i<100;i++,j++) // @@ [Loop only runs up to 100 characters regardless of actual input length, causing truncation]
    {
        if(str[i]!='-')
        {
            str1[j]=str[i];
        }
        else if(str[i]=='-')
        {
            j--; // @@ [Decrementing j here assumes previous character was added, but may cause overwriting or negative index if '-' is first char]
            if(str[i-1]-'a'>=0&&str[i+1]-'z'<=0&&str[i+1]-str[i-1]>0) // @@ [Incorrect range check: 'str[i-1]-'a'>=0' allows uppercase/digits as long as >= 'a'; similarly 'str[i+1]-'z'<=0' is always true for most chars. Should use islower() and compare types consistently]
            {
                int n,t;
                n=str[i+1]-str[i-1];
                for(t=(int)str[i-1]+1;t<(int)str[i+1];t++)
                {
                    j++;
                    str1[j]=(char)t;
                }
            }
            else if(str[i-1]-'A'>=0&&str[i+1]-'Z'<=0&&str[i+1]-str[i-1]>0) // @@ [Same flawed range checking logic as above; e.g., 'str[i-1]-'A'>=0' includes lowercase letters which are > 'Z']
            {
                int n,t;
                n=str[i+1]-str[i-1];
                for(t=(int)str[i-1]+1;t<(int)str[i+1];t++)
                {
                    j++;
                    str1[j]=(char)t;
                }
            }
            if(str[i-1]-'0'>=0&&str[i+1]-'9'<=0&&str[i+1]-str[i-1]>0) // @@ [Again, incorrect digit range check: 'str[i-1]-'0'>=0' includes letters; also this is an 'if', not 'else if', so digit expansion may incorrectly occur after letter checks fail]
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