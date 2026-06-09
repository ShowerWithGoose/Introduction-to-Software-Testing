#include<stdio.h>
#include<string.h>
char a[1000000];
int main(){
    
    int i,j,k,m,n,p,w;
    gets(a);    
    
    for(i=0;a[i]!='\0';i++){
        if(a[i]=='-'){
            if((a[i-1]>='a'&&a[i+1]<='z')||(a[i-1]>='A'&&a[i+1]<='Z')||(a[i-1]>='0'&&a[i+1]<='9')){ // @@ The condition does not require both characters to be in the same character class (lowercase, uppercase, digit). For example, '0' and 'A' satisfy this condition incorrectly, leading to undesired expansion.
                if(a[i-1]<a[i+1]){
                    j=strlen(a);
                    p=a[i+1]-a[i-1]-2; // @@ p should be a[i+1]-a[i-1]-1 (the number of characters to insert). Using -2 gives an incorrect shift amount.
                    w=i;
                    k=a[i+1]-a[i-1];
                    for(n=1;n<=j-i-2;n++){ // @@ The loop bound j-i-2 is wrong; it should be based on the number of new characters to insert (p+1). Also, j is the original length, which may have changed due to previous expansions.
                        a[i+n+1+p]=a[i+n+1]; // @@ Copying from left to right in the same array causes overwriting of unshifted data. Should iterate from right to left (starting from the last character) to avoid data loss.
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