#include<stdio.h>
#include<string.h>
char s[105];
int n,m,p,pp;
int main(){
    scanf("%s",s+1);n=strlen(s+1);
    if(s[2]=='.'){
        for(int i=1;i<=n;i++){
            if(s[i]!='0'&&s[i]!='.'){p=i;break;}
            if(s[i]=='0') m++; 
        }
        printf("%c",s[p]);
        if(p<n) printf(".");
        for(int i=p+1;i<=n;i++){
            if(s[i]!='.') printf("%c",s[i]);
        }
        printf("e%d\n",-m);
    }
    else{
        for(int i=1;i<=n;i++){
            if(s[i]=='.'){p=i-1;break;}
        }
        if(!p) p=n;
        for(int i=n;i;i--){
            if(s[i]!='.'&&s[i]!='0'){pp=i;break;}
        }
        printf("%c",s[1]);
        if(pp>1) printf(".");
        for(int i=2;i<=pp;i++){
            if(s[i]!='.') printf("%c",s[i]);
        }
        printf("e%d\n",p-1);
    }
    return 0;
}
