#include<stdio.h>
int main(){
    char s[301];
    fgets(s,300,stdin);
    int i=0,ans=0,tem=0,tot,j=0;
    char op='+',po;
    while(s[i]!='='){
        if(s[i]!=' ')s[j++]=s[i];
        i++;
    }
    s[j]='=';
    i&=0;
    while(i<j&&s[i]>='0'&&s[i]<='9')tem=tem*10+s[i++]-'0';
    for(;i<j;i++){
        if(s[i]=='+'||s[i]=='-'){
            if(op=='+')ans+=tem;
            else ans-=tem;
            op=s[i++];
            tem&=0;
            while(i<j&&s[i]>='0'&&s[i]<='9')tem=tem*10+s[i++]-'0';
            i--;continue;
        }
        if(s[i]=='*'||s[i]=='/'){
            po=s[i++];
            tot&=0;
            while(i<j&&s[i]>='0'&&s[i]<='9')tot=tot*10+s[i++]-'0';
            if(po=='*')tem*=tot;
            else tem/=tot;
            i--;continue;
        }
    }
    if(op=='+')ans+=tem;
    else ans-=tem;
    printf("%d",ans);
    return 0;
}
