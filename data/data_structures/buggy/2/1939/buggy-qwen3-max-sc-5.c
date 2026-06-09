#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    char s[10000]={0};
    gets(s); // @@ [Using `gets` is unsafe and deprecated; more critically, `t` is used uninitialized below, leading to undefined behavior.]
    int n=strlen(s),ans,d[10000]={0},j=0,e[10000]={0},t; // @@ [`t` is declared but not initialized, yet it's used in `t++` and `t+=2` before being assigned a value. This causes undefined behavior.]
    for(int i=0;i<n;i++){
        if(s[i]=='='){
            t++; // @@ [`t` is used uninitialized here. It should be initialized to 0 at declaration.]
            break;
        }
        if(s[i]>='0'&&s[i]<='9'){
            d[j]=d[j]*10+s[i]-'0';
        }
        else if(s[i]=='+'){
            t+=2; // @@ [`t` is still uninitialized the first time this runs, causing undefined behavior.]
            j++;
            d[j]=-1;
            j++;
        }
        else if(s[i]=='-'){
            t+=2; // @@ [Same issue: `t` is uninitialized.]
            j++;
            d[j]=-2;
            j++;
        }
        else if(s[i]=='*'){
            t+=2; // @@ [Same issue: `t` is uninitialized.]
            j++;
            d[j]=-3;
            j++;
        }
        else if(s[i]=='/'){
            t+=2; // @@ [Same issue: `t` is uninitialized.]
            j++;
            d[j]=-4;
            j++;
        }
        
    }
    ans+=d[0]; // @@ [`ans` is used uninitialized. It should be initialized to 0 or d[0] directly.]
    j=0;
    for(int i=0;i<t;i++){ // @@ [`t` may be uninitialized or have an incorrect value due to prior misuse, leading to wrong loop bounds.]
        if(d[i]==-3){
           d[j-1]=d[j-1]*d[i+1]; // @@ [If `j` is 0, `j-1` becomes -1, causing out-of-bounds array access. Also, logic assumes operators and operands are correctly separated, but storage scheme mixes them incorrectly.]
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
    for(int i=1;i<n;i++){ // @@ [Loop starts at i=1, but if the first element is an operand, it may skip necessary processing. Also, logic for handling + and - assumes correct pairing, which may not hold due to earlier flawed parsing.]
        if(d[i]==-1){
           ans+=d[i+1]; // @@ [May read beyond array if `i+1 >= n`. Also, `ans` was never properly initialized.]
           i++;
        }
        else if(d[i]==-2){
           ans-=d[i+1]; // @@ [Same potential out-of-bounds access and uninitialized `ans` issue.]
           i++;
        }
    }
    printf("%d",ans);
    return 0;
}