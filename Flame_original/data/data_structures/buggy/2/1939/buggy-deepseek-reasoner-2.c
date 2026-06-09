#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    char s[10000]={0};
    gets(s);
    int n=strlen(s),ans,d[10000]={0},j=0,e[10000]={0},t; // @@ [ans and t are not initialized, leading to undefined behavior]
    for(int i=0;i<n;i++){
        if(s[i]=='='){
            t++; // @@ [t is used uninitialized]
            break;
        }
        if(s[i]>='0'&&s[i]<='9'){
            d[j]=d[j]*10+s[i]-'0';
        }
        else if(s[i]=='+'){
            t+=2; // @@ [t is used uninitialized, and the logic for counting operators is flawed]
            j++;
            d[j]=-1;
            j++;
        }
        else if(s[i]=='-'){
            t+=2; // @@ [same as above]
            j++;
            d[j]=-2;
            j++;
        }
        else if(s[i]=='*'){
            t+=2; // @@ [same]
            j++;
            d[j]=-3;
            j++;
        }
        else if(s[i]=='/'){
            t+=2; // @@ [same]
            j++;
            d[j]=-4;
            j++;
        }
        
    }
    ans+=d[0]; // @@ [ans is uninitialized]
    j=0; // @@ [j is reset without proper context for the next loop; j will be used as index but initial value 0 causes out-of-bounds access later]
    for(int i=0;i<t;i++){
        if(d[i]==-3){
           d[j-1]=d[j-1]*d[i+1]; // @@ [j-1 is -1 when j is 0, out-of-bounds access]
           i++;
        }
        else if(d[i]==-4){
           d[j-1]=d[j-1]/d[i+1]; // @@ [same out-of-bounds issue]
           i++;
        }
        else d[j++]=d[i];
    }
    n=j;
    j=0;
    for(int i=1;i<n;i++){
        if(d[i]==-1){
           ans+=d[i+1]; // @@ [ans still uninitialized, potential out-of-bounds]
           i++;
        }
        else if(d[i]==-2){
           ans-=d[i+1]; // @@ [same issue]
           i++;
        }
    }
    printf("%d",ans);
    return 0;
}