#include <stdio.h>
#include <malloc.h>
#include <string.h>
int f(int x,char op,int y){
    if(op=='+'){
        return x+y;
    }
    else if(op=='-'){
        return x-y;
    }
    else if(op=='*'){
        return x*y;
    }
    else{
        return x/y;
    }
}
int main()
{
    int * p=(int *)malloc(sizeof(int)); // @@ [Insufficient memory allocation: only space for one integer, but multiple numbers may be stored]
    char * q=(char *)malloc(sizeof(char)); // @@ [Insufficient memory allocation: only space for one character, but multiple operators may be stored]
    int cur=0,i=0;
    char temp;
    while(scanf("%c",&temp)!=EOF){ // @@ [Loop does not stop at '=', continues reading beyond '=' which may cause incorrect parsing or infinite loop if input doesn't end with EOF immediately after '=']
        if(temp>='0' && temp<='9'){
            cur=cur*10+temp-'0';
        }
        else if(temp=='+' || temp=='-' || temp=='*' || temp=='/' || temp=='='){
            p[i]=cur; // @@ [Writes beyond allocated memory when i >= 1 because p has space for only one int]
            cur=0;
            q[i++]=temp; // @@ [Writes beyond allocated memory when i >= 1 because q has space for only one char]
        }
    }
    if(q[0]=='='){
        printf("%d",p[0]);
    }
    else{
        int j=0;
    for(j;j<i;j++){
        if(q[j]=='*' || q[j]=='/'){
            p[j]=f(p[j],q[j],p[j+1]); // @@ [Accesses p[j+1] which may be out of bounds due to insufficient initial allocation and shifting logic]
            int k=j+1;
            for(k;k<i-1;k++){
                p[k]=p[k+1];
            }
            for(k=j;k<i-1;k++){
                q[k]=q[k+1]; 
            }
            j--;
            i--;
        }
    }
    for(j=0;j<i;j++){
        if(q[j]=='+' || q[j]=='-'){
            p[j]=f(p[j],q[j],p[j+1]); // @@ [Accesses p[j+1] which may be out of bounds due to insufficient initial allocation and prior shifting]
        int    k=j+1;
            for(k;k<i-1;k++){
                p[k]=p[k+1];
            }
            for(k=j;k<i-1;k++){
                q[k]=q[k+1];
            }
            j--;
            i--;
        }
    
    }
    printf("%d",p[0]);
}
    return 0;
}