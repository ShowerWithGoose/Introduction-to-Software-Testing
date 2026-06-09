#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

char a[BUFSIZ];
char b[BUFSIZ];
int flag;
int flag_1;
int i,j,k,t;

int main(){
    gets(a);
    if (a[0]=='0')
    {
       for (i = 2,t=1; a[i]=='0'; i++,t++) ;
       if (i==strlen(a)-1)  printf("%ce-%d",a[i],t);
       else{
           printf("%c.",a[i++]);
           for (;i<strlen(a);i++)printf("%c",a[i]);
           printf("e-%d",t);
       }
    }
    else{
        for (i = 1,t = 0;a[i]!='.';i++,t++);
        printf("%c.",a[0]);
        for (j = 1;j<i;j++)printf("%c",a[j]);
        for (j++;j<strlen(a);j++)printf("%c",a[j]);
        printf("e%d",t);
    }
}
