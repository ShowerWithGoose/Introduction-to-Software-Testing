#include<stdio.h>

void Arrange(int *state,int *num,int n,int k)
{
    if (k == n){
        for (int i=0;i<n;i++) printf("%d ",num[i]);
        printf("\n");
        return;
    }
    for (int i=1;i<=n;i++){
        if (state[i] == 1) continue;
        state[i] = 1;
        num[k] = i;
        Arrange(state,num,n,k+1);
        num[k] = 0;
        state[i] = 0;
    }
    return;
}

int main(){
    int n;
    int state[20] = {0},num[20] = {0};

    scanf("%d",&n);
    Arrange(state,num,n,0);

    return 0;
}
