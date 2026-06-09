#include<stdio.h>
#include<string.h>
char a[1000000];
int main(){
    
    int i,j,k,m,n,p,w;
    gets(a);    // @@ [The function 'gets' is unsafe and has been removed from the C standard library since C11; many compilers no longer support it, leading to compilation errors. Use 'fgets' instead.]

    for(i=0;a[i]!='\0';i++){
        if(a[i]=='-'){
            if((a[i-1]>='a'&&a[i+1]<='z')||(a[i-1]>='A'&&a[i+1]<='Z')||(a[i-1]>='0'&&a[i+1]<='9')){
                if(a[i-1]<a[i+1]){
                    j=strlen(a);
                    p=a[i+1]-a[i-1]-2;
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