#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
char s[1005],c[1005];
int main()
{
    scanf("%s",s);
    int i,len=strlen(s);
    int flag[1005]={},j=0,k=0;
    for(i=1;i<len-1;i++)
    {
        if(s[i]=='-'&&s[i-1]<s[i+1]&&(('a'<=s[i-1]&&s[i-1]<='z'&&'a'<=s[i+1]&&s[i+1]<='z')||('A'<=s[i-1]&&s[i-1]<='Z'&&'A'<=s[i+1]&&s[i+1]<='Z')||('0'<=s[i-1]&&s[i-1]<='9'&&'0'<=s[i+1]&&s[i+1]<='9')))
        {
            flag[j]=i;j++;
        }
    }
    
    if(j==0)
    {
        for(i=0;i<len;i++)
        {
            printf("%c",s[i]);
        }
    }
    else
    {
    printf("%d",j); // @@ [Error: prints the number of expansions, which should not be output. This causes the output to start with an extra digit (e.g., '2'), deviating from the expected expanded string.]
    for(i=0;i<flag[0];i++)
    {
        printf("%c",s[i]);
    }
    
    for(i=0;i<j;i++)
    {    
        
        for(k=s[flag[i]-1]+1;k<s[flag[i]+1];k++)
        {
            printf("%c",k);
        }
        
        if(i<j-1)
        {
        for(k=flag[i]+1;k<flag[i+1];k++)
        {
            printf("%c",s[k]);
        }
        }
        else if(i==j-1)
        {
            for(k=flag[i]+1;k<len;k++)
            {
                printf("%c",s[k]);
            }
        }
    }
    }
    
    return 0;
}