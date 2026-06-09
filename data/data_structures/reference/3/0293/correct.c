#include<stdio.h>
int main(){
    char num[105]={};
    char out[110]={};
    int i = 0,j = 0,cnt = 0;//i,j为循环变量，cnt为幂指数
    //读入原始数据
    gets(num);
    //分出首位是否为0的情况
    if(num[0] > '0'){//首位非0
        while(num[i] != '.'){
            out[j] = num[i];
            i++,j++;
        }
        cnt = i - 1;
        i++;
        while(num[i] != '\0'){
            out[j] = num [i];
            i++,j++;
        }
        i = 0;
        //输出
        printf("%c.",out[0]);
        do{
            ++i;
            putchar(out[i]);
        }while(out[i+1] != '\0');
        printf("e%d",cnt);
    }
    else{
        i = 2;
        while(num[i] == '0') i++;
        cnt = i - 1;
        while(num[i] != '\0'){
            out[j] = num[i];
            i++,j++;
        }
        i = 0;

        printf("%c",out[0]);
        if(out[1] != '\0'){
            printf(".");
            do{
                ++i;
                putchar(out[i]);
            } while(out[i+1] != '\0');
        }
        printf("e-%d",cnt);
    }
    return 0;
}



