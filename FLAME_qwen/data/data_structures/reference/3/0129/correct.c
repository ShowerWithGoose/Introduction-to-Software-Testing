#include<stdio.h>
#include<string.h>
char s[105];
int e;

int main(){
    scanf("%s",s);int sn=strlen(s);
    if(s[0]!='0'){
        while(s[sn-1]=='0')--sn;
        printf("%c",s[0]);
        if(sn>1)printf(".");
        for(int i=1;i<sn;++i){
            if(s[i]=='.')e=i;
            else printf("%c",s[i]);
        }
        if(e==0) e=sn;
        printf("e%d",e-1);
    }else{
        while(s[e]<'1'||s[e]>'9')++e;
        printf("%c",s[e]);
        if(s[e+1]!='\0')printf(".");
        for(int i=e+1;i<sn;++i) printf("%c",s[i]);
        printf("e-%d",e-1);
    }
    return 0;
}
