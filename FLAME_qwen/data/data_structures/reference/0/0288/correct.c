#include <stdio.h>
#include <string.h>

int main()
{
    int i=0,j=0,k=0;
    char str[1000]={};
    char exp[1000]={};

    gets(str);

    for(i=0;str[i]!='\0';i++)
    {
        if(str[i]=='-')
        {
            if(str[i-1]>='0'&&str[i-1]<='9'&&str[i+1]>='0'&&str[i+1]<='9'&&str[i+1]>str[i-1])
            {
                for(j=i+k;j<i+k+str[i+1]-str[i-1]-1;j++)
                {
                    exp[j]=exp[j-1]+1;
                }
                k+=str[i+1]-str[i-1]-1-1;
            }
            else if(str[i-1]>='a'&&str[i-1]<='z'&&str[i+1]>='a'&&str[i+1]<='z'&&str[i+1]>str[i-1])
            {
                for(j=i+k;j<i+k+str[i+1]-str[i-1]-1;j++)
                {
                    exp[j]=exp[j-1]+1;
                }
                k+=str[i+1]-str[i-1]-1-1;
            }
            else if(str[i-1]>='A'&&str[i-1]<='Z'&&str[i+1]>='A'&&str[i+1]<='Z'&&str[i+1]>str[i-1])
            {
                for(j=i+k;j<i+k+str[i+1]-str[i-1]-1;j++)
                {
                    exp[j]=exp[j-1]+1;
                }
                k+=str[i+1]-str[i-1]-1-1;
            }
            else
            {
                exp[j]=str[i];
                j++;
            }
        }
        else
        {
            exp[j]=str[i];
            j++;
        }
    }

    puts(exp);

    return 0;
}

