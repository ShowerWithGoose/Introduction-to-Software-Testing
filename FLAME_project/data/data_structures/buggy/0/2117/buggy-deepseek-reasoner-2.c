#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>

int main()
{
    char a[1000];
    gets(a);
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
            else if(a[i-1]>='1'&&a[i-1]<='9'&&a[i+1]>='1'&&a[i+1]<='9'&&a[i+1]>a[i-1]) // @@ [Error: Should include digit '0', i.e., use '0' instead of '1' to cover all digit characters.]
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