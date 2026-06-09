#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>

int main()
{
    char a[1000];
    gets(a); // @@ [Using gets() is unsafe and deprecated; may cause compilation error with modern compilers due to removal from C standard]
    for(int i=0;i<strlen(a);i++)
    {
        if(a[i]=='-')
        {
            if(a[i-1]>='a'&&a[i-1]<='z'&&a[i+1]>='a'&&a[i+1]<='z'&&a[i+1]>a[i-1])
            {
                for(char c=a[i-1]+1;c<a[i+1];c++)
                {
                    printf("%c",c);
                }
            }
            else if(a[i-1]>='A'&&a[i-1]<='Z'&&a[i+1]>='A'&&a[i+1]<='Z'&&a[i+1]>a[i-1])
            {
                for(char c=a[i-1]+1;c<a[i+1];c++)
                {
                    printf("%c",c);
                }
            }  
            else if(a[i-1]>='1'&&a[i-1]<='9'&&a[i+1]>='1'&&a[i+1]<='9'&&a[i+1]>a[i-1]) // @@ [Digit range should be '0'-'9', not '1'-'9'; this misses expansions like 0-2]
            {
                for(char c=a[i-1]+1;c<a[i+1];c++)
                {
                    printf("%c",c);
                }
            }
            else 
            {
                printf("%c",a[i]);
            }
        }
        else
        {
            printf("%c",a[i]);
        }
    }


 return 0;
}