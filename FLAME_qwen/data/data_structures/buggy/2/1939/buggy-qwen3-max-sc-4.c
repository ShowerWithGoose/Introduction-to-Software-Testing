#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    char s[10000]={0};
    gets(s); // @@ [Using `gets` is unsafe and deprecated; may cause compilation error with modern compilers that remove `gets` entirely.]
    int n=strlen(s),ans,d[10000]={0},j=0,e[10000]={0},t; // @@ [`ans` and `t` are used uninitialized, leading to undefined behavior. Also, `t` is used to control loop bounds but starts uninitialized.]
    for(int i=0;i<n;i++){
        if(s[i]=='='){
            t++; // @@ [`t` is used uninitialized; incrementing it here causes undefined behavior.]
            break;
        }
        if(s[i]>='0'&&s[i]<='9'){
            d[j]=d[j]*10+s[i]-'0';
        }
        else if(s[i]=='+'){
            t+=2; // @@ [`t` is still uninitialized at first use; this leads to undefined behavior.]
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
    ans+=d[0]; // @@ [`ans` is uninitialized; adding to it causes undefined behavior. Should be `ans = d[0];`]
    j=0;
    for(int i=0;i<t;i++){ // @@ [`t` may be uninitialized or have incorrect value due to prior misuse, causing wrong loop bounds.]
        if(d[i]==-3){
           d[j-1]=d[j-1]*d[i+1]; // @@ [If `j` is 0, `j-1` is -1 → out-of-bounds access. Also, logic for handling operator precedence is flawed.]
           i++;
        }
        else if(d[i]==-4){
           d[j-1]=d[j-1]/d[i+1]; // @@ [Same out-of-bounds risk when `j == 0`.]
           i++;
        }
        else d[j++]=d[i];
    }
    n=j;
    j=0;
    for(int i=1;i<n;i++){ // @@ [Loop starts at i=1, but if the expression starts with a negative number or has other structures, this fails. Also, logic skips operands incorrectly.]
        if(d[i]==-1){
           ans+=d[i+1]; // @@ [Accesses `d[i+1]` without ensuring `i+1 < n`; possible buffer overread. Also, index management is inconsistent.]
           i++;
        }
        else if(d[i]==-2){
           ans-=d[i+1]; // @@ [Same potential out-of-bounds access.]
           i++;
        }
    }
    printf("%d",ans);
    return 0;
}