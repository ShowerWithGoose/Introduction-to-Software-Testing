#include <stdio.h>
#include <string.h> 

char s[10000000];
int i,len,j,lenth;

int main()
{
    scanf("%s",s);
    len=strlen(s);
    for(i=0;i<len;i++)
    {
        if(s[i]=='-')
        {
            if(s[i-1]>='0'&&s[i+1]<='9'&&s[i+1]>s[i-1]) // @@ Missing upper bound check for s[i-1] (s[i-1]<='9') and lower bound check for s[i+1] (s[i+1]>='0').
            {
                lenth=s[i+1]-s[i-1]; // @@ Calculates difference but loop logic causes duplication of left char and omission of right char.
                for(j=0;j<lenth;j++) // @@ Loop bounds incorrect; should iterate from s[i-1]+1 to s[i+1]-1.
                    printf("%c",s[i-1]+j); // @@ Starts printing from s[i-1], duplicating it. Should start from s[i-1]+1.
            }
            else if(s[i-1]>='a'&&s[i+1]<