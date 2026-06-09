#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    char s[10000]={0};
    gets(s); // @@ [Using `gets` is unsafe and deprecated; may cause compilation error with modern compilers due to removal from standard library]
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
            t+=2; // @@ [`t` is used uninitialized; this leads to undefined behavior]
            j++;
            d[j]=-1;
            j++;
        }
        else if(s[i]=='-'){
            t+=2; // @@ [`t` is used uninitialized; this leads to undefined behavior]
            j++;
            d[j]=-2;
            j++;
        }
        else if(s[i]=='*'){
            t+=2; // @@ [`t` is used uninitialized; this leads to undefined behavior]
            j++;
            d[j]=-3;
            j++;
        }
        else if(s[i]=='/'){
            t+=2; // @@ [`t` is used uninitialized; this leads to undefined behavior]
            j++;
            d[j]=-4;
            j++;
        }
        
    }
    ans+=d[0]; // @@ [`ans` is used uninitialized; should be initialized to d[0] instead of adding to garbage value]
    j=0;
    for(int i=0;i<t;i++){ // @@ [`t` may be uninitialized or incorrectly computed, leading to wrong loop bounds]
        if(d[i]==-3){
           d[j-1]=d[j-1]*d[i+1]; // @@ [Accessing `d[j-1]` when `j` could be 0 leads to out-of-bounds access (negative index)]
           i++;
        }
        else if(d[i]==-4){
           d[j-1]=d[j-1]/d[i+1]; // @@ [Same issue: `j-1` may be negative, causing invalid memory access]
           i++;
        }
        else d[j++]=d[i];
    }
    n=j;
    j=0;
    for(int i=1;i<n;i++){
        if(d[i]==-1){
           ans+=d[i+1]; // @@ [May read beyond array bounds if `i+1 >= n`; also logic skips handling of first operand correctly]
           i++;
        }
        else if(d[i]==-2){
           ans-=d[i+1]; // @@ [Same issue: potential out-of-bounds access]
           i++;
        }
    }
    printf("%d",ans);
    return 0;
}