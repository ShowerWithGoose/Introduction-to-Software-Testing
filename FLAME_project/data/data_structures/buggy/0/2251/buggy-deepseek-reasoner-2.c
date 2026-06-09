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
            if(s[i-1]>='0'&&s[i+1]<='9'&&s[i+1]>s[i-1]) // @@ Need to also check s[i-1]<='9' and s[i+1]>='0' to ensure both ends are within the digit range.
            {
                lenth=s[i+1]-s[i-1];
                for(j=0;j<lenth;j++) // @@ Should start from j=1 to exclude the left character, and condition should be j<lenth (since lenth equals the difference, the number of characters to print is lenth-1).
                    printf("%c",s[i-1]+j); // @@ With j starting at 0, this prints the left character, which should be omitted.
            }
            else if(s[i-1]>='a'&&s[i+1]<='z'&&s[i+1]>s[i-1]) // @@ Need to also check s[i-1]<='z' and s[i+1]>='a' to ensure both ends are within the lowercase letter range.
            {
                lenth=s[i+1]-s[i-1];
                for(j=0;j<lenth;j++) // @@ Same loop error: should start from j=1.
                    printf("%c",s[i-1]+j); // @@ Prints the left character incorrectly.
            }
            else if(s[i-1]>='A'&&s[i+1]<='Z'&&s[i+1]>s[i-1]) // @@ Need to also check s[i-1]<='Z' and s[i+1]>='A' to ensure both ends are within the uppercase letter range.
            {
                lenth=s[i+1]-s[i-1];
                for(j=0;j<lenth;j++) // @@ Same loop error: should start from j=1.
                    printf("%c",s[i-1]+j); // @@ Prints the left character incorrectly.
            }
            else
                printf("-");
        }
        else 
            printf("%c",s[i]);
    }
    return 0;
}