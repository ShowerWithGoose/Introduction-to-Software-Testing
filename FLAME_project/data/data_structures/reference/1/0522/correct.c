#include<stdio.h>
void f(int* a,int* b,int x,int y);
int main()
{
    int n,a[15]={0},b[15]={0};     //数组a，b表示所有数还没用过
    scanf("%d",&n);
    f(a,b,n,1);
    return 0;
}
void f(int* a,int* b,int x,int y)
{
    if(y==x+1){
        for(int i=1;i<=x;i++){
            printf("%d ",a[i]);
        }
        printf("\n");
    }
    else{
        for(int i=1;i<=x;i++){
            if(b[i]==0){      //该数是否用过
                b[i]=1;      //记录该数被使用
                a[y]=i;
                f(a,b,x,y+1);
                b[i]=0;        //撤销选择
            }
        }
    }
}



