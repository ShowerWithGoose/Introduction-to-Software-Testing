#include<stdio.h>
#include<string.h>
#include<ctype.h>
char s[3000005];
int judge(int p){
    if(s[p]!='-')return 0;
    if((isdigit(s[p-1])&&isdigit(s[p+1]))||(islower(s[p-1])&&islower(s[p+1]))||(isupper(s[p-1])&&isupper(s[p+1]))){
        if(s[p+1]>s[p-1])return 1;
        else return 0;
    }
    else return 0;
}
int main(void){
    gets(s);
    printf("%c",s[0]);
    int i;
    for(i=1;s[i+1];i++){
        if(judge(i)){
            for(char j=s[i-1]+1;j<s[i+1];j++){
                printf("%c",j);
            }
        }
        else printf("%c",s[i]);
    }
    printf("%c",s[i]);
    return 0;
}


