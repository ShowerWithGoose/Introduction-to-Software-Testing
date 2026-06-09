#include<stdio.h>
#include<string.h>

int main(){
    char s[1000]= {0};
    int j;

    scanf("%s",s);
    for (int i = 0; i < strlen(s); ++i) {
        if(*(s+i) == '-'){

            if(*(s+i-1)>='0' && *(s+i-1) <= '9'){
                if(*(s+i+1)>='0' && *(s+i+1)<='9'){
                    for (j = 1; j < *(s+i+1)-*(s+i-1); ++j) {
                        printf("%c",*(s+i-1)+j);
                    }
                }else{
                    printf("-");
                }
            }else if(*(s+i-1)>='a' && *(s+i-1) <= 'z'){
                if(*(s+i+1)>='a' && *(s+i+1)<='z'){
                    for (j = 1; j < *(s+i+1)-*(s+i-1); ++j) {
                        printf("%c",*(s+i-1)+j);
                    }
                }else{
                    printf("-");
                }
            }else if(*(s+i-1)>='A' && *(s+i-1) <= 'Z'){
                if(*(s+i+1)>='A' && *(s+i+1)<='Z'){
                    for (j = 1; j < *(s+i+1)-*(s+i-1); ++j) {
                        printf("%c",*(s+i-1)+j);
                    }
                }else{
                    printf("-");
                }
            }
        }else{
            printf("%c",*(s+i));
        }
    }
    return 0;
}


