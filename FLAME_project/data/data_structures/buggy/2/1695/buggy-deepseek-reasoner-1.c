#include<stdio.h>

int main() {
    int a1=0,a2,a3;
    char s1='+',s2,s3;
    while (s1!='='){
        scanf("%d%c",&a2,&s2); // @@ [scanf格式没有跳过前导空格，导致读取到的s2是空格字符，后续输入解析错误，陷入无限循环]
        while (s2=='*'||s2=='/'){
            scanf("%d%c",&a3,&s3); // @@ [同样，scanf格式没有跳过空格，导致连续乘除时读取错误]
            if (s2=='*')
                a2=a2*a3;
            else if (s2=='/')
                a2=a2/a3;
            s2=s3;//产生循环，连续乘除 
        }
        if (s1=='+'){
            a1+=a2;
        }
        else if (s1=='-'){
            a1-=a2;
        }
        s1=s2;//产生循环，连续加减 
    }
    printf("%d",a1);
    return 0;
}