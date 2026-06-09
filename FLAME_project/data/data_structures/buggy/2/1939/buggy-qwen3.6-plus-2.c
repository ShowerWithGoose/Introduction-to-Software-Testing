#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    char s[10000]={0};
    gets(s);
    int n=strlen(s),ans,d[10000]={0},j=0,e[10000]={0},t; // @@ [Variable 't' and 'ans' are used without initialization. 't' is incremented but starts with garbage value, leading to incorrect loop bounds. 'ans' accumulates values but starts with garbage.]
    for(int i=0;i<n;i++){
        if(s[i]=='='){
            t++; // @@ ['t' is incremented here, but since it was uninitialized, its value is undefined. It should be initialized to 0 before the loop or here set explicitly if counting tokens.]
            break;
        }
        if(s[i]>='0'&&s[i]<='9'){
            d[j]=d[j]*10+s[i]-'0';
        }
        else if(s[i]=='+'){
            t+=2; // @@ ['t' is being used as a counter for something (possibly tokens or array size), but it is uninitialized. Also, logic for tracking number of elements 'j' is separate.]
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
    ans+=d[0]; // @@ ['ans' is uninitialized, so adding d[0] to it results in undefined behavior. It should be initialized to 0 or set to d[0].]
    j=0;
    for(int i=0;i<t;i++){ // @@ ['t' is uninitialized/garbage, so this loop bound is incorrect. It should likely iterate up to 'j' (the number of elements stored in d).]
        if(d[i]==-3){
           d[j-1]=d[j-1]*d[i+1]; // @@ [Logic error: When processing operators, we should modify the existing sequence. Using 'j' here which is reset to 0 causes access to d[-1] initially. The standard approach is to process high precedence operators in place or use a stack. Here, it seems to try to compact the array, but 'j' management is flawed.]
           i++;
        }
        else if(d[i]==-4){
           d[j-1]=d[j-1]/d[i+1]; // @@ [Same logic error as above. Accessing d[j-1] when j=0 is out of bounds. Also, integer division order matters.]
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