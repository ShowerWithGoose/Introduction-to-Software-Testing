#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    char s[10000]={0};
    gets(s); // @@ [Using `gets` is unsafe and deprecated; may cause compilation error with modern compilers that remove `gets` from stdio.h]
    int n=strlen(s),ans,d[10000]={0},j=0,e[10000]={0},t; // @@ [`ans` and `t` are used uninitialized, leading to undefined behavior; also contributes to logical errors]
    for(int i=0;i<n;i++){
        if(s[i]=='='){
            t++; // @@ [`t` is used uninitialized; incrementing it leads to undefined behavior]
            break;
        }
        if(s[i]>='0'&&s[i]<='9'){
            d[j]=d[j]*10+s[i]-'0';
        }
        else if(s[i]=='+'){
            t+=2; // @@ [`t` is uninitialized; using it here causes undefined behavior]
            j++;
            d[j]=-1;
            j++;
        }
        else if(s[i]=='-'){
            t+=2; // @@ [`t` is uninitialized; using it here causes undefined behavior]
            j++;
            d[j]=-2;
            j++;
        }
        else if(s[i]=='*'){
            t+=2; // @@ [`t` is uninitialized; using it here causes undefined behavior]
            j++;
            d[j]=-3;
            j++;
        }
        else if(s[i]=='/'){
            t+=2; // @@ [`t` is uninitialized; using it here causes undefined behavior]
            j++;
            d[j]=-4;
            j++;
        }
        
    }
    ans+=d[0]; // @@ [`ans` is uninitialized; adding to it leads to undefined behavior]
    j=0;
    for(int i=0;i<t;i++){ // @@ [`t` may be uninitialized or have incorrect value due to prior misuse, causing loop bounds to be wrong]
        if(d[i]==-3){
           d[j-1]=d[j-1]*d[i+1]; // @@ [Accessing `d[j-1]` when `j` could be 0 leads to out-of-bounds access (negative index)]
           i++;
        }
        else if(d[i]==-4){
           d[j-1]=d[j-1]/d[i+1]; // @@ [Same as above: `j-1` may be negative, causing invalid memory access]
           i++;
        }
        else d[j++]=d[i];
    }
    n=j;
    j=0;
    for(int i=1;i<n;i++){ // @@ [Loop logic is flawed: it skips elements and doesn't correctly handle operator precedence after compression]
        if(d[i]==-1){
           ans+=d[i+1]; // @@ [May read beyond array bounds if `i+1 >= n`; also logic assumes alternating operands/operators but structure is broken]
           i++;
        }
        else if(d[i]==-2){
           ans-=d[i+1]; // @@ [Same as above: potential out-of-bounds access and incorrect evaluation order]
           i++;
        }
    }
    printf("%d",ans);
    return 0;
}