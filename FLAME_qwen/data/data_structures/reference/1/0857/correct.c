#include<stdio.h>
#include<stdlib.h>
int a[2][12];
int n;
void reset(int w);
int main(){
    scanf("%d",&n);
    reset(0);
    return 0;
}
void reset(int w){
    if(w == n){
        int k;
        for(k = 0;k < n;k++){
            printf("%d ",a[0][k] + 1);
        }
        printf("%c",10);
        return ;
    }
    int j;
    for(j = 0;j < n;j++){
        if(a[1][j] == 0){
            a[0][w] = j;
            a[1][j] = 1;
            reset(w + 1);
            a[1][j] = 0;
        }
    }
    return;
}
