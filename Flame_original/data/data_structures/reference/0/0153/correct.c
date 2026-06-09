#include <stdio.h>
#include <ctype.h>
#include <string.h>

char a[100];

int main() {
    scanf("%s",a);
    int i;
    for(i=0; a[i] != '\0'; i++)
    {
        if (a[i]=='-'&&((isdigit(a[i-1])&&isdigit(a[i+1]))||(islower(a[i-1])&&islower(a[i+1]))||(isupper(a[i-1])&&isupper(a[i+1])))&&a[i-1]<a[i+1])
        {
            int c;
            c=a[i+1]-a[i-1]-2;
            int j;
            j=strlen(a);
            for(;j>=i+1;j--)
            {
                a[j+c]=a[j];
            }
            int k=i;
            char b;
            for(b=a[i-1]+1;k<=i+c+1;b++,k++)
            {
                a[k]=b;
            }
        }
    }
    printf("%s\n",a);
    return 0;
}


