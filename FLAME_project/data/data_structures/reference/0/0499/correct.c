#include <stdio.h>
#include <string.h>

void fil(char* p){
    char a=*(p-1)+1;
    while(a<*(p+1)){
        printf("%c",a);
        a++;
    }
}

int chrtyp(char a){
    if('0'<=a&&a<='9') return 1;
    if('a'<=a&&a<='z') return 2;
    if('A'<=a&&a<='Z') return 3;
}

int chrcheck(char a,char b){
    if(a<b){
        if(chrtyp(a)==chrtyp(b)) return 1;
        else return 0;
    }
    else return 0;
}

void work(char* str){
    char* p=str;
        while(strchr(p,'-')!=NULL){
                p=strchr(p,'-');
                if(chrcheck(*(p-1),*(p+1))){
                    *(p)='\0';
                    printf("%s",str);
                    str=p+1;
                    fil(p);
                }
                p++;}
    printf("%s",str);
    return;
}

int main(){
    char s[100000];
    scanf("%s",s);
    work(s);
    return 0;
}



