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
            if(s[i-1]>='0'&&s[i+1]<='9'&&s[i+1]>s[i-1]) // @@ Incorrect range validation: missing s[i-1]<='9' and s[i+1]>='0'. Both characters must be checked to ensure they are digits.
            {
                lenth=s[i+1]-s[i-1];
                for(j=0;j<lenth;j++) // @@ Incorrect loop bounds: starting at 0 duplicates s[i-1] and stopping at lenth-1 omits s[i+1]. Should be j=1;j<lenth;j to print only intermediate characters.
                    printf("%c",s[i-1]+j);
            }
            else if(s[i-1]>='a'&&s[i+1]<='z'&&s[i+1]>s[i-1]) // @@ Incorrect range validation: missing s[i-1]<='z' and s[i+1]>='a'. Both characters must be checked to ensure they are lowercase letters.
            {
                lenth=s[i+1]-s[i-1];
                for(j=0;j<lenth;j++) // @@ Incorrect loop bounds: starting at 0 duplicates s[i-1] and stopping at lenth-1 omits s[i+1]. Should be j=1;j<lenth;j to print only intermediate characters.
                    printf("%c",s[i-1]+j);
            }
            else if(s[i-1]>='A'&&s[i+1]<='Z'&&s[i+1]>s[i-1]) // @@ Incorrect range validation: missing s[i-1]<='Z' and s[i+1]>='A'. Both characters must be checked to ensure they are uppercase letters.
            {
                lenth=s[i+1]-s[i-1];
                for(j=0;j<lenth;j++) // @@ Incorrect loop bounds: starting at 0 duplicates s[i-1] and stopping at lenth-1 omits s[i+1]. Should be j=1;j<lenth;j to print only intermediate characters.
                    printf("%c",s[i-1]+j);
            }
            else
                printf("-");
        }
        else 
            printf("%c",s[i]);
    }
    return 0;
}