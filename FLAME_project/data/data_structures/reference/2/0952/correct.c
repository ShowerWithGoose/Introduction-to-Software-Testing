#include<stdio.h>
int main()
{
    int num[10000]={0}, i=0, cal1, cal2, sum=0, sgn=1;
    char op;
    while(scanf(" %d ", &cal1))//先读入一个数字
    {
        out1:
        scanf(" %c", &op);//读入数字后面的运算符
        if(op=='+') //如果为加号或减号则直接保存到数组中
        {
            num[i]=sgn*cal1;
            sgn=1;
        }
        else if(op=='-') 
        {
            num[i]=sgn*cal1;
            sgn=-1;
        }
        else if(op=='*') //如果为乘号或除号则先进行乘除运算直至读到下一个加减号，然后将数值保存到数组中
        {
            scanf(" %d ", &cal2);
            cal1*=cal2;
            goto out1;
        }
        else if(op=='/')
        {
            scanf(" %d ", &cal2);
            cal1/=cal2;
            goto out1;
        }
        else if(op=='=') 
        {
            num[i]=sgn*cal1;
            break;
        }
        i++;
    }
    for(;i>-1;i--) sum+=num[i];
    printf("%d", sum);
    return 0;
}
