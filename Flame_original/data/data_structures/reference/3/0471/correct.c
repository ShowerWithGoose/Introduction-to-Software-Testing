#include <stdio.h>
int num[100],flat=0,j=0;
int getpoint(char *x)
{
    int i=0,k=0,f=0,m=1,l=0;//f判断是否已遇到小数点，这意味着遇到零是否需要记录；k记录e后面需要填的数字
    while(*(x+i)!='\0')
    {
        if(*(x+i)=='.')
        {
            f=1; //遇到小数点
        }
        else
        {
            if(*(x+i)=='0')//读到0
            {
                if(flat==1)//若已知小数点前有非零数，则每一个读到的零都需要记，但只有小数点前面的零会影响位数k
                {
                    num[j++]=0;
                    if(f==0)
                        k++;
                }
                else if(f==1)//读到零时还未出现小数点前的非零数，则只有当零出现在小数点之后同时前面没有非零数时才影响位数
                {
                        if(j>0)
                            num[j++]=0;
                        else
                            k++;
                }
            }
            else//未读到零
            {
                num[j++]=*(x+i)-'0';//记录该数
                if(j==1)//遇到的第一个非零数，不管在小数点前还是后，都会影响位数
                {
                    k++;
                    if(f==0)
                        flat=1;
                }
                else if(f==0)//遇到的不是第一个非零数，若在小数点前则影响位数，在小数点后还需要观察第一个数是否遇到小数点
                {
                    k++;
                }
            }
        }
        i++;
    }
    return k;
}
int main()
{
    char s[100],*p1=s;
    int a;
    gets(s);
    a=getpoint(p1);//a即为k
    printf("%d",num[0]);
    if(j==1)
    {
        printf("e");
        if(flat==0)
            printf("-");
        printf("%d",a);
    }
    else
    {
        printf(".");
        for(int i=1;i<j-1;i++)
        {
            printf("%d",num[i]);
        }
        if(num[j-1]!=0)
            printf("%d",num[j-1]);
        if(a==1)
            printf("e0");//小数点不需要移动
        else if(flat==0)//第一个非零数在小数点后
            printf("e-%d",a);
        else
            printf("e%d",a-1);
    }
    return 0;
}



