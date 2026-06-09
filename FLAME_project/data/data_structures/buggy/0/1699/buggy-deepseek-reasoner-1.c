#include<stdio.h>
int main()
{
    char str[100000],str1[10000];
    gets(str);
    int i,j;
    for(i=0,j=0;i<100;i++,j++) // @@ [Loop condition should iterate until end of string, not fixed 100; incrementing j in loop header causes incorrect indexing and skips characters]
    {
        if(str[i]!='-')
        {
            str1[j]=str[i];
        }
        else if(str[i]=='-')
        {
            j--; // @@ [Decrementing j before processing loses the dash character and disrupts index alignment; should not decrement; instead, output '-' if expansion condition fails]
            if(str[i-1]-'a'>=0&&str[i+1]-'z'<=0&&str[i+1]-str[i-1]>0) // @@ [Conditions do not correctly verify that both characters are lowercase letters; should check: str[i-1]>='a' && str[i-1]<='z' && str[i+1]>='a' && str[i+1]<='z']
            {
                int n,t;
                n=str[i+1]-str[i-1];
                for(t=(int)str[i-1]+1;t<(int)str[i+1];t++)
                {
                    j++;
                    str1[j]=(char)t;
                }
            }
            else if(str[i-1]-'A'>=0&&str[i+1]-'Z'<=0&&str[i+1]-str[i-1]>0) // @@ [Conditions do not correctly verify that both characters are uppercase letters; similar issue as above]
            {
                int n,t;
                n=str[i+1]-str[i-1];
                for(t=(int)str[i-1]+1;t<(int)str[i+1];t++)
                {
                    j++;
                    str1[j]=(char)t;
                }
            }
            if(str[i-1]-'0'>=0&&str[i+1]-'9'<=0&&str[i+1]-str[i-1]>0) // @@ [Should be else if to avoid multiple expansions; conditions also incomplete for digit range checking]
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
    puts(str1);
 }