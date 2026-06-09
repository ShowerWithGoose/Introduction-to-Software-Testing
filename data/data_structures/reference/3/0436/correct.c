#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
char num[105];

int main()
{
    int i=0,n1=0,n2,flag=1,t=1000;
    char c;
    while(((c=getchar())!='\n')&&i<100){
        num[i++]=c;
        if(c=='.')
            n1=i-1;
    }
    n2=i-1;
    //读取字符，n1为小数点位置，n2为数字位数
    if(num[0]!='0'){
        printf("%c.",num[0]);
        for(i=1;i<=n2;i++){
            if(num[i]!='.')
                printf("%c", num[i]);
        }
        printf("e%d", n1-1);
    }
    else if(num[1]!='.')
        printf("0");
    else{
        for(i=2;i<=n2;i++){
            if((num[i]!='0')&&flag){
                printf("%c", num[i]);
                flag=0;
                t=i;
            }//flag表示未出现第一位
            else if(flag == 0){
                if(i==t+1)
                    printf(".");
                printf("%c", num[i]);
            }

        }
        printf("e-%d", t-1);

    }
	return 0;
}

