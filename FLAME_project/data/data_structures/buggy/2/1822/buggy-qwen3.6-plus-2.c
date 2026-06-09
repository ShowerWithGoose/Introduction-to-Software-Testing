#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
char str[1000005];
char o[1000005];
int main() {
    int i,k=0,count,t,p,l;
    long long sum=0,sum1,sum2;
    gets(str); // @@ The function 'gets' is deprecated and removed in C11/C17 standards, causing compilation warnings or errors. It should be replaced with 'fgets'. Additionally, the linker error indicates missing 'pow' references, which suggests the math library might not be linked correctly during compilation (usually requires -lm flag), but strictly speaking, the code uses 'pow' which is declared in <math.h>. The primary compilation failure described in the prompt ("undefined reference to `pow'") is a linker error, not a source code syntax error, but often in these contexts, using integer arithmetic instead of floating point pow is preferred to avoid linking issues and precision errors. However, since I must only annotate existing lines: The use of pow() for integer conversion is inefficient and prone to floating point precision errors, and requires linking the math library.
    int len=strlen(str);
    count=0;
    for(i=0; i<len; i++) {
        if(str[i]!=' ') {
            o[k]=str[i];
            k++;
        }
    }//首先把所有的空格全部去掉
    k=0;
    while(1) {
        if('0'<=o[k]&&o[k]<='9') {
            count++;//记录数有几位
            k++;//k代表位置
        } else {
            break;//如果遇到加号减号退出循环
        }
    }
    for(i=0; i<k; i++) {
        sum+=((o[i]-'0')*pow(10,k-1-i));//sum进行加法运算算第一个数字的值 // @@ Using pow() for integer powers is problematic. It returns a double, which can lead to precision errors (e.g., pow(10, 2) might be 99.999999, truncating to 99). It also causes the linker error if -lm is not provided. Integer accumulation should be used instead.
    }
    for(i=k; i<len; i++) {
        if(o[i]=='-') {//如果运算符号是减法的情况
            count=0;
            sum1=0;
            t=i+1;
            while(1) {
                if('0'<=o[t]&&o[t]<='9') {
                    count++;//记录数有几位
                    t++;//t代表位置
                } else {
                    break;//如果遇到乘号除号退出循环
                }
            }
            for(p=0; p<count; p++) {
                sum1+=(o[p+i+1]-'0')*pow(10,count-1-p); // @@ Same issue: using pow() for integer conversion causes precision errors and linker dependencies.
            }
            while(1) {
                if(o[t]=='*') {
                    count=0;
                    l=t+1;
                    sum2=0;
                    while(o[l]!='*'&&o[l]!='/'&&o[l]!='+'&&o[l]!='-') {
                        if(o[l]=='=') {
                            break;
                        }
                        count++;
                        l++;
                    }
                    for(p=0; p<count; p++) {
                        sum2+=(o[p+t+1]-'0')*pow(10,count-1-p); // @@ Same issue: using pow() for integer conversion causes precision errors and linker dependencies.
                    }
                    sum1=sum1*sum2;
                    t=l;
                    continue;
                } else if(o[t]=='/') {
                    count=0;
                    l=t+1;
                    sum2=0;
                    while(o[l]!='*'&&o[l]!='/'&&o[l]!='+'&&o[l]!='-') {
                        if(o[l]=='=') {
                            break;
                        }
                        count++;
                        l++;
                    }
                    for(p=0; p<count; p++) {
                        sum2+=(o[p+t+1]-'0')*pow(10,count-1-p); // @@ Same issue: using pow() for integer conversion causes precision errors and linker dependencies.
                    }
                    sum1=sum1/sum2;
                    t=l;
                    continue;
                } else if(o[t]=='+'||o[t]=='-'||o[t]=='=') {
                    break;
                }
            }
            sum-=sum1;
            i=t-1;
        } else if(o[i]=='+') { //如果运算符号是加法的情况
            count=0;
            sum1=0;
            t=i+1;
            while(1) {
                if('0'<=o[t]&&o[t]<='9') {
                    count++;//记录数有几位
                    t++;//t代表位置
                } else {
                    break;//如果遇到乘号除号退出循环
                }
            }
            for(p=0; p<count; p++) {
                sum1+=(o[p+i+1]-'0')*pow(10,count-1-p); // @@ Same issue: using pow() for integer conversion causes precision errors and linker dependencies.
            }
            while(1) {
                if(o[t]=='*') {
                    count=0;
                    l=t+1;
                    sum2=0;
                    while(o[l]!='*'&&o[l]!='/'&&o[l]!='+'&&o[l]!='-') {
                        if(o[l]=='=') {
                            break;
                        }
                        count++;
                        l++;
                    }
                    for(p=0; p<count; p++) {
                        sum2+=(o[p+t+1]-'0')*pow(10,count-1-p); // @@ Same issue: using pow() for integer conversion causes precision errors and linker dependencies.
                    }
                    sum1=sum1*sum2;
                    t=l;
                    continue;
                } else if(o[t]=='/') {
                    count=0;
                    l=t+1;
                    sum2=0;
                    while(o[l]!='*'&&o[l]!='/'&&o[l]!='+'&&o[l]!='-') {
                        if(o[l]=='=') {
                            break;
                        }
                        count++;
                        l++;
                    }
                    for(p=0; p<count; p++) {
                        sum2+=(o[p+t+1]-'0')*pow(10,count-1-p); // @@ Same issue: using pow() for integer conversion causes precision errors and linker dependencies.
                    }
                    sum1=sum1/sum2;
                    t=l;
                    continue;
                } else if(o[t]=='+'||o[t]=='-'||o[t]=='=') {
                    break;
                }
            }
            sum+=sum1;
            i=t-1;
        } else if(o[i]=='=') {
            break;
        }
    }
    printf("%lld",sum);
    return 0;
}