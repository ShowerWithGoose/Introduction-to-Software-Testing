#include<stdio.h>
#include<string.h>
char a[1000000];
int main(){
    
    int i,j,k,m,n,p,w;
    gets(a);    // @@ [Using 'gets' is unsafe and deprecated; may cause compilation error with modern compilers that remove 'gets' entirely. Also, no check for empty string or leading '-'.]
    
    for(i=0;a[i]!='\0';i++){
        if(a[i]=='-'){
            if((a[i-1]>='a'&&a[i+1]<='z')||(a[i-1]>='A'&&a[i+1]<='Z')||(a[i-1]>='0'&&a[i+1]<='9')){ // @@ [Incorrect range checks: should ensure both ends are of same type, e.g., a[i-1] >= 'a' && a[i+1] <= 'z' && a[i-1] <= 'z' && a[i+1] >= 'a', but current logic allows mixed types like '0' and 'z'. Also, accessing a[i-1] when i=0 leads to undefined behavior (buffer underflow).]
                if(a[i-1]<a[i+1]){
                    j=strlen(a);
                    p=a[i+1]-a[i-1]-2;
                    w=i;
                    k=a[i+1]-a[i-1];
                    for(n=1;n<=j-i-2;n++){
                        a[i+n+1+p]=a[i+n+1]; // @@ [This shifting logic is flawed: it overwrites parts of the string incorrectly during expansion, and may write beyond array bounds. Also, assumes enough space in 'a' for expansion, which may not be true.]
                    }
                    for(m=1;m<=k;m++){
                        a[w]=a[i-1]+m; // @@ [Overwrites the '-' and subsequent characters without properly handling the original content after the range; also doesn't account for the fact that the loop starts at m=1, skipping the first character after '-', and misplaces expanded characters.]
                        w=w+1;
                    }
                }
            }
        }
    }
    printf("%s",a);
    return 0;
}