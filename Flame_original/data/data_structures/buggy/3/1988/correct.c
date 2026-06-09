#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
char str[10000];
int main() {
    scanf("%s", str);
    if(str[0] == '0'){
        int flag = 0, len = strlen(str), cnt1=0, cnt0=0, dot_flag = 0;
        for(int i=2; i<len; i++){
            if(str[i]!='0'){
                cnt1++;
            }else{
                if(flag == 0){
                    cnt0++;
                }
            }
            if(cnt1 == 1 && flag == 0){
                printf("%c", str[i]);
                flag = 1;
            }else if(flag == 1){
                if(dot_flag == 0){
                    printf(".%c", str[i]);
                    dot_flag = 1;
                }else{
                    printf("%c", str[i]);
                }
            }
        }
        printf("e-%d", cnt0+1);
    }else if(str[1] == '.'){
        printf("%se0", str);
    }else{
        int i=0, len = strlen(str);
        while(str[i]!='.'){
            i++;
        }
        printf("%c.", str[0]);
        for(int j=1; j<len; j++){
            if(str[j]!='.'){
                printf("%c", str[j]);
            }
        }
        printf("e%d", i-1);
    }
    return 0;
}

