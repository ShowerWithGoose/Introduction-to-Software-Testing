#include<stdio.h>
int a[200] = {0}, hash[200] = {0};
void dfs(int, int);


int main(){

    int n;
    scanf("%d", &n);
    dfs(n, 1);



    return 0;
}

void dfs(int n, int depth){
    int i = 0;
    if(depth == n+1){       //上一次递归为最后一次，这一次的depth == n+1
        for(i = 1; i <= n; ++i){
            printf("%d ", a[i]);
        }
        printf("\n");
        return;
    }
    for(i = 1;i <= n; ++i)
        if(!hash[i]){
            hash[i]++;
            a[depth] = i;
            dfs(n, depth+1);
            hash[i]--;
        }
}


