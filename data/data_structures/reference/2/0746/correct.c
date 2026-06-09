#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>
#include<string.h>
void Delete(char a[]);

char s[1000], t[1000], sign[1000];
int a[1000];

int main()
{
    gets(s); //输入字符串
    Delete(s); //去除空格和等号
    //字符串数组记录符号，整形数组记录处理后的数字
    for (int i = 0, j = 0; s[i] != '\0'; i++, j++){
        int num = 0;
        for(; isdigit(s[i]); i++){
            num = num*10 +s[i] -'0';
        }
        a[j] = num;
        if (s[i] == '\0')
            break;
        sign[j] = s[i];
    }
    int sum=0, cnt=a[0], flag=1; //sum为总数，cnt为当前所处理数,flag为cnt的符号
    int len = strlen(sign);
    for (int i = 0; i < len; i++){
        //遇到加减，意味着当前cnt结束，sum+=cnt*flag,同时标记下一个cnt和flag.
        if (sign[i] == '+' || sign[i] == '-'){
            sum += cnt*flag;
            cnt = a[i+1];
            flag = (sign[i]=='+') ? 1:-1;
        }
        //遇到乘除将cnt进行计算
        else if(sign[i]=='*')
            cnt *= a[i+1];
        else
            cnt /= a[i+1];
    }
    sum += cnt*flag;//最后一个数字对应'\0'，进行特殊处理2
    printf("%d", sum);
    return 0;
}


void Delete(char s[])
{
    for (int i=0,j=0; s[i]!='\0'; i++){
        if(s[i]!=' ' && s[i]!='=')
            t[j++] = s[i];
    }
    int i;
    for (i = 0; t[i] != '\0'; i++)
        s[i] = t[i];
    s[i] = '\0';
}



