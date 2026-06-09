#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    char s[10000]={0};
    gets(s);
    int n=strlen(s),ans,d[10000]={0},j=0,e[10000]={0},t; // @@ ans and t are uninitialized; using them leads to undefined behavior. e is unused but not an error.
    for(int i=0;i<n;i++){
        if(s[i]=='='){
            t++; // @@ Incrementing t here incorrectly adds 1, corrupting the count of operators. Should not increment.
            break;
        }
        if(s[i]>='0'&&s[i]<='9'){
            d[j]=d[j]*10+s[i]-'0';
        }
        else if(s[i]=='+'){
            t+=2;
            j++;
            d[j]=-1;
            j++;
        }
        else if(s[i]=='-'){
            t+=2;
            j++;
            d[j]=-2;
            j++;
        }
        else if(s[i]=='*'){
            t+=2;
            j++;
            d[j]=-3;
            j++;
        }
        else if(s[i]=='/'){
            t+=2;
            j++;
            d[j]=-4;
            j++;
        }
    }
    ans+=d[0]; // @@ ans is uninitialized; the value is undefined.
    j=0;
    for(int i=0;i<t;i++){ // @@ t is uninitialized (or incorrectly set), causing loop bounds to be undefined.
        if(d[i]==-3){
           d[j-1]=d[j-1]*d[i+1]; // @@ When j=0, j-1 is -1, causing out-of-bounds access.
           i++;
        }
        else if(d[i]==-4){
           d[j-1]=d[j-1]/d[i+1]; // @@ Same out-of-bounds issue as line 45.
           i++;
        }
        else d[j++]=d[i];
    }
    n=j;
    j=0;
    for(int i=1;i<n;i++){
        if(d[i]==-1){
           ans+=d[i+1]; // @@ When i=n-1, d[i+1] accesses index n, which is out of bounds.
           i++;
        }
        else if(d[i]==-2){
           ans-=d[i+1]; // @@ Same out-of-bounds issue as line 58.
           i++;
        }
    }
    printf("%d",ans);
    return 0;
}