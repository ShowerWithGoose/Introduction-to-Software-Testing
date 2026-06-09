#include<stdio.h>
#include<string.h>
int main(){
    int xiaoshudian,feilingshu,e;
    char s[101];
    gets(s);
    for(xiaoshudian=0;xiaoshudian<strlen(s);xiaoshudian++){
        if(s[xiaoshudian]=='.')break;
    }
    for(feilingshu=0;feilingshu<strlen(s);feilingshu++){
        if(s[feilingshu]!='0'&&s[feilingshu]!='.')break;
    }
    e=feilingshu<xiaoshudian?xiaoshudian-feilingshu-1:xiaoshudian-feilingshu;
    if(feilingshu<xiaoshudian){
        printf("%c.",s[0]);
        for(int m=1;m<strlen(s);m++){
            if(m!=xiaoshudian)
            printf("%c",s[m]);
        }
        printf("e%d",e);
    }
    else{
        if(feilingshu==strlen(s)-1){
            printf("%ce%d",s[feilingshu],e);
        }
        else{
            printf("%c.",s[feilingshu]);
            for(int m=feilingshu+1;m<strlen(s);m++){
                printf("%c",s[m]);
            }
            printf("e%d",e);
        }
    }
    getchar();
}
