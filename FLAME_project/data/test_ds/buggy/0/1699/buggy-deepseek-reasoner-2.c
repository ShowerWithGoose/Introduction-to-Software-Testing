#include<stdio.h>
int main()
{
    char str[100000],str1[10000];
    gets(str); // Unsafe, but not primary error for this test case
    int i,j;
    for(i=0,j=0;i<100;i++,j++) // @@ Loop bound i<100 may truncate input; unconditional j++ causes index misalignment
    {
        if(str[i]!='-')
        {
            str1[j]=str[i];
        }
        else if(str[i]=='-') // @@ The following block does not output '-' when no expansion occurs (e.g., "B-e")
        {
            j--; // @@ Incorrectly decrements j, overwriting previous character
            if(str[i-1]-'a'>=0&&str[i+1]-'z'<=0&&str[i+1]-str[i-1]>0) // @@ Missing else clause for non-expanding '-'
            {
                int n,t;
                n=str[i+1]-str[i-1];
                for(t=(int)str[i-1]+1;t<(int)str[i+1];t++) // @@ Only prints inner characters, missing endpoints
                {
                    j++;
                    str1[j]=(char)t;
                }
            }
            else if(str[i-1]-'A'>=0&&str[i+1]-'Z'<=0&&str[i+1]-str[i-1]>0) // @@ Same missing else issue
            {
                int n,t;
                n=str[i+1]-str[i-1];
                for(t=(int)str[i-1]+1;t<(int)str[i+1];t++) // @@ Missing endpoints in expansion
                {
                    j++;
                    str1[j]=(char)t;
                }
            }
            if(str[i-1]-'0'>=0&&str[i+1]-'9'<=0&&str[i+1]-str[i-1]>0) // @@ Should be else if; also missing else
            {
                int n,t;
                n=str[i+1]-str[i-1];
                for(t=(int)str[i-1]+1;t<(int)str[i+1];t++) // @@ Missing endpoints
                {
                    j++;
                    str1[j]=(char)t;
                }
            }
        }
    }
    puts(str1); // @@ str1 not null-terminated; may print garbage
 }