#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    char s[10000]={0};
    gets(s); // @@ [Using `gets` is unsafe and deprecated; however, the immediate error is uninitialized variable usage leading to undefined behavior]
    int n=strlen(s),ans,d[10000]={0},j=0,e[10000]={0},t; // @@ [`ans` and `t` are used without initialization, causing undefined behavior]
    for(int i=0;i<n;i++){
        if(s[i]=='='){
            t++; // @@ [`t` is used uninitialized; first use should be assignment, not increment]
            break;
        }
        if(s[i]>='0'&&s[i]<='9'){
            d[j]=d[j]*10+s[i]-'0';
        }
        else if(s[i]=='+'){
            t+=2; // @@ [`t` is still uninitialized here if '=' hasn't been encountered yet]
            j++;
            d[j]=-1;
            j++;
        }
        else if(s[i]=='-'){
            t+=2; // @@ [Same issue: `t` uninitialized]
            j++;
            d[j]=-2;
            j++;
        }
        else if(s[i]=='*'){
            t+=2; // @@ [Same issue: `t` uninitialized]
            j++;
            d[j]=-3;
            j++;
        }
        else if(s[i]=='/'){
            t+=2; // @@ [Same issue: `t` uninitialized]
            j++;
            d[j]=-4;
            j++;
        }
        
    }
    ans+=d[0]; // @@ [`ans` is uninitialized; should be `ans = d[0]`]
    j=0;
    for(int i=0;i<t;i++){ // @@ [`t` may be uninitialized or have incorrect value due to prior misuse]
        if(d[i]==-3){
           d[j-1]=d[j-1]*d[i+1]; // @@ [If `j` is 0, `j-1` is -1 → out-of-bounds write]
           i++;
        }
        else if(d[i]==-4){
           d[j-1]=d[j-1]/d[i+1]; // @@ [Same: potential negative index]
           i++;
        }
        else d[j++]=d[i];
    }
    n=j;
    j=0;
    for(int i=1;i<n;i++){
        if(d[i]==-1){
           ans+=d[i+1];
           i++;
        }
        else if(d[i]==-2){
           ans-=d[i+1];
           i++;
        }
    }
    printf("%d",ans);
    return 0;
}