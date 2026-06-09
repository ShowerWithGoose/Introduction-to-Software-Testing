#include<stdio.h>
#include<string.h>
char a[1000000];
int main(){
    
    int i,j,k,m,n,p,w;
    gets(a);    
    
    for(i=0;a[i]!='\0';i++){
        if(a[i]=='-'){
            if((a[i-1]>='a'&&a[i+1]<='z')||(a[i-1]>='A'&&a[i+1]<='Z')||(a[i-1]>='0'&&a[i+1]<='9')){ // @@ [Error: The condition checks if both characters are within the same range, but it does not ensure they are of the same type. For example, 'a' and 'z' are both lowercase, but 'a' and 'Z' would also pass because 'a' >= 'a' and 'Z' <= 'z' is false, but 'a' >= 'a' and 'Z' <= 'z' is false, but the condition for uppercase would also be checked. However, the main issue is that the condition should require both characters to be in the same specific range, not just one in each. For example, 'a' and '9' would fail because 'a' >= 'a' is true but '9' <= 'z' is true, so it would incorrectly pass. The correct condition should be: ((a[i-1]>='a' && a[i+1]<='z' && a[i-1]<='z' && a[i+1]>='a') || ...) but more simply, check both are in the same range: (a[i-1]>='a' && a[i-1]<='z' && a[i+1]>='a' && a[i+1]<='z') etc.]
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