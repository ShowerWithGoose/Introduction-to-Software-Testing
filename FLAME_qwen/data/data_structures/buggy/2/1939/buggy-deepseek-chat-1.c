#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    char s[10000]={0};
    gets(s);
    int n=strlen(s),ans,d[10000]={0},j=0,e[10000]={0},t;
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
    ans+=d[0]; // @@ [ans is uninitialized, leading to undefined behavior]
    j=0;
    for(int i=0;i<t;i++){
        if(d[i]==-3){
           d[j-1]=d[j-1]*d[i+1]; // @@ [j may be 0, causing out-of-bounds access]
           i++;
        }
        else if(d[i]==-4){
           d[j-1]=d[j-1]/d[i+1]; // @@ [j may be 0, causing out-of-bounds access]
           i++;
        }
        else d[j++]=d[i];
    }
    n=j;
    j=0;
    for(int i=1;i<n;i++){
        if(d[i]==-1){
           ans+=d[i+1]; // @@ [i+1 may exceed array bounds]
           i++;
        }
        else if(d[i]==-2){
           ans-=d[i+1]; // @@ [i+1 may exceed array bounds]
           i++;
        }
    }
    printf("%d",ans);
    return 0;
}