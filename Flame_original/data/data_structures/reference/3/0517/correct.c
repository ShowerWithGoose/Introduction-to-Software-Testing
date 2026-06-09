#include <stdio.h>
#include <string.h>
int main()
{
//定义变量：
    char ch0[106] = {0}, ch1[110] = {0};
    int p = 0, len = 0, i = 0, j = 0, del=0;
//输入：
    gets(ch0);
//找小数点，定长度：
    p = strchr(ch0, '.') - ch0;
    len = strlen(ch0);
//真小数：
    if('0' == ch0[0]){
        for(i = p + 1; i < len; i++){
            if(ch0[i] != '0'){
                break;
            }
            del++;
        }
        ch1[0] = ch0[p+1+del];
        for(i = 0; ch0[p+2+del+i] != '\0'; i++){
            ch1[2+i] = ch0[p+2+del+i];
        }
        if(i != 0){
            ch1[1] = '.';
        }
        for(i = 0; ch1[i] != '\0'; i++){
            printf("%c",ch1[i]);
        }
        printf("e%d",-del-1);
    }
//假小数：
    else{
        for(i = 0; i < p; i++){
            ch1[i] = ch0[i];
        }
        for(i = 0; ch0[p+1+i] != '\0'; i++){
            ch1[p+i] = ch0[p+1+i];
        }
        for(i = 0; ch1[i] != '\0'; i++){
            if(1 == i){
                printf(".");
            }
            printf("%c",ch1[i]);
        }
        printf("e%d",p-1);
    }
    return 0;
}

