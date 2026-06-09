#include<stdio.h>
int used[10],num[10],print[10];
int n;
void dps(int depth){
	int i;
    if(depth==n){
        for(i=0;i<n-1;i++){
            printf("%d ",print[i]);
        }
        printf("%d\n",print[n-1]);
        return;
    }
    for(i=0;i<n;i++){
        if(used[i])continue;
        print[depth]=num[i];
        used[i]=1;
        dps(depth+1);
        used[i]=0;
    }
    return;
}
int main(){
    scanf("%d",&n);
    int i;
    for(i=0;i<n;i++){
        used[i]=0;
        num[i]=i+1;
    }
    dps(0);
}
