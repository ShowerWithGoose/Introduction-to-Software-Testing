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
            if(a[i-1]>='a'&&a[i+1]<='z') @@ // Error: Does not ensure both characters are lowercase; e.g., 'B'-'e' passes a[i-1] < a[i+1] and a[i+1] <= 'z', but a[i-1] is uppercase, so should not expand.
        {
            for(j=a[i-1]+1;j<a[i+1];j++)
            {
                printf("%c", j);
            }
        }
        else if(a[i-1]>='A'&&a[i+1]<='Z') @@ // Error: Does not ensure both characters are uppercase; e.g., 'D'-'e' would have a[i+1]='e' > 'Z', so skipped, but case like 'a'-'E' might incorrectly pass other conditions or fall through incorrectly. More critically, mixed-type cases like 'B'-'e' are not properly rejected because only one side's range is checked.
        {
            for(j=a[i-1]+1;j<a[i+1];j++)
            {
                printf("%c", j);
            }
        }
        else if(a[i-1]>='0'&&a[i+1]<='9') @@ // Error: Similarly, only checks that left is digit and right <= '9', but doesn't verify right is >= '0'; also doesn't ensure both are digits. For example, '-0' with a[i-1]='/' (not digit) could theoretically pass if a[i+1] <= '9', but more importantly, mixed cases like 'a'-'5' may not be caught because condition only checks bounds, not type consistency.
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