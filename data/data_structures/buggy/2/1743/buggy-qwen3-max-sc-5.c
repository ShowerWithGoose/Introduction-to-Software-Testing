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
    int * p=(int *)malloc(sizeof(int)); // @@ [Insufficient memory allocation: only space for one integer is allocated, but the program may store multiple numbers from the expression. This leads to buffer overflow when accessing p[i] for i >= 1.]
    char * q=(char *)malloc(sizeof(char)); // @@ [Insufficient memory allocation: only space for one character is allocated, but the program stores multiple operators and '='. This leads to buffer overflow when accessing q[i] for i >= 1.]
    int cur=0,i=0;
    char temp;
    while(scanf("%c",&temp)!=EOF){ // @@ [scanf with %c reads every character including newlines; the loop does not stop at '=', it continues until EOF. The problem states input ends with '=', so the loop should break upon reading '='. Continuing past '=' may read unintended characters or hang waiting for EOF.]
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
            p[j]=f(p[j],q[j],p[j+1]); // @@ [Accessing p[j+1] may be out of bounds if insufficient memory was allocated (which it was). Also, after shrinking arrays by shifting, the logic assumes valid indices, but initial allocation size is wrong.]
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
            p[j]=f(p[j],q[j],p[j+1]); // @@ [Same issue: potential out-of-bounds access due to insufficient initial allocation and unsafe array shrinking.]
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