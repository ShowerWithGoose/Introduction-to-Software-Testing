#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    char s[10000]={0};
    gets(s);
    int n=strlen(s),ans,d[10000]={0},j=0,e[10000]={0},t; // @@ t is uninitialized; ans is uninitialized, leading to undefined behavior
    for(int i=0;i<n;i++){
        if(s[i]=='='){
            t++; // @@ t is incremented but t is garbage; this line should be removed or t should be set properly
            break;
        }
        if(s[i]>='0'&&s[i]<='9'){
            d[j]=d[j]*10+s[i]-'0';
        }
        else if(s[i]=='+'){
            t+=2; // @@ t is used as a loop bound later, but this logic is flawed
            j++;
            d[j]=-1;
            j++;
        }
        else if(s[i]=='-'){
            t+=2; // @@ same issue
            j++;
            d[j]=-2;
            j++;
        }
        else if(s[i]=='*'){
            t+=2; // @@ same issue
            j++;
            d[j]=-3;
            j++;
        }
        else if(s[i]=='/'){
            t+=2; // @@ same issue
            j++;
            d[j]=-4;
            j++;
        }
        
    }
    ans+=d[0]; // @@ ans contains garbage, so this addition is invalid
    j=0;
    for(int i=0;i<t;i++){ // @@ t is uninitialized, loop bounds are unpredictable
        if(d[i]==-3){
           d[j-1]=d[j-1]*d[i+1]; // @@ when j=0, d[j-1] is out of bounds (negative index)
           i++;
        }
        else if(d[i]==-4){
           d[j-1]=d[j-1]/d[i+1]; // @@ same out-of-bounds issue
           i++;
        }
        else d[j++]=d[i];
    }
    n=j;
    j=0;
    for(int i=1;i<n;i++){ // @@ if n is 1 (only one number), this loop does nothing, skipping addition/subtraction
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