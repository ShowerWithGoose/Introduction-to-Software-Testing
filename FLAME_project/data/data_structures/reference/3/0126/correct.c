#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define MAXLEN 100

int main(){
    char s[MAXLEN];
    gets(s);
    int flag = 0 , len = (int)strlen(s) , wei=0 ;
    if(s[0] == '-'){//判断是否为负数，得到|s|
        printf("-");
        for(int i = 0 ; i < len ; i++)  s[i] = s[i+1];
        len--;
    }
    
    if(s[1] == '\0'){//如果是0
        printf("0e0");
        return 0;
    }
    if(s[0] == '0' && s[1] == '.'){//如果小数
        //flag标志是否遇到第一个非0的数字
        for(int i = 2 ; i < len ; i++){//从第二个开始遍历
            //判断位数
            if(flag == 0 && s[i] == '0'){                                                                          wei++;                               continue;}
            //有小数点（有至少两个数字
            else if(flag == 0 && s[i] >='0'&& s[i] <= '9' && s[i+1] >= '0' && s[i+1] <= '9'){                printf("%c.",s[i]);       flag = 1;}
            //无小数点（仅有一个数字
            else if(flag == 0 && s[i] >='0'&& s[i] <= '9' && s[i+1] == '\0' )   printf("%c",s[i]);
            else if(flag == 1 && s[i] != '\0')                                                               printf("%c",s[i]);
        }
        printf("e-%d",wei+1);
    }
    
    else if(s[0] != '0'){//如果整数
        if(flag == 0 && s[1] == '.')                                                flag=1;//第二位就是小数点
        else if(flag == 0 && s[1] >= '0' && s[1] <= '9')        flag=2;//整数位>1
        else if(flag == 0 ){//个位数字
            printf("%ce0",s[0]);
            return 0;
        }
        if(flag == 1){
            printf("%se0",s);
            return 0;
        }
        else if(flag == 2){
            printf("%c.",s[0]);
            int i=1;
            while(s[i] != '.' && s[i] !='\0'){
                printf("%c",s[i]);
                wei++;i++;
            }
            if(s[i] == '.')     while(i++ < len && s[i] != '\0')    printf("%c",s[i]);
            printf("e%d",wei);
        }
    }
    return 0;
}

