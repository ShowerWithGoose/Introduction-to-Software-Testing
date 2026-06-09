#include<stdio.h>
#include<string.h>
char a[1000000];
int main(){
    
    int i,j,k,m,n,p,w;
    gets(a);    
    
    for(i=0;a[i]!='\0';i++){
        if(a[i]=='-'){
            if((a[i-1]>='a'&&a[i+1]<='z')||(a[i-1]>='A'&&a[i+1]<='Z')||(a[i-1]>='0'&&a[i+1]<='9')){ // @@ [Incorrect condition; does not ensure both characters are of the same type and within valid ranges, leading to false expansion or missed expansion.]
                if(a[i-1]<a[i+1]){
                    j=strlen(a);
                    p=a[i+1]-a[i-1]-2; // @@ [Shift amount `p` is miscalculated; should be `a[i+1]-a[i-1]-1` to insert the correct number of new characters.]
                    w=i;
                    k=a[i+1]-a[i-1];
                    for(n=1;n<=j-i-2;n++){ // @@ [Loop bound off by one; should be `n<=j-i-1` to include all characters that need to be shifted.]
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