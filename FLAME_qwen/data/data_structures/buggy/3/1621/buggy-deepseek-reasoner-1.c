#include<stdio.h>
#include<string.h>
int main()
{
    char c[105];
    int k=2;
    gets(c); // @@ 使用gets函数不安全，可能导致缓冲区溢出；且在C11标准中已被移除，可能引起编译错误。
    int len= strlen(c);
    if(c[0]=='0' && len!=3)
    {
        for( ; k<len; k++)
        {
            if(c[k]!='0')
            break;
        }
        printf("%c.", c[k]); // @@ 应判断c[k]后面是否有数字，若无数字则不应输出小数点。例如输入"0.01"，c[3]='1'后无数字，正确输出应为"1e-2"而非"1.e-2"。
        for(int m=k+1; m<=len; m++) // @@ 循环条件应为m<len，否则会输出字符串结束符'\0'，导致多余字符。
        {
            printf("%c", c[m]);
        }
        printf("e-%d", k-1);
    }
    else if(c[0]=='0' && len==3)
    {
        printf("%c", c[2]);
        printf("e-1");
    }
    else
    {
        int q=1;
        int te=1;
        for(; q<len; q++)
        {
            if(c[q]=='.')//814.3,q=3
            {
                te=0;
                break;
            }
            if(c[q]!='0')
            {
                te=0;
            }
        }
        if(te==1) // @@ 此分支逻辑有误，对于形如"10.2"的输入，因小数点后存在非零数字，te并未保持为1，但若输入无小数点且后续全为零（实际不存在），则输出格式错误。
        {
            printf("%ce%d", c[0], q-1);
        }else{
            printf("%c.", c[0]);
            for(int m=1; m<len; m++)
            {
                if(c[m]!='.')
                printf("%c", c[m]);
            }
            printf("e%d", q-1);
        }
    }
    return 0;
}