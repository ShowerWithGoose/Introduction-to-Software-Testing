#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
 char s[105];
 char c='.';
 int len,n=-1,dian;
 gets(s);
 len=strlen(s);
 dian=len;
 if(len==1){
    printf("%ce0",s[0]);
    return 0;
 }
 for(int i=0;i<=len-1;i++){
    if(s[i]!='0'&&s[i]!='.'&&n==-1){
            n=i;
        }
    if(s[i]=='.')
        dian=i;
 }
 if(s[0]=='0'){
        if(n+1>=len-1)
            printf("%c",s[n]);
        else
            printf("%c.",s[n]);
    for(int i=n+1;i<=len-1;i++){
        printf("%c",s[i]);
    }
    printf("e-%d",n-1);
 }
if(s[0]!='0'){
    printf("%c.",s[0]);
    for(int i=1;i<=len-1;i++){
        if(s[i]=='.')
            continue;
        printf("%c",s[i]);
    }
    printf("e%d",dian-n-1);
}
 return 0;
}

