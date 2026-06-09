#include<stdio.h>
#include<string.h>
int main()
{
    char a[100];
    int i,j;
    fgets(a,100,stdin);
    for(i=0;i<strlen(a);i++)
    {
        if(a[i]=='-')
        {
            // Missing bounds check: i must be > 0 and i < strlen(a)-1 to safely access a[i-1] and a[i+1]
            if((a[i-1]>='a')&&(a[i-1]<='z'))
            {
                // Error: Missing check that a[i+1] is also a lowercase letter and within bounds.
                // Also, a[i+1] should be > a[i-1] (already satisfied by loop condition j<a[i+1] if a[i+1] is a valid letter, but we must ensure it's a letter)
                for(j=a[i-1]+1;j<a[i+1];j++)
                {printf("%c",j);}
            }
            else if((a[i-1]>='A')&&(a[i-1]<='Z'))
            {
                // Same as above: missing check for a[i+1] being uppercase letter and within bounds
                for(j=a[i-1]+1;j<a[i+1];j++)
                {printf("%c",j);}
            }
            else if((a[i-1]>='0')&&(a[i-1]<='9'))
            {
                // Same as above: missing check for a[i+1] being a digit and within bounds
                for(j=a[i-1]+1;j<a[i+1];j++)
                {printf("%c",j);}
            }
        }
        else
        {printf("%c",a[i]);}
    }
    return 0;
}