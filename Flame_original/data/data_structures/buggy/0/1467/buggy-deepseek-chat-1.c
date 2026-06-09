#include<stdio.h>
#include<string.h>

int main()
{
    char str[1000];
    gets(str);
    int i;
    for(i=0;str[i]!='\0';i++)
    {
        if (str[i]!='-')
            putchar(str[i]);        
        else
        {
            if (str[i-1]>='a' && str[i+1]<='z' && str[i-1]<str[i+1]) // @@ Error: The condition should check that both characters are within the same range, not just the first is >= 'a' and the second is <= 'z'. For example, 'a' and 'z' would pass, but 'a' and 'b' should also pass. The correct condition should be: (str[i-1]>='a' && str[i-1]<='z') && (str[i+1]>='a' && str[i+1]<='z') && str[i-1]<str[i+1]
            {
                for(int k=1,j=str[i+1]-str[i-1];k<j;k++)
                {
                    char sto=str[i-1];
                    printf("%c",sto+k);
                }
            }
            if (str[i-1]>='0' && str[i+1]<='9' && str[i-1]<str[i+1]) // @@ Error: Same issue as above. The condition should check both characters are digits: (str[i-1]>='0' && str[i-1]<='9') && (str[i+1]>='0' && str[i+1]<='9') && str[i-1]<str[i+1]
            {
                for(int k=1,j=str[i+1]-str[i-1];k<j;k++)
                {
                    char sto=str[i-1];
                    printf("%c",sto+k);
                }
            }
            if (str[i-1]>='A' && str[i+1]<='Z' && str[i-1]<str[i+1]) // @@ Error: Same issue. Should be: (str[i-1]>='A' && str[i-1]<='Z') && (str[i+1]>='A' && str[i+1]<='Z') && str[i-1]<str[i+1]
            {
                for(int k=1,j=str[i+1]-str[i-1];k<j;k++)
                {
                    char sto=str[i-1];
                    printf("%c",sto+k);
                }
            } 
        }

    }
    return 0;
}