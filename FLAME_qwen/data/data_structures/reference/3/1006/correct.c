#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#define LL long long
#define ULL unsigned long long

int main(void)
{
    char str[200],s[200];
    int m=0,n=0,i=0,lth,sum;
    gets(str);
    lth=strlen(str);

    while(str[i++]!='.'){
        m++;//小数点以前的位数
    }

    if(m!=1){
        m--;//整数部分的数量级
        printf("%c.",str[0]);
        for(i=1;i<=m;i++){
            printf("%c",str[i]);
        }//去掉小数点
        for(i=m+2;i<lth;i++){
            printf("%c",str[i]);
        }
        printf("e%d",m);
    }else{//整数部分数量级为0
        if(str[0]!='0'){//n.类型的
            for(i=0;i<strlen(str);i++){
                printf("%c",str[i]);
            }
            printf("e0");
        }else{//0.类型的
            i=2;
            while(str[i]=='0'){
               i++;
            }
            n=i-1;//第一位有效数字前0的个数
            printf("%c",str[i]);
            i++;//小数点位
            if(str[i]!='\0'){
                printf(".");
            }//后有数字则加小数点

            while(str[i]!='\0'){
                printf("%c",str[i]);
                i++;
            }//输出后面几位
            printf("e-%d",n);
        }
    }

    return 0;
}
