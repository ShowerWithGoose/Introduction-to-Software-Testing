#include<stdio.h>
#include<string.h>

int main(){
    char s[1000]= {0};
    int v;

    scanf("%s",s);
    for (int i = 0; i < strlen(s); ++i) {
        if(*(s+i) == '-'){

            if(*(s+i-1)>='0' && *(s+i-1) <= '9'){
                if(*(s+i+1)>='0' && *(s+i+1)<='9'){
                    for (v = 1; v < *(s+i+1)-*(s+i-1); ++v) {
                        printf("%c",*(s+i-1)+v);
                    }
                }else{
                    printf("-");
                }
            }else if(*(s+i-1)>='a' && *(s+i-1) <= 'z'){
                if(*(s+i+1)>='a' && *(s+i+1)<='z'){
                    for (v = 1; v < *(s+i+1)-*(s+i-1); ++v) {
                        printf("%c",*(s+i-1)+v);
                    }
                }else{
                    printf("-");
                }
            }else if(*(s+i-1)>='A' && *(s+i-1) <= 'Z'){
                if(*(s+i+1)>='A' && *(s+i+1)<='Z'){
                    for (v = 1; v < *(s+i+1)-*(s+i-1); ++v) {
                        printf("%c",*(s+i-1)+v);
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


