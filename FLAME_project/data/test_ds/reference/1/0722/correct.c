#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    char a[1000];
    int i;
    char k;
    scanf ("%s",&a);
    for (i=0;a[i]!='\0';i++)
    {
       
        if(a[i]=='-'&&a[i+1]>a[i-1]&&((a[i-1]>='a'&&a[i+1]<='z')||(a[i-1]>='A'&&a[i+1]<='Z')||(a[i-1]>='0'&&a[i+1]<='9')))
            {
                k=a[i-1]+1;
               while (k!=a[i+1])
               {
                  printf("%c",k);
                   k++;
               }
            }
        else
        {
            printf("%c",a[i]);
        }
        
    }
    
    
    return 0;
}

