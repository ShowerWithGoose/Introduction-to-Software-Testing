#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
char s[50000];
int main(void){
    gets(s);
    int len=strlen(s);
    int head=0,tail=len-1;
    int p=0;
    while(!(s[head]>'0'&&s[head]<='9'))head++;
    while(!(s[tail]>'0'&&s[tail]<='9'))tail--;
    while(s[p]!='.')p++;

    if(head==tail){
        printf("%c",s[head]);
    }
    else{
        for(int i=head;i<=tail;i++){
            if(s[i]!='.')printf("%c",s[i]);
            if(i==head)printf(".");
        }
        // s[tail+1]='\0';
        // printf("%c.%s",s[head],s+head+1);
    }

    printf("e");

    printf("%d",(p<head)?(p-head):(p-head-1));
    return 0;
}
