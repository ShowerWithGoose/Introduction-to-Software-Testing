#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
int main()
{
    int i;
    char a[1006], j;

    gets(a);
    
    printf("%c", a[0]);
    for(i=1;a[i]!='\0';i++)
    {
        if(a[i]=='-'&&a[i-1]<a[i+1]) // @@ The condition does not require both characters to be of the same type; it enters the block for mismatched types, and when the inner type checks fail, the dash is not printed, causing omission of the hyphen.
        {
            if(a[i-1]>='a'&&a[i+1]<='z') // @@ This does not ensure both characters are lowercase; it only checks left >= 'a' and right <= 'z', which can match mismatched types (e.g., 'a' and 'Z'), leading to incorrect expansions or missing dash.
        {
            for(j=a[i-1]+1;j<a[i+1];j++)
            {
                printf("%c", j);
            }
        }
        else if(a[i-1]>='A'&&a[i+1]<='Z') // @@ Similarly, this does not guarantee both are uppercase; it can match a lowercase on the right (e.g., 'A' and 'z'), causing erroneous behavior.
        {
            for(j=a[i-1]+1;j<a[i+1];j++)
            {
                printf("%c", j);
            }
        }
        else if(a[i-1]>='0'&&a[i+1]<='9') // @@ This does not ensure both are digits; it can match a letter on the left (e.g., 'B' and '5') due to ASCII ordering, leading to wrong expansions or missing dash.
        {
            for(j=a[i-1]+1;j<a[i+1];j++)
            {
                printf("%c", j);
            }
        }
        }
        
        else
        {
            printf("%c", a[i]);
        }
        
    }
    
    
    return 0;
}