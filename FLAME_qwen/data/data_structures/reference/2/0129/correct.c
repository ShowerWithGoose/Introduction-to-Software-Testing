#include <stdio.h>
#include<string.h>
#define MAX 1000000
char s[MAX];
int s1[MAX],st[MAX];
int tp,sn,s1n;
int main(){
    gets(s);sn=strlen(s);
    for(int i=0;i<sn;++i){
        if(s[i]>='0'&&s[i]<='9'){
            s1[s1n++]=s[i]-'0';
            while(s[i+1]>='0'&&s[i+1]<='9')
                s1[s1n-1]=s1[s1n-1]*10+s[++i]-'0';
        }else if(s[i]=='+'||s[i]=='-'){
            while(tp){
                s1[s1n++]=st[tp--];
            }
            st[++tp]=s[i];
        }else if(s[i]=='*'||s[i]=='/'){
            while(st[tp]=='*'||st[tp]=='/'){
                s1[s1n++]=st[tp--];
            }
            st[++tp]=s[i];
        }
    }
    while(tp) s1[s1n++]=st[tp--];
    //for(int i=0;i<=s1n;++i) cout<<s1[i]<<" ";puts("");
    for(int i=0;i<s1n;++i){
        if(s1[i]!='+'&&s1[i]!='-'&&s1[i]!='*'&&s1[i]!='/') st[++tp]=s1[i];
        else{
            int y=st[tp--],x=st[tp--];
            switch(s1[i]){
                case '+': st[++tp]=x+y;break;
                case '-': st[++tp]=x-y;break;
                case '*': st[++tp]=x*y;break;
                case '/': st[++tp]=x/y;break;
            }
        }
        //cout<<st[tp]<<" ";
    }
    printf("%d",st[tp]);
}
