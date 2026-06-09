#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    char s[10000]={0};
    gets(s); // @@ [Using `gets` is unsafe and deprecated; may cause compilation error with modern compilers that remove `gets` from stdio.h]
    int n=strlen(s),ans,d[10000]={0},j=0,e[10000]={0},t;
    for(int i=0;i<n;i++){
        if(s[i]=='='){
            t++; // @@ [`t` is used uninitialized; this leads to undefined behavior and potential incorrect logic]
            break;
        }
        if(s[i]>='0'&&s[i]<='9'){
            d[j]=d[j]*10+s[i]-'0';
        }
        else if(s[i]=='+'){
            t+=2; // @@ [`t` is used uninitialized; also, the logic of incrementing `t` by 2 per operator is flawed and doesn't correctly count tokens or operators]
            j++;
            d[j]=-1;
            j++;
        }
        else if(s[i]=='-'){
            t+=2; // @@ [Same issue: `t` uninitialized and logic for `t` is incorrect]
            j++;
            d[j]=-2;
            j++;
        }
        else if(s[i]=='*'){
            t+=2; // @@ [Same issue]
            j++;
            d[j]=-3;
            j++;
        }
        else if(s[i]=='/'){
            t+=2; // @@ [Same issue]
            j++;
            d[j]=-4;
            j++;
        }
        
    }
    ans+=d[0]; // @@ [`ans` is used uninitialized; should be initialized to `d[0]` instead of adding to garbage value]
    j=0;
    for(int i=0;i<t;i++){ // @@ [`t` may be uninitialized or incorrectly computed, leading to wrong loop bounds]
        if(d[i]==-3){
           d[j-1]=d[j-1]*d[i+1]; // @@ [Accessing `d[j-1]` when `j` could be 0 leads to out-of-bounds access (negative index)]
           i++;
        }
        else if(d[i]==-4){
           d[j-1]=d[j-1]/d[i+1]; // @@ [Same out-of-bounds risk]
           i++;
        }
        else d[j++]=d[i];
    }
    n=j;
    j=0;
    for(int i=1;i<n;i++){ // @@ [Loop starts at i=1 but uses d[i+1], which may go out of bounds; also logic skips first operand incorrectly]
        if(d[i]==-1){
           ans+=d[i+1]; // @@ [Accesses d[i+1] without ensuring i+1 < n; also misaligned due to prior tokenization errors]
           i++;
        }
        else if(d[i]==-2){
           ans-=d[i+1]; // @@ [Same issue]
           i++;
        }
    }
    printf("%d",ans);
    return 0;
}