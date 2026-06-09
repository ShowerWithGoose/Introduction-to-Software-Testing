#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>


char s[10000],t[10000];
void expand(char a[],char b[]);

int main()
{
    scanf("%s",s);
    expand(s,t);
    printf("%s",t);
    return 0;
}
void expand(char a[],char b[])
{
    int len=strlen(a);
    int i,j;
    for(i=0,j=0;i<len;i++){
        if(a[i+1]=='-'&&( isupper(a[i])&&isupper(a[i+2]) || islower(a[i])&&islower(a[i+2]) || isdigit(a[i])&&isdigit(a[i+2])  )){
        	char c;
            for(c=a[i];c<a[i+2];c++)
                b[j++]=c;
            i++;
        }
        else b[j++]=a[i];
    }
}

