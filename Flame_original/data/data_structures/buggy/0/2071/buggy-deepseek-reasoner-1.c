#include <stdio.h>
#include <string.h>

#define isnum(a) ((a>='0')&&(a<='9'))
#define isa_z(a) ((a>='a')&&(a<='z'))
#define isA_Z(a) ((a>='A')&&(a<='Z'))

char Cen[25000]={0};

int main()
{
    gets(Cen); // @@ 使用gets不安全，可能导致缓冲区溢出；更关键的是后续访问Cen[i-1]和Cen[i+1]时未检查边界。
    int i;
    int n=strlen(Cen);
    for(i=0;i<strlen(Cen);i++) // @@ 每次循环调用strlen效率低，但非错误；边界检查应在内部处理。
    {
        if(Cen[i]=='-') // @@ 缺少边界检查，当i==0或i==n-1时，Cen[i-1]或Cen[i+1]访问越界。
        {
            if(((isnum(Cen[i-1]))&&(isnum(Cen[i+1]))) || ((isa_z(Cen[i-1]))&&(isa_z(Cen[i+1]))) || ((isA_Z(Cen[i-1]))&&(isA_Z(Cen[i+1]))))
            {
                if(Cen[i+1]>Cen[i-1]) // @@ 依赖未检查的下标；且缺少else分支输出'-'（当条件不满足时应原样输出'-'）。
                {
                    int j=Cen[i-1]+1;
                    for(;j<Cen[i+1];j++)
                        putchar(j);
                }
            } // @@ 此处缺少else分支，当前后字符类型不同或前>=后时应输出'-'原样。
        }
        else
            putchar(Cen[i]);
    }
    return 0;
}