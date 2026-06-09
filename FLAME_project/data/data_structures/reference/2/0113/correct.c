#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main(){
    char s[1005]={},ch[1005]={};
    int r=0,i,num[1005]={};
    int j=0,k=0,t=0;
    fgets(s,1005,stdin);
    for(i=0;i<strlen(s);i++){
        if(isspace(s[i])){
            continue;
        }
        if(isdigit(s[i])){
            while(isdigit(s[i])){
                t=t*10+s[i]-'0';
                i++;
            }
            i--;
            num[j++]=t;
            t=0;
        }
        else{
            ch[k++]=s[i];
        }
    }
    for(i=0;i<strlen(ch);i++){
        if(ch[i]=='-'){
            num[i+1]*=(-1);
        }
    }
    for(i=0;i<strlen(ch);i++){
         if(ch[i]=='*'||ch[i]=='/'){
            int k=i;
            int j=i,o=1,p=1;
            while(ch[i]=='*'||ch[i]=='/'){
                i++;
            }
            for(;j<i;j++){
                if(ch[j]=='*'){
                    o*=num[j+1];
                }
                else{
                    p*=num[j+1];
                }
            }
            r+=num[k]*o/p;
        }
        else{
            r+=num[i];
        }
    }
    printf("%d",r);
    return 0;
}
