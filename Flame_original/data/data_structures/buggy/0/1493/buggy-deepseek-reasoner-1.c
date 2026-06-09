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
        if(a[i]=='-'&&a[i-1]<a[i+1])
        {
            if(a[i-1]>='a'&&a[i+1]<='z') // @@ Error: Condition does not ensure both characters are lowercase letters. It only checks left >= 'a' and right <= 'z', allowing right to be an uppercase letter (e.g., 'B') while left is lowercase, causing incorrect expansion or missing dash.
        {
            for(j=a[i-1]+1;j<a[i+1];j++)
            {
                printf("%c", j);
            }
        }
        else if(a[i-1]>='A'&&a[i+1]<='Z') // @@ Error: Condition does not ensure both characters are uppercase letters. It only checks left >= 'A' and right <= 'Z', allowing left to be a character below 'A'? Actually left could be something like '[' (91) which is >= 'A' but not uppercase, and right could be a digit (e.g., '0' which is <= 'Z'), leading to improper expansion.
        {
            for(j=a[i-1]+1;j<a[i+1];j++)
            {
                printf("%c", j);
            }
        }
        else if(a[i-1]>='0'&&a[i+1]<='9') // @@ Error: Condition does not ensure both characters are digits. It only checks left >= '0' and right <= '9', allowing left to be a non-digit character like ':' (58) which is >= '0', and right could be a punctuation mark less than '9'. This may cause incorrect expansion.
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