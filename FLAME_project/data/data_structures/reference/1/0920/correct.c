#include<stdio.h>
#include<string.h>
#include<math.h>
#define true 1
#define false 0
int n,num[20],used[20];
void dfs(int step){
    if(step > n){
        for(int i = 1; i <= n; i++) printf("%d ",num[i]);
        printf("\n");
        return;
    }
    for(int i = 1; i <= n; i++){
        if(!used[i]){
            num[step] = i;
            used[i] = true;
            dfs(step + 1);
            num[step] = 0;
            used[i] = false;
        }
    }
}
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) used[i] = false;
    dfs(1);
    return 0;
}

