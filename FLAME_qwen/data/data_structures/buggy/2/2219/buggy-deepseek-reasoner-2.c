#include <stdio.h>
#include <string.h>
int num=0;
int main ()
{
    char ch[10005];
    char ch0[1005];
    gets(ch);
    for(int i,j=0;i<strlen(ch);i++) // @@ i未初始化，导致循环行为未定义；变量声明方式在C89中可能不支持
    {
        if(ch[i]!=' ')
        {
            ch0[j]=ch[i];
            j++;
        }
        if(ch0[i]>='0'&&ch0[i]<='9') // @@ 索引错误：应使用j而非i；ch0未初始化，导致访问未定义内存
            num++;
        
    }
    if(num==(strlen(ch0)-1)) // @@ ch0未以'\0'结尾，strlen行为未定义；逻辑与表达式求值无关
    {
        for(int k=0;k<strlen(ch0)-1;k++) // @@ 同上，ch0未终止；且未实现表达式计算
            printf("%c",ch0[k]);
    }
    
    return 0;
}