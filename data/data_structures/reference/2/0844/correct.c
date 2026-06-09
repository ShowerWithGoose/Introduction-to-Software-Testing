#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
char s[50000];
int i;
int cal(){
    int num=1;
    char ch='*';
    while(1){
        if(isdigit(s[i])){
            int tmp=0;
            while(isdigit(s[i])){
                tmp=tmp*10+s[i++]-'0';
            }
            if(ch=='*')num*=tmp;
            else num/=tmp;
        }
        else if(s[i]=='*'||s[i]=='/'){
            ch=s[i++];
        }
        else break;;
    }
    return num;
}
int main(void){
    gets(s);
    int j=0;
    for(i=0;s[i];i++){
        if(s[i]!=' '){
            s[j++]=s[i];
        }
    }
    s[j-1]='\0';
    // printf("%s\n",s);
    int ans=0;
    char ch='+';
    for(i=0;s[i];){
        if(s[i]=='+'||s[i]=='-'){
            ch=s[i++];
        }
        else{
            ans=(ch=='+')?(ans+cal()):(ans-cal());
            ans=ans;
        }
    }
    printf("%d",ans);
    return 0;
}
