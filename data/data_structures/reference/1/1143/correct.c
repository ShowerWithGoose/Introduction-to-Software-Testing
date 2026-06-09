#include<stdio.h>
#include<string.h>
#include<math.h>


int n,flag[11]={0},place[11]={0};
void pl(int);

int main(){
    scanf("%d",&n);
    pl(1);
    return 0;
}

void pl(int x){
    int i;
    if(n+1==x){
        for(i=1;i<=n;i++){
            printf("%d ",place[i]);
        }
        printf("\n");
        return;
    }
    for(i=1;i<=n;i++){
        if(flag[i]==0){
            place[x]=i;
            flag[i]=1;
            pl(x+1);
            flag[i]=0;
        }
    }
}
