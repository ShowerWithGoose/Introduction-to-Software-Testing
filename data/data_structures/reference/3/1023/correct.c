// 3. 小数形式与科学计数法转换（简）
// 【问题描述】

// 编写一个程序，将用小数表示的浮点数，转换成科学计数法的形式输出。输入的数据没有符号，小数点前后必有数字，
//且全为有效数据，即小数点后的末尾数字不为0；小数点前若只有一位数字，可以为0，否则小数点前的最高位数字不为0。

// 提示：以字符串形式保存相关数据。

// 【输入形式】

// 从控制台输入一小数，最后有回车换行符，所有输入的字符数不会超过100。

// 【输出形式】

// 以科学计数法形式输出数据。输出的数据由以下几部分构成：
// 1.底数部分是一个小数或整数，若为小数，则小数点前后必有数字，而且都为有效数字。即：小数点前只有一位大于0
//的数字，小数点后的末尾数字不能为0。若为整数，则只有一位数字，不带小数点。
// 2.必有小写字母“e”。
// 3.指数部分是一个整数，若大于等于0，则不带正号“+”。若小于0，则需要带负号“-”，且整数的最高位数字不为0。

// 【输入样例1】

// 0.000000000000002

// 【输出样例1】

// 2e-15

// 【输入样例2】

// 8.9845623489651700659

// 【输出样例2】

// 8.9845623489651700659e0

// 【输入样例3】

// 367298599999093453490394859509568659795603.4

// 【输出样例3】

// 3.672985999990934534903948595095686597956034e41

// 【样例说明】

// 以小数形式输入数据，然后转换成科学计数法形式输出。

// 【评分标准】

// 该题要求以科学计数法形式输出数据，提交程序文件名为notation.c。
#include<stdio.h>
#include<string.h>
int Find_Zero(char *s,int len){
    int i;
    for(i=0;i<len;i++){
        if(*(s+i)!='0')return i;
    }
}
int Remove_Zero(char *s,int len){
    int i;
    for (i = 0;i<len;i++){
        if(*(s-i)!=0)return i;
    }
}
int main(){
    char str[200];
    gets(str);
    int All_Len,Zero_len,len1,Last_Zero,dot=0,exist_dot=0,exist_zero=0;
    int i;
    All_Len=strlen(str);
    if(str[All_Len-1]=='0')exist_zero=1;
    if(exist_zero==1){
        Last_Zero=Remove_Zero(&str[All_Len-1],All_Len);

    }
    for(i=0;i<All_Len;i++){
        if(str[i]=='.'){
            dot=i;
            exist_dot=1;
            break;
        }
    }
    len1=dot;
    if(len1==1){
        if(str[0]=='0'){
            Zero_len=Find_Zero(&str[2],All_Len-2);
            if(Zero_len==All_Len-3)printf("%c",str[2+Zero_len]);
            else printf("%c.",str[2+Zero_len]);
            for(i=0;i<All_Len-3-Zero_len-Last_Zero;i++){
                printf("%c",str[3+Zero_len+i]);
            }
            printf("e-%d",Zero_len+1);
        }
        else{
            printf("%se0",str);
        }
    }
    else{
        Zero_len=Find_Zero(&str[0],All_Len);
        printf("%c.",str[Zero_len]);
        for(i=0;i<All_Len-Zero_len-Last_Zero-1;i++){
            if(str[i+1]=='.')continue;
            printf("%c",str[i+1+Zero_len]);
        }
        if(exist_dot==1){
            printf("e%d",dot-1-Zero_len);
        }
        else{
            printf("e%d",All_Len-1-Zero_len);
        }
    }
    return 0;
}
