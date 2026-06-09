#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
char str[1000005];
char o[1000005];
int main() {
    int i,k=0,count,t,p,l;
    long long sum=0,sum1,sum2;
    gets(str); // @@ [Using `gets` is unsafe and deprecated; it may cause buffer overflow. More critically, in many modern environments (like those with strict compilation flags), `gets` is not available, leading to a compilation error.]
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
                        sum2+=(o[p+t+1]-'0')*pow(10,count-1-p); // @@ [Incorrect indexing: should be `o[t+1+p]` or `o[l_start + p]`, but here `p+t+1` reuses `t` which hasn't been updated to the start of the new number. This leads to reading wrong digits. However, this is a logic error, not compilation. The actual compilation error stems from `gets`.]
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
                        sum2+=(o[p+t+1]-'0')*pow(10,count-1-p); // @@ [Same indexing error as above. But again, not causing compilation failure.]
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
                        sum2+=(o[p+t+1]-'0')*pow(10,count-1-p); // @@ [Same indexing issue.]
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
                        sum2+=(o[p+t+1]-'0')*pow(10,count-1-p); // @@ [Same indexing issue.]
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