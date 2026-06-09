#include <stdio.h>
#include <string.h>

int main(void){
    char s[80];
    gets(s);
    if(s[0]=='0'){
        int i=0,j=2;
        while(s[j]=='0'){
            i++;
            j++;
        }
        if(s[j+1]!='\0'){
            printf("%c.",s[j]);
            j++;
        }else{
            printf("%c",s[j]);
            j++;
        }
        for( ;j<strlen(s);j++){
            printf("%c",s[j]);
        }
        printf("e-%d",i+1);
    }else{
        if(strlen(s)>1){
            int i=0,j=1;
            printf("%c.",s[0]);
            while(s[j]!='.'&&s[j]!='\0'){
                printf("%c",s[j]);
                i++;
                j++;
            }
            j++;
            for( ;j<strlen(s);j++){
                printf("%c",s[j]);
            }
            printf("e%d",i);
        }else{
            printf("%ce0",s[0]);
        }
    }
}

