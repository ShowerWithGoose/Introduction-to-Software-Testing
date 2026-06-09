#include <stdio.h>

int n, output[15], flag[15];

void DFS(int step){
    if(step == n){
        for(int i = 1; i <= n; i++){
            printf("%d ", output[i]);
        }
        printf("\n");
        return;
    }
    for(int i = 1; i <= n; i++){
        if(!flag[i]){
            output[step + 1] = i;
            flag[i] = 1;
            DFS(step + 1);
            flag[i] = 0;
        }
    }
}

int main(){
    scanf("%d", &n);

    DFS(0);

    return 0;
}
