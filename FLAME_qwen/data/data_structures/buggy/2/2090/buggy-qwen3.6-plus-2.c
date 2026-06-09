#include<stdio.h>
int main(){
    int a[100];
    char s[100];
    int i=0,j,result;
    scanf("%d %c",&a[i],&s[i]);
    while(s[i]!='='){
        i++; 
        scanf("%d %c",&a[i],&s[i]);
    }
    for(j=0;j<i;j++){
        if(s[j]=='*'||s[j]=='/'){
            if(s[j]=='*'){
                a[j+1]=a[j]*a[j+1];
                a[j]=0;
                s[j]=s[j-1]; @@ Out-of-bounds access when j=0; modifying s[j] here incorrectly affects the subsequent if condition.
            }
            if(s[j]=='/'){ @@ Should be 'else if' to prevent re-evaluating the modified s[j], which causes logical errors.
                a[j+1]=a[j]/a[j+1];
                a[j]=0;
                s[j]=s[j-1]; @@ Same out-of-bounds access and logical flaw as above.
            }
        }
    }
    result=a[0];
    for(j=0;j<i;j++){
        if(s[j]=='+') result+=a[j+1];
        else result-=a[j+1]; @@ Incorrectly assumes any non-'+' operator is '-', which fails if s[j] contains '*' or '/' due to the flawed first loop.
    }
    printf("%d",result);
    return 0;
}