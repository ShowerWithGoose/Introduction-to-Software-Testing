#include <stdio.h>
#include <string.h>
int main()
{
    char s[1000],c[1000];
    int n,i,j;
    gets(s); // @@ [Using 'gets' is unsafe and deprecated; causes compilation error in modern compilers due to security risks]
    if(s[0]=='0'){
        for(i=2;s[i]=='0';i++){
        }
        n=1-i;
        printf("%d\n",i);
        for(j=0;i<=strlen(s);j++,i++){
            c[j]=s[i];
        }
    }
    else{
        c[0]=s[0];
        c[1]='.';
        for(i=1;s[i]!='.';i++){
            c[i+1]=s[i];
        }
        n=i-1;
        for(i=i+1;i<=strlen(s);i++){
            c[i]=s[i];
        }
        printf("%se%d",c,n);
        return 0;
    }
}