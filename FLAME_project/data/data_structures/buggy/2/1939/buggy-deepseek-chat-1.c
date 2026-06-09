#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    char s[10000]={0};
    gets(s);
    int n=strlen(s),ans,d[10000]={0},j=0,e[10000]={0},t; // @@ [t is uninitialized; it should be initialized to 0 before use]
    for(int i=0;i<n;i++){
        if(s[i]=='='){
            t++; // @@ [t is used but not initialized; also, this logic for detecting '=' is flawed because t is incremented but the loop breaks immediately, and t is used later as a count of operators, which is incorrect]
            break;
        }
        if(s[i]>='0'&&s[i]<='9'){
            d[j]=d[j]*10+s[i]-'0';
        }
        else if(s[i]=='+'){
            t+=2; // @@ [t is incremented by 2 for each operator, but this does not correctly count the number of operators or numbers; the logic for tracking positions is flawed]
            j++;
            d[j]=-1;
            j++;
        }
        else if(s[i]=='-'){
            t+=2; // @@ [same issue as above]
            j++;
            d[j]=-2;
            j++;
        }
        else if(s[i]=='*'){
            t+=2; // @@ [same issue as above]
            j++;
            d[j]=-3;
            j++;
        }
        else if(s[i]=='/'){
            t+=2; // @@ [same issue as above]
            j++;
            d[j]=-4;
            j++;
        }
        
    }
    ans+=d[0]; // @@ [ans is uninitialized; it should be initialized to 0 before use]
    j=0;
    for(int i=0;i<t;i++){ // @@ [t is not correctly set to the number of elements in d; it may be too large or too small, causing out-of-bounds access or missing elements]
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
           ans+=d[i+1]; // @@ [ans is used but not properly initialized; also, the logic for addition/subtraction does not handle the first number correctly]
           i++;
        }
        else if(d[i]==-2){
           ans-=d[i+1]; // @@ [same issue as above]
           i++;
        }
    }
    printf("%d",ans);
    return 0;
}