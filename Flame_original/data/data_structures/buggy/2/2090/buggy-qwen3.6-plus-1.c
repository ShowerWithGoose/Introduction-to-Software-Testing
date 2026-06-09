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
                s[j]=s[j-1]; // @@ Accessing s[-1] when j=0 causes undefined behavior; modifying s[j] here affects the subsequent if condition
            }
            if(s[j]=='/'){ // @@ Should be 'else if' because s[j] was modified in the previous block, causing incorrect execution if the previous operator was '/'
                a[j+1]=a[j]/a[j+1];
                a[j]=0;
                s[j]=s[j-1]; // @@ Accessing s[-1] when j=0 causes undefined behavior
            }
        }
    }
    result=a[0];
    for(j=0;j<i;j++){
        if(s[j]=='+') result+=a[j+1];
        else result-=a[j+1];
    }
    printf("%d",result);
    return 0;
}