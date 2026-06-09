#include<stdio.h>
int a, box[15], flag[15];
void dfs(int);
int main(){
    scanf("%d", &a);
    dfs(1);
    return 0;
}
void dfs(int step){
    int i;
    if(step==a+1){
        for (i = 1; i <= a; i++){
            printf("%d ", box[i]);
        }
        printf("\n");
        return;
    }
    for (i = 1; i <= a; i++){
        if(flag[i]==0){
            box[step] = i;
            flag[i] = 1;
            dfs(step + 1);
            flag[i] = 0;
        }   
        
    }
    
    return;
}


