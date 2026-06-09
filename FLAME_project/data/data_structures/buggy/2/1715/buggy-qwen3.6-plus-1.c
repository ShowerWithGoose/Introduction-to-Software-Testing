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
                    num2=0; // @@ The variable num2 is not reset to 0 before parsing the next number in subsequent iterations of the outer loop, leading to incorrect accumulation if multiple * or / operations occur. However, the critical error here is that num2 retains its value from previous calculations if not explicitly cleared before the inner parsing loops start. In the first block (before the main loop), num2 is reset. Inside the loop, num2 is reset after use. But if the loop continues, num2 might hold garbage or old values if the logic flow skips the reset. More importantly, looking at the logic: `num2` is used to accumulate the second operand. It is reset to 0 after `num1=num1*num2`. This seems correct locally. Let's look closer.
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