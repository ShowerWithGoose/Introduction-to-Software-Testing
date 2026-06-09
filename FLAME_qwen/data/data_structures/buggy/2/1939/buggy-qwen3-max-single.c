#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    char s[10000]={0};
    gets(s); // @@ [Using `gets` is unsafe and deprecated; more critically, `t` is used uninitialized below, leading to undefined behavior.]
    int n=strlen(s),ans,d[10000]={0},j=0,e[10000]={0},t; // @@ [`t` is declared but not initialized, yet it's used in `t++` and `t+=2` before being assigned a value. This causes undefined behavior.]
    for(int i=0;i<n;i++){
        if(s[i]=='='){
            t++; // @@ [`t` is used uninitialized here. This leads to unpredictable behavior.]
            break;
        }
        if(s[i]>='0'&&s[i]<='9'){
            d[j]=d[j]*10+s[i]-'0';
        }
        else if(s[i]=='+'){
            t+=2; // @@ [`t` is still uninitialized on first use; this accumulates garbage values.]
            j++;
            d[j]=-1;
            j++;
        }
        else if(s[i]=='-'){
            t+=2; // @@ [Same issue: `t` uninitialized.]
            j++;
            d[j]=-2;
            j++;
        }
        else if(s[i]=='*'){
            t+=2; // @@ [Same issue: `t` uninitialized.]
            j++;
            d[j]=-3;
            j++;
        }
        else if(s[i]=='/'){
            t+=2; // @@ [Same issue: `t` uninitialized.]
            j++;
            d[j]=-4;
            j++;
        }
        
    }
    ans+=d[0]; // @@ [`ans` is used uninitialized. It should be initialized to `d[0]` or 0 before adding.]
    j=0;
    for(int i=0;i<t;i++){ // @@ [`t` may contain garbage due to prior uninitialized use, causing loop bounds to be invalid.]
        if(d[i]==-3){
           d[j-1]=d[j-1]*d[i+1]; // @@ [If `j` is 0, `j-1` becomes -1, leading to out-of-bounds array access.]
           i++;
        }
        else if(d[i]==-4){
           d[j-1]=d[j-1]/d[i+1]; // @@ [Same as above: potential negative index if `j == 0`.]
           i++;
        }
        else d[j++]=d[i];
    }
    n=j;
    j=0;
    for(int i=1;i<n;i++){
        if(d[i]==-1){
           ans+=d[i+1]; // @@ [If `i+1 >= n`, this reads beyond the valid data in `d`. Also, `ans` was never properly initialized.]
           i++;
        }
        else if(d[i]==-2){
           ans-=d[i+1]; // @@ [Same risk of out-of-bounds read and use of uninitialized `ans`.]
           i++;
        }
    }
    printf("%d",ans);
    return 0;
}