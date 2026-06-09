#include<stdio.h>
#include<string.h>
char str[100000000],key[100000000];
int main() {
    gets(str);
    int num1=0,num2=0,sum1=0;
    int length=strlen(str);
    int i=0,j=0;
    for(i=0; i<=length; i++) {
        if(str[i]!=' ') {
            key[i-j]=str[i];
        } else
            j+=1;//去除空格
    }
    for(i=0; key[i]<='9'&&key[i]>='0'; i++) {
        if(key[i]>='0'&&key[i]<='9') {
            num1=num1*10+(key[i]-'0');
        }//计算第一个数字
    }
    for(i=i; key[i]!='='; i++) {
        if(key[i]=='*') {
            for(i=i+1; key[i]<='9'&&key[i]>='0'; i++) {
                num2=num2*10+(key[i]-'0');
            }
            num1=num1*num2;
            num2=0;
            i=i-1;
        } else if(key[i]=='/') {
            for(i=i+1; key[i]<='9'&&key[i]>='0'; i++) {
                num2=num2*10+(key[i]-'0');
            }
            num1=num1/num2;
            num2=0;
            i=i-1;
        } else if(key[i]=='+'||key[i]=='-')
            break;
    }//计算第一个算式
    sum1=num1;
    for(i=i; key[i]=='+'||key[i]=='-'; i++) {
        num1=0;
        if(key[i]=='+') {
            for(i=i+1; key[i]<='9'&&key[i]>='0'; i++) {
                if(key[i]>='0'&&key[i]<='9') {
                    num1=num1*10+(key[i]-'0');
                }
            }//数
            for(i=i; key[i]!='='; i++) {
                if(key[i]=='*') {
                    for(i=i+1; key[i]<='9'&&key[i]>='0'; i++) {
                        num2=num2*10+(key[i]-'0');
                    }
                    num1=num1*num2;
                    num2=0;
                    i=i-1;
                } else if(key[i]=='/') {
                    for(i=i+1; key[i]<='9'&&key[i]>='0'; i++) {
                        num2=num2*10+(key[i]-'0');
                    }
                    num1=num1/num2;
                    num2=0;
                    i=i-1;
                } else if(key[i]=='+'||key[i]=='-')
                    break;
            }//式子
            sum1=sum1+num1;
        }
        if(key[i]=='-') {
            for(i=i+1; key[i]<='9'&&key[i]>='0'; i++) {
                if(key[i]>='0'&&key[i]<='9') {
                    num1=num1*10+(key[i]-'0');
                }
            }//数
            for(i=i; key[i]!='='; i++) {
                if(key[i]=='*') {
                    for(i=i+1; key[i]<='9'&&key[i]>='0'; i++) {
                        num2=num2*10+(key[i]-'0');
                    }
                    num1=num1*num2;
                    num2=0;
                    i=i-1;
                } else if(key[i]=='/') {
                    for(i=i+1; key[i]<='9'&&key[i]>='0'; i++) {
                        num2=num2*10+(key[i]-'0');
                    }
                    num1=num1/num2;
                    num2=0;
                    i=i-1;
                } else if(key[i]=='+'||key[i]=='-')
                    break;
            }
            //式子
            sum1=sum1-num1;
        }
        i=i-1;
    }
     printf("%d", sum1); // @@ [The logic fails to correctly handle operator precedence across the entire expression. It processes only immediate * and / after a + or -, but doesn't account for multiple consecutive * and / operations properly, and incorrectly assumes that after processing one term, the next operator is always at the current position. Also, the loop condition `key[i]=='+'||key[i]=='-'` may skip operators or go out of bounds. Additionally, the initial parsing of numbers does not correctly handle multi-digit numbers following operators in all cases, leading to wrong operand extraction.]
    return 0;
}