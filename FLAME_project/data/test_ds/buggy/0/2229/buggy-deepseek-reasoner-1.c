#include<stdio.h>
#include<string.h>
char a[1000000];
int main(){
    
    int i,j,k,m,n,p,w;
    gets(a);    
    
    for(i=0;a[i]!='\0';i++){
        if(a[i]=='-'){
            if((a[i-1]>='a'&&a[i+1]<='z')||(a[i-1]>='A'&&a[i+1]<='Z')||(a[i-1]>='0'&&a[i+1]<='9')){ // @@ Error: Condition only checks left >= start and right <= end, not that both are within the same character class. For example, '0' and 'A' would be incorrectly considered same type because '0'>='0' true and 'A'<='9' false (this case fails, but other cross-type cases like 'a' and 'Z' would pass leading to undesired expansion).
                if(a[i-1]<a[i+1]){
                    j=strlen(a);
                    p=a[i+1]-a[i-1]-2;
                    w=i;
                    k=a[i+1]-a[i-1];
                    for(n=1;n<=j-i-2;n++){ // @@ Error: This forward shifting loop does not move the null terminator, causing the string to become unterminated or overwritten. Also, it does not update the string length, leading to memory corruption and incorrect output (as seen when the second expansion overwrites the null with '-' and later characters).
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