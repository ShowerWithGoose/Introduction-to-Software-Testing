#include <stdio.h>
#include<stdlib.h>
#include<string.h>

int p,pon;

void worknum(char*str){
    int i=0;
    while(str[p]!='.'){
        p++;
        i++;
    }
    str[p++]='\0';
    printf("%c.%s%se%d",str[pon],str+pon+1,str+p,i-1);
    return;
}

void workdec(char*str){
    int i=0;
    p+=2;
    while(str[p]=='0'){
        p++;
        i++;
    }
    if(str[p+1]!='\0') printf("%d.%se-%d",str[p]-'0',str+p+1,i+1);
    else printf("%de-%d",str[p]-'0',i+1);
    return;
}

int main(){
    char str[105];
    gets(str);
    if(str[p]=='-'){
        p++;
        printf("-");
        pon=1;
    }
    if(str[p]!='0') worknum(str);
    else workdec(str);
    return 0;
}

