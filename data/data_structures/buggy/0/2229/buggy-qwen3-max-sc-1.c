#include<stdio.h>
#include<string.h>
char a[1000000];
int main(){
    
    int i,j,k,m,n,p,w;
    gets(a);    // @@ [Using 'gets' is unsafe and deprecated; may cause compilation error with modern compilers due to removal from standard library]
    
    for(i=0;a[i]!='\0';i++){
        if(a[i]=='-'){
            if((a[i-1]>='a'&&a[i+1]<='z')||(a[i-1]>='A'&&a[i+1]<='Z')||(a[i-1]>='0'&&a[i+1]<='9')){ // @@ [Incorrect boundary checks: should ensure both ends are of same type, e.g., a[i-1] >= 'a' && a[i+1] <= 'z' && a[i-1] <= 'z' && a[i+1] >= 'a']
                if(a[i-1]<a[i+1]){
                    j=strlen(a);
                    p=a[i+1]-a[i-1]-2;
                    w=i;
                    k=a[i+1]-a[i-1];
                    for(n=1;n<=j-i-2;n++){
                        a[i+n+1+p]=a[i+n+1]; // @@ [Potential buffer overflow: shifting characters without ensuring array bounds]
                    }
                    for(m=1;m<=k;m++){
                        a[w]=a[i-1]+m; // @@ [Overwrites the '-' and subsequent characters incorrectly; logic does not properly insert expanded sequence]
                        w=w+1;
                    }
                }
            }
        }
    }
    printf("%s",a);
    return 0;
}