#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    char s[10000]={0};
    gets(s);
    int n=strlen(s),ans,d[10000]={0},j=0,e[10000]={0},t; // @@ Variables 'ans' and 't' are uninitialized. Using them before assignment leads to undefined behavior.
    for(int i=0;i<n;i++){
        if(s[i]=='='){
            t++;
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
    ans+=d[0]; // @@ 'ans' is uninitialized; should be 'ans = d[0];' to correctly initialize the result.
    j=0;
    for(int i=0;i<t;i++){
        if(d[i]==-3){
           d[j-1]=d[j-1]*d[i+1]; // @@ Accesses 'd[-1]' when 'j=0', causing an out-of-bounds error. The in-place evaluation logic for '*' and '/' is incorrect.
           i++;
        }
        else if(d[i]==-4){
           d[j-1]=d[j-1]/d[i+1]; // @@ Same out-of-bounds access and logical flaw as the multiplication case.
           i++;
        }
        else d[j++]=d[i]; // @@ The compaction logic fails to correctly maintain the sequence of operands and operators, leading to corrupted data for the next pass.
    }
    n=j;
    j=0;
    for(int i=1;i<n;i++){ // @@ 'n' is set to 'j', but due to previous logical errors, 'j' does not accurately reflect the number of valid tokens.
        if(d[i]==-1){
           ans+=d[i+1]; // @@ Relies on the incorrectly processed 'd' array, likely accessing invalid indices or wrong values.
           i++;
        }
        else if(d[i]==-2){
           ans-=d[i+1]; // @@ Same issue as above; incorrect array state leads to wrong calculations.
           i++;
        }
    }
    printf("%d",ans);
    return 0;
}