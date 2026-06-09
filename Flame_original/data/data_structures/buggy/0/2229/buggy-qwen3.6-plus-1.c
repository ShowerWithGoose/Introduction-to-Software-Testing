#include<stdio.h>
#include<string.h>
char a[1000000];
int main(){

    int i,j,k,m,n,p,w;
    gets(a);    // @@ gets() is removed in the C11 standard and causes compilation errors in modern environments; use fgets() instead.

    for(i=0;a[i]!='\0';i++){ // @@ Loop starts at i=0, but a[i-1] is accessed inside, causing out-of-bounds memory access when i=0. Should start at i=1 or add a boundary check.
        if(a[i]=='-'){
            if((a[i-1]>='a'&&a[i+1]<='z')||(a[i-1]>='A'&&a[i+1]<='Z')||(a[i-1]>='0'&&a[i+1]<='9')){ // @@ Logical error in range checking: mixes bounds for a[i-1] and a[i+1], failing to ensure both characters belong to the same type. Should verify both characters fall within the exact same range (e.g., both lowercase, both uppercase, or both digits).
                if(a[i-1]<a[i+1]){
                    j=strlen(a);
                    p=a[i+1]-a[i-1]-2; // @@ If the difference between characters is 1 (e.g., "a-b"), p becomes negative, leading to incorrect array indexing and potential data corruption during the shift loop.
                    w=i;
                    k=a[i+1]-a[i-1];
                    for(n=1;n<=j-i-2;n++){
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