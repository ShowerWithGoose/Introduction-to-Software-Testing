#include<stdio.h>

int tmp[10000];
int count = 0;

void arrangement(int n,int depth,int A[]){

    for(int i = 1;i <= n;i ++){
        if(A[i] == 0){
            if(depth == n){
                for(int j = 0;j < count ;j ++){
                    printf("%d ",tmp[j]);
                }
                printf("%d\n",i);
                return;
            }
            A[i] = 1;
            tmp[count ++] = i;
            arrangement(n,depth + 1,A);
            count --;
            A[i] = 0;
        }
    }
}

int main(){

    int A[20];{
        for(int i = 0;i < 20;i ++){
            A[i] = 0;
        }
    }
    int n;
    scanf("%d",&n);
    arrangement(n,1,A);
}
