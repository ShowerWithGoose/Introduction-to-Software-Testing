#include<stdio.h>
#include<string.h>
int main(){
    int i,j=0,j1=-1,k=0,len,a,b; @@ [Variables 'a' and 'b' are declared but never used, which may not cause a compilation error in all compilers, but the primary issue is the use of unsafe function 'gets']
    char str[105];
    gets(str); @@ [The function 'gets' is inherently unsafe and has been removed from the C standard library since C11; using it can cause compilation errors with modern compilers that do not support it]
    len=strlen(str);
    for(i=0;i<len;i++){
        if(str[i]>'0'&&str[i]<='9'){
            j=i;
            if(j1<0)
            j1=j;    
        }
        if(str[i]=='.')
            k=i;
    }
    if(k==0){
        k=len-1;
    }
    if(j1==j){
        printf("%ce%d",str[j1],k-j1);
    }
    else{
        printf("%c.",str[j1]);
        for(i=j1+1;i<=j;i++){
            if(str[i]!='.')
                printf("%c",str[i]);
        }
        printf("e%d",k-j1-1);
    }
    return 0;
}