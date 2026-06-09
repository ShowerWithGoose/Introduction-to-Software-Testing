#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char s[200],news[200];



int is(int i)
{
    if(s[i]>='0'&&s[i]<='9'&&s[i+2]>='0'&&s[i+2]<='9') return 1;
    if(s[i]>='a'&&s[i]<='z'&&s[i+2]>='a'&&s[i+2]<='z') return 1;
    if(s[i]>='A'&&s[i]<='Z'&&s[i+2]>='A'&&s[i+2]<='Z') return 1;
    return 0;
}





int main()
{
    int i,j,k;
    gets(s);
    for(i=0,j=0;s[i]!='\0';i++)
    {
        news[j++]=s[i];
        if(s[i+1]=='-')
        {
            if(is(i)==0)
            {
                news[j++]=s[++i];
                continue;
            }
            else
            {
                for(k=1;k<s[i+2]-s[i];k++)
                {
                    news[j++]=s[i]+k;
                }
                i++;
            }
        }


    }
    news[j]='\0';
    printf("%s",news);

    return 0;
}





