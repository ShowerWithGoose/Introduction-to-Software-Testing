//
//  main.c
//  科学计数法
//
//  Created by  on 2022/3/3.
//

#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[]) {
    char str[110];
    gets(str);
    int dotsit=0,flag=0;
    int len=strlen(str);
    //判断小数点位置
    for(int i=0;i<len;i++)
        if(str[i]=='.'){
            dotsit=i;
            flag++;
            break;
        }
    //0.0000的情况
    int record=2,flag0=0,weishu=0;
    if(str[0]=='0'&&str[1]=='.'){
        flag0++;
        for(int i=2;str[i]=='0';i++)
            record++;
        weishu=len-record;
    }
    
    
    //判断e后的数字
    int eno;
    if(flag0!=0){
        eno=-record+dotsit;
    }
    else if(flag==0)
        eno=len-1;
    else if(dotsit==1)
        eno=0;
    else
        eno=dotsit-1;
    
    //输出
    //首位不含0的情况
    if(flag0==0){
        if(len==1)
            printf("%c",str[0]);
        else
            printf("%c.",str[0]);
        if(dotsit==1)
            for(int i=2;i<dotsit;i++)
                printf("%c",str[i]);
        else
            for(int i=1;i<dotsit;i++)
                printf("%c",str[i]);
        for(int i=dotsit+1;i<len;i++)
            printf("%c",str[i]);
        printf("e%d",eno);
    }
    //首位含0但位数为1的情况
    else if(flag0!=0&&weishu==1){
        printf("%ce%d",str[record],eno);
    }
    //首位含0且数字个数不为1的情况
    else{
        printf("%c.",str[record]);
        for(int i=1;str[record+i]!='\0';i++)
            printf("%c",str[record+i]);
        printf("e%d",eno);
    }
    
    return 0;
}

