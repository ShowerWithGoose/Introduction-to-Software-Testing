#include<stdio.h>
#include<string.h>
char a[1000000];
int main(){
    
    int i,j,k,m,n,p,w;
    gets(a);    
    
    for(i=0;a[i]!='\0';i++){
        if(a[i]=='-'){
            if((a[i-1]>='a'&&a[i+1]<='z')||(a[i-1]>='A'&&a[i+1]<='Z')||(a[i-1]>='0'&&a[i+1]<='9')){ @@ [The condition checks only one side of the range; it should ensure both characters are of the same type, e.g., both lowercase, both uppercase, or both digits. For example, 'a' and 'Z' would incorrectly pass the current check.]
                if(a[i-1]<a[i+1]){
                    j=strlen(a);
                    p=a[i+1]-a[i-1]-2;
                    w=i;
                    k=a[i+1]-a[i-1];
                    for(n=1;n<=j-i-2;n++){
                        a[i+n+1+p]=a[i+n+1]; @@ [This shifting logic is flawed: it writes beyond the current string length without ensuring sufficient space, and may overwrite memory. Also, the index calculation is incorrect for inserting multiple characters.]
                    }
                    for(m=1;m<=k;m++){
                        a[w]=a[i-1]+m; @@ [This overwrites the '-' and subsequent characters without properly handling the expansion; it does not insert the full range (missing the starting character) and corrupts the string structure.]
                        w=w+1;
                    }
                }
            }
        }
    }
    printf("%s",a);
    return 0;
}