#include <stdio.h>
int a[11],used[11]={0};
void dfs(int step,int n) {
    int i;
    if(step>n){
        for(i=1;i<=n;i++){
            printf("%d ",a[i]);
        }
        printf("\n");
       // return;
    }
    for(i=1;i<=n;i++){
        if(!used[i]){             //第i个数还没有用过
            a[step]=i;
            used[i]=1;              //标记第i个数，表示已经用过
            dfs(step+1,n);
            used[i]=0;              //解除第i个数的标记
        }
    }
}
int main(){
	int n;
	scanf("%d",&n);
	dfs(1,n);
	return 0;
}

