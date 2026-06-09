#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
int main()
{
    int i;
    char a[1006], j;

    gets(a); // @@ [Using gets() is unsafe and deprecated; may cause compilation error with modern compilers due to removal from standard library]
    
    printf("%c", a[0]);
    for(i=1;a[i]!='\0';i++)
    {
        if(a[i]=='-'&&a[i-1]<a[i+1])
        {
            if(a[i-1]>='a'&&a[i+1]<='z') // @@ [Incorrect condition: should ensure both a[i-1] and a[i+1] are in the same category (e.g., both lowercase). This checks only lower bound of first and upper bound of second, allowing mixed cases like 'a'-'Z' to pass if 'a' <= 'Z']
        {
            for(j=a[i-1]+1;j<a[i+1];j++)
            {
                printf("%c", j);
            }
        }
        else if(a[i-1]>='A'&&a[i+1]<='Z') // @@ [Same issue: does not verify that a[i+1] >= 'A' or that a[i-1] <= 'Z', so could accept invalid ranges like '0'-'Z']
        {
            for(j=a[i-1]+1;j<a[i+1];j++)
            {
                printf("%c", j);
            }
        }
        else if(a[i-1]>='0'&&a[i+1]<='9') // @@ [Same issue: does not check that a[i+1] >= '0' or that a[i-1] <= '9', so could accept invalid ranges like 'A'-'9']
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