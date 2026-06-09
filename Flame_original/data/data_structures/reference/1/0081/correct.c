//
//  main.c
//  全排列数的生成
//
//  Created by  on 2022/3/7.
//
#include <stdio.h>
//计算阶乘
int jiecheng(int n)
{
    int sum=1;
    for(;n>=1;n--)
        sum*=n;
    return sum;
}
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

int main()
{
    int n;
    scanf("%d",&n);
    int a[10]={0};
    for(int i=0;i<n;i++)
        a[i]=i+1;
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
        if(i==n-1)
            printf("\n");
    }
    //开始算下一位是哪个
    for(int o=1;o<jiecheng(n);o++){
        int m=0,l=0;
        //先判断哪个是比最后一位大的
       /* for(int i=n-2;i>=0;i--){
            if(a[i]>a[n-1]){
                m=i;
                break;
            }
            if(a[n-1]==n)
                m=n-1;
        }*/
        //在判断哪个是不递增的
        int max=a[n-1];
        for(int i=n-2;i>=0;i--){
            if(a[i]>max)
                max=a[i];
            else{
                l=i;
                break;
            }
        }
        //判断比它大的离最后一位最近的数
        for(int i=n-1;i>=0;i--){
             if(a[i]>a[l]){
                 m=i;
                 break;
             }
        }
        //交换二者
        swap(a+m,a+l);
        int re=(m<l?m:l);
        for(int i=re+1;i<n;i++)
            for(int j=i;j<n;j++)
                if(a[i]>a[j])
                    swap(a+i,a+j);
        //开始打印
        for(int i=0;i<n;i++){
            printf("%d ",a[i]);
            if(i==n-1)
                printf("\n");
        }
    }
}

