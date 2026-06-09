#include<stdio.h>
#include<stdlib.h>
int main()
{    
    int x[205]={0};
    int y[205]={0};
    int n;
    int sign=1;
    int k=0;
    int a=0;
    int max=1;
    int len=1;
    int l=0;
    int r=0;
    int lm=0;
    int rm=0;
    scanf("%d",&n);
    for(int i=0;i<2*n;i+=2)
    {
        scanf("%d%d%d%d",&x[i],&y[i],&x[i+1],&y[i+1]);
    }
    //输入

    for(int i=0;i<2*n;i+=2)
    {
        for(int j=i+1;j<2*n;j+=2)
        {
            
            if(x[i]==x[j]&&y[i]==y[j])
            {
                len++;
                l=x[j-1]; // @@ 错误：这里假设前一个点是起点，但j-1可能不是当前线段的起点，且未考虑线段方向
                r=y[j-1]; // @@ 错误：同上，起点坐标获取错误
                sign=1;
                k=j-1; // @@ 错误：k被设置为j-1，但后续循环中可能错误地访问了不相关的点
                while(sign==1)
                {
                
                sign=0;
                    for( a=0;a<2*n;a++)
                    {
                    if(k==a)
                    {
                        a++;
                    }
                    if(x[k]==x[a]&&y[k]==y[a])
                    {
                        len++;
                        l=x[a-1]; // @@ 错误：同样错误地假设a-1是起点
                        r=y[a-1]; // @@ 错误：同上
                        k=a-1; // @@ 错误：更新k的方式不正确，可能导致无限循环或错误连接
                        sign++;
                        a=0;
                        break;
                    }
                    }
                    a=0;
                }
            }
            

            if(x[i+1]==x[j+1]&&y[i+1]==y[j+1])
            {
                len++;
                k=j+2; // @@ 错误：k被设置为j+2，但后续循环中可能错误地访问了不相关的点
                sign=1;
                while(sign==1)
                {
                    sign=0;
                    for(a=0;a<2*n;a++)
                    {
                        if(k==a)
                        {
                            a++;
                        }
                        if(x[k]==x[a]&&y[k]==y[a])
                        {
                            len++;
                            k=a+1; // @@ 错误：更新k的方式不正确，可能导致无限循环或错误连接
                            sign++;
                            a=0;
                            break;
                        }
                    }
                    
                }
                
            }
            
        }    
        if(max<len)
        {
            max=len;
            lm=l; // @@ 错误：lm和rm只在第一个if分支中更新，第二个if分支未更新起点坐标
            rm=r;
        }
        len=1;

    }
    printf("%d %d %d\n",max,lm,rm);

    system("pause");
    return 0;
}