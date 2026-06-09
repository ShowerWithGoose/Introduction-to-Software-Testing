#include<stdio.h>
int main()
{
    char str[100000],str1[10000];
    gets(str);
    int i,j;
    for(i=0,j=0;i<100;i++,j++) // @@ loop bound is hardcoded and j increments unconditionally, causing index gaps; should iterate until string terminator
    {
        if(str[i]!='-')
        {
            str1[j]=str[i];
        }
        else if(str[i]=='-')
        {
            j--; // @@ decrementing j is unnecessary and causes the hyphen character to be lost when no expansion occurs; should output hyphen instead
            if(str[i-1]-'a'>=0&&str[i+1]-'z'<=0&&str[i+1]-str[i-1]>0)
            {
                int n,t;
                n=str[i+1]-str[i-1];
                for(t=(int)str[i-1]+1;t<(int)str[i+1];t++)
                {
                    j++;
                    str1[j]=(char)t;
                }
            }
            else if(str[i-1]-'A'>=0&&str[i+1]-'Z'<=0&&str[i+1]-str[i-1]>0)
            {
                int n,t;
                n=str[i+1]-str[i-1];
                for(t=(int)str[i-1]+1;t<(int)str[i+1];t++)
                {
                    j++;
                    str1[j]=(char)t;
                }
            }
            if(str[i-1]-'0'>=0&&str[i+1]-'9'<=0&&str[i+1]-str[i-1]>0) // @@ should be else if to avoid checking digit condition after failing uppercase; also missing else to output hyphen when no condition matches
            {
                int n,t;
                n=str[i+1]-str[i-1];
                for(t=(int)str[i-1]+1;t<(int)str[i+1];t++)
                {
                    j++;
                    str1[j]=(char)t;
                }
            }
        } // @@ after this closing brace, there is no code to output the hyphen when none of the expansion conditions are met, causing the hyphen to be missing from the output
    }
    puts(str1);
 }