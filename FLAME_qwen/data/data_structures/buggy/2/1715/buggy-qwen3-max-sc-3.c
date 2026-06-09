#include<stdio.h>
#include<string.h>
char str[100000000],key[100000000];
int main() {
    gets(str); // @@ [Using `gets` is unsafe and deprecated; may cause buffer overflow. However, the primary issue here is that the array sizes are extremely large (100 million elements each), which likely causes a stack overflow at runtime or compile-time memory allocation failure, leading to compilation or linking errors in some environments.]
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
     printf("%d", sum1);
    return 0;
}