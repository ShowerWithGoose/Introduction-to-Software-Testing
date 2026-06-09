#include<stdio.h>
int main()
{
    char str[100000],str1[10000];
    gets(str);
    int i,j;
    for(i=0,j=0;i<100;i++,j++) // @@ [Error: The loop condition i<100 is incorrect; it should be i < strlen(str) to iterate over the entire input string. Using a fixed value of 100 may miss characters or cause out-of-bounds access.]
    {
        if(str[i]!='-')
        {
            str1[j]=str[i];
        }
        else if(str[i]=='-')
        {
            j--;
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
            if(str[i-1]-'0'>=0&&str[i+1]-'9'<=0&&str[i+1]-str[i-1]>0) // @@ [Error: This should be else if instead of if, to ensure only one expansion case is handled per '-'. Otherwise, for digit ranges, it may incorrectly execute after a previous condition was already met.]
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