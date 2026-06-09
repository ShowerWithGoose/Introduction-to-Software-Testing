#include <stdio.h>
#include <malloc.h> // @@ Non-standard header; may cause compilation error
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
    int * p=(int *)malloc(sizeof(int)); // @@ Insufficient memory; only one int allocated, but multiple used
    char * q=(char *)malloc(sizeof(char)); // @@ Insufficient memory; only one char allocated, but multiple used
    int cur=0,i=0;
    char temp;
    while(scanf("%c",&temp)!=EOF){
        if(temp>='0' && temp<='9'){
            cur=cur*10+temp-'0';
        }
        else if(temp=='+' || temp=='-' || temp=='*' || temp=='/' || temp=='='){
            p[i]=cur;
            cur=0;
            q[i++]=temp;
        }
    }
    if(q[0]=='='){
        printf("%d",p[0]);
    }
    else{
        int j=0;
    for(j;j<i;j++){
        if(q[j]=='*' || q[j]=='/'){
            p[j]=f(p[j],q[j],p[j+1]);
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
            p[j]=f(p[j],q[j],p[j+1]);
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