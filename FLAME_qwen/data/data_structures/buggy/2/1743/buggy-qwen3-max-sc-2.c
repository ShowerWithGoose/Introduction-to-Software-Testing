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
    while(scanf("%c",&temp)!=EOF){
        if(temp>='0' && temp<='9'){
            cur=cur*10+temp-'0';
        }
        else if(temp=='+' || temp=='-' || temp=='*' || temp=='/' || temp=='='){
            p[i]=cur; // @@ [Writing beyond allocated memory: p was allocated only sizeof(int), so p[0] is valid, but p[1], p[2], etc., are out of bounds.]
            cur=0;
            q[i++]=temp; // @@ [Writing beyond allocated memory: q was allocated only sizeof(char), so q[0] is valid, but q[1], q[2], etc., are out of bounds.]
        }
    }
    if(q[0]=='='){ // @@ [Potential undefined behavior: if input is just "=", then i=1 and q[0]='=', but if input is empty or malformed (though problem says valid), this could access uninitialized memory. However, main issue is prior buffer overflows.]
        printf("%d",p[0]);
    }
    else{
        int j=0;
    for(j;j<i;j++){
        if(q[j]=='*' || q[j]=='/'){
            p[j]=f(p[j],q[j],p[j+1]); // @@ [Accessing p[j+1] which may be out of allocated bounds due to insufficient initial allocation.]
            int k=j+1;
            for(k;k<i-1;k++){
                p[k]=p[k+1]; // @@ [Shifting elements in an undersized array causes further out-of-bounds reads/writes.]
            }
            for(k=j;k<i-1;k++){
                q[k]=q[k+1]; // @@ [Same issue with operator array q.]
            }
            j--;
            i--;
        }
    }
    for(j=0;j<i;j++){
        if(q[j]=='+' || q[j]=='-'){
            p[j]=f(p[j],q[j],p[j+1]); // @@ [Again, p[j+1] likely out of bounds.]
        int    k=j+1;
            for(k;k<i-1;k++){
                p[k]=p[k+1]; // @@ [Out-of-bounds access due to undersized p.]
            }
            for(k=j;k<i-1;k++){
                q[k]=q[k+1]; // @@ [Out-of-bounds access due to undersized q.]
            }
            j--;
            i--;
        }
    
    }
    printf("%d",p[0]);
}
    return 0;
}