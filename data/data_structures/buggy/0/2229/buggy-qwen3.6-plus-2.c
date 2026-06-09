#include<stdio.h>
#include<string.h>
char a[1000000];
int main(){

    int i,j,k,m,n,p,w;
    gets(a); // @@ gets is deprecated and removed in C11, causing compilation errors in modern environments; also unsafe.

    for(i=0;a[i]!='\0';i++){ // @@ Loop starts at 0, causing out-of-bounds access to a[i-1] when i=0.
        if(a[i]=='-'){
            if((a[i-1]>='a'&&a[i+1]<='z')||(a[i-1]>='A'&&a[i+1]<='Z')||(a[i-1]>='0'&&a[i+1]<='9')){ // @@ Incorrect type validation; fails to ensure both characters are strictly within the same category range.
                if(a[i-1]<a[i+1]){
                    j=strlen(a);
                    p=a[i+1]-a[i-1]-2;
                    w=i;
                    k=a[i+1]-a[i-1];
                    for(n=1;n<=j-i-2;n++){ // @@ Loop bound is off by one; fails to shift the null terminator, resulting in an unterminated string after expansion.
                        a[i+n+1+p]=a[i+n+1];
                    }
                    for(m=1;m<=k;m++){
                        a[w]=a[i-1]+m;
                        w=w+1;
                    }
                }
            }
        }
    }
    printf("%s",a);
    return 0;
}