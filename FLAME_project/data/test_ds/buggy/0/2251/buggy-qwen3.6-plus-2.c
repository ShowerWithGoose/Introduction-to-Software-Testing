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
            if(s[i-1]>='0'&&s[i+1]<='9'&&s[i+1]>s[i-1])
            {
                lenth=s[i+1]-s[i-1];
                for(j=0;j<lenth;j++) // @@ [Error] The loop starts from j=0, which prints s[i-1] again. Since s[i-1] was already printed in the previous iteration, it should start from j=1 to avoid duplicate characters.
                    printf("%c",s[i-1]+j);
            }
            else if(s[i-1]>='a'&&s[i+1]<='z'&&s[i+1]>s[i-1])
            {
                lenth=s[i+1]-s[i-1];
                for(j=0;j<lenth;j++) // @@ [Error] Same as above: starting from j=0 causes the left boundary character to be printed twice. Change to j=1.
                    printf("%c",s[i-1]+j);
            }
            else if(s[i-1]>='A'&&s[i+1]<='Z'&&s[i+1]>s[i-1])
            {
                lenth=s[i+1]-s[i-1];
                for(j=0;j<lenth;j++) // @@ [Error] Same as above: starting from j=0 causes the left boundary character to be printed twice. Change to j=1.
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