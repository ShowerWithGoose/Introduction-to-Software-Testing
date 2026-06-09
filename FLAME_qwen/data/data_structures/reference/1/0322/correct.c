#include <stdio.h>
int change(int i,int n);
int a[11],book[11];

int fullArray(int step, int n){
    int i;
    int save;
    save=step;
    if(step>n)
        return 0;
    for (i = 1; i <= n; i++) //每一步都从最小的开始尝试放数字
    {
        if (book[i] == 0) //如果还没有被用
        {
            a[step] = i;      //用一个数组装卡片，放下数字卡片
            book[i] = 1;      //表明放下的数字卡片被占用
            fullArray(step + 1, n); //开始下一步
            
            book[i] = 0;      //取回数字卡片
        }
    }
    for(i=1;i<=n;i++){
        if(save==n){
            if(i!=n)
            printf("%d ",a[i]);
        else
            printf("%d\n",a[i]);
            
        }
        
    }
    
}
int main(){
    int n,step=1;
    scanf("%d",&n);
    fullArray(step,n);
    return 0;
}
