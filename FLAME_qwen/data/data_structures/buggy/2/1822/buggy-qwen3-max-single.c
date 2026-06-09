#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
char str[1000005];
char o[1000005];
int main() {
    int i,k=0,count,t,p,l;
    long long sum=0,sum1,sum2;
    gets(str); // @@ [Using `gets` is unsafe and deprecated; it was removed in C11. This may cause compilation errors with modern compilers that don't support it. Use `fgets` instead.]
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
        sum+=((o[i]-'0')*pow(10,k-1-i));//sum进行加法运算算第一个数字的值
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
                sum1+=(o[p+i+1]-'0')*pow(10,count-1-p);
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
                        sum2+=(o[p+t+1]-'0')*pow(10,count-1-p); // @@ [Incorrect indexing: should be `o[t+1+p]`, not `o[p+t+1]` — but more critically, this loop uses `pow` from <math.h> which returns double, causing precision issues with large integers and potential incorrect results due to floating-point inaccuracies. Also, integer parsing logic is flawed when handling multi-digit numbers after operators.]
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
                        sum2+=(o[p+t+1]-'0')*pow(10,count-1-p); // @@ [Same issue: using `pow` (double-returning) for integer arithmetic leads to incorrect results due to floating point rounding. Should use integer-based power or digit-by-digit accumulation.]
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
                sum1+=(o[p+i+1]-'0')*pow(10,count-1-p); // @@ [Again, using `pow` from <math.h> introduces floating-point inaccuracies. For example, pow(10,2) might return 99.999... which becomes 99 when cast to int, breaking number parsing.]
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
                        sum2+=(o[p+t+1]-'0')*pow(10,count-1-p); // @@ [Same floating-point precision error with `pow`.]
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
                        sum2+=(o[p+t+1]-'0')*pow(10,count-1-p); // @@ [Same issue.]
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