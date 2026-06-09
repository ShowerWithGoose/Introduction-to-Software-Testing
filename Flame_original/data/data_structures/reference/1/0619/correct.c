#include<stdio.h>
int a[10],book[10]={0};
void dfs(int step,int n) {
    int i;
    if(step==n){
        for(i=0;i<n;i++){
            printf("%d ",a[i]);
        }
        printf("\n");
        return;
    }
    for(i=0;i<n;i++){
        if(book[i]==0){             //第i个数还没有用过
            a[step]=i+1;
            book[i]=1;              //标记第i个数，表示已经用过
            dfs(step+1,n);
            book[i]=0;              //解除第i个数的标记
        }
    }
}


int main(){
	int n;
    scanf("%d",&n);
    dfs(0,n);
    return 0;
}


