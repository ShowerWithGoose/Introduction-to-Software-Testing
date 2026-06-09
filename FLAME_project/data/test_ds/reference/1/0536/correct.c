#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int type(int);
int main()
{
    char s[100];
    int i,j,k,l;
    gets(s);
    j=strlen(s);
    for(i=0;i<j;i++){
        if(i==0||i==j-1||s[i]!='-')
            putchar(s[i]);
        else if((type(s[i-1])==type(s[i+1]))&&(s[i+1]-s[i-1]>0)){
            k=s[i+1]-s[i-1];
            for(l=1;l<k;l++)
                putchar(s[i-1]+l);
        }
        else
            putchar(s[i]);
    }
    return 0;
}
int type(int a)
{
    if(islower(a)!=0)
        return 1;
    if(isupper(a)!=0)
        return 2;
    if(isdigit(a)!=0)
        return 3;
}



