#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    char s[10000]={0};
    gets(s);
    int n=strlen(s),ans,d[10000]={0},j=0,e[10000]={0},t; // @@ Variables 'ans' and 't' are uninitialized. 'ans' will cause undefined behavior when used with '+='. 't' is used as a loop bound but never properly assigned the number of parsed elements.
    for(int i=0;i<n;i++){
        if(s[i]=='='){
            t++; // @@ 't' is uninitialized, incrementing it is undefined behavior. This line does not correctly track the number of elements.
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
    ans+=d[0]; // @@ 'ans' is uninitialized. Using '+=' adds to a garbage value. It should be assigned 'd[0]' directly.
    j=0;
    for(int i=0;i<t;i++){ // @@ 't' contains garbage/uninitialized value. The loop should iterate over the parsed elements, which are counted by 'j'. However, 'j' is modified inside the loop, so the original count should be saved before this loop.
        if(d[i]==-3){
           d[j-1]=d[j-1]*d[i+1];
           i++;
        }
        else if(d[i]==-4){
           d[j-1]=d[j-1]/d[i+1];
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