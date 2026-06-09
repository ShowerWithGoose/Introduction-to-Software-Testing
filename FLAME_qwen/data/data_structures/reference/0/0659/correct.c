#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char a[100];
    gets(a);
    for(int i=0;i<strlen(a);i++)
    {
        if(a[i]=='-')
        {
            if(a[i-1]>='a'&& a[i-1]<='z' && a[i+1]<='z' && a[i+1]>='a' && a[i-1]<a[i+1])
            {
                for(char c=a[i-1]+1;c<a[i+1];c++)
                {
                    printf("%c",c);
                }
                
            }
            
            else if(a[i-1]>='A'&& a[i-1]<='Z' && a[i+1]<='Z' && a[i+1]>='A' && a[i-1]<a[i+1])
            {
                for(char c=a[i-1]+1;c<a[i+1];c++)
                {
                    printf("%c",c);
                }
            }
            else if(a[i-1]>='0'&& a[i-1]<='9' && a[i+1]<='9' && a[i+1]>='0' && a[i-1]<a[i+1])
            {
                for(char c=a[i-1]+1;c<a[i+1];c++)
                {
                    printf("%c",c);
                }
            }
            else 
               printf("%c",a[i]);
        }
        else 
            printf("%c",a[i]);
    }
    printf("\n");
    return 0;
}




