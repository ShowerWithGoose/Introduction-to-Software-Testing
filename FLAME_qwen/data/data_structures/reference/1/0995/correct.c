#include <stdio.h>
void dfs(int *,int *,int,int);
int main()
{
    int a[15]={0},b[15]={0};
    int n;
    scanf("%d",&n);
    dfs(a,b,n,1);//从第一层开始
    return 0;
}
void dfs(int *a,int *b,int n,int depth)
{
    //a记录数字是否使用过，b记录在该层输出的数
    int i=1;
    if(depth==n+1){
        //排列完毕
        for(i=1;i<=n;i++){
            printf("%d ",b[i]);
        }
        printf("\n");
    }
    for(i=1;i<=n;i++){
        if(!a[i]){
            //未使用
           a[i]=1;
           b[depth]=i;
           dfs(a,b,n,depth+1);//下一层 此处进入递归，i逆序退出
           a[i]=0;//层层退出，清除使用过的数字 
        }
    }
}
