#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int flag;
int ding,bian;
int putin[101][101];
int visit[101];
int zhishi[101];
void DFS(int a[][101],int b[],int n){
    if(flag == 1){
        printf(" %d",n);
    }
    else{
        printf("%d",n);
        flag = 1;
    }
    b[n] = 1;
    int i;
    for(i = 0;i < bian;i++){
        if(a[n][i]==1&&b[i]==0){
            DFS(a,b,i);
        }
    }
}
void BFS(int a[][101],int b[],int c[],int n){
    b[0] = n;
    int m;
    int s=0,j=0;
    while(s<=j) {
        m = b[s++];
        if (c[m] == 1)continue;

        if (flag == 0) {
            printf("%d",m);
            flag = 1;
        }
        else {
            printf(" %d",m);
        }
        c[m] = 1;
        int i;
        for (i = 0; i < bian; i++) {
            if (a[m][i] == 1 && c[i] == 0) {
                b[++j] = i;
            }
        }
    }
}
int main(){
    scanf("%d%d",&ding,&bian);
    int i;
    for(i = 0;i < bian;i++){
        int num1,num2;
        scanf("%d%d",&num1,&num2);
        putin[num1][num2] = 1;
        putin[num2][num1] = 1;
    }
    int delete;
    scanf("%d",&delete);
    DFS(putin,zhishi,0);
    printf("\n");
    memset(zhishi,0,sizeof(int)*101);
    flag = 0;
    BFS(putin,visit,zhishi,0);
    printf("\n");
    memset(zhishi,0,sizeof(int)*101);
    zhishi[delete] = 1;
    flag = 0;
    DFS(putin,zhishi,0);
    printf("\n");
    memset(zhishi,0,sizeof(int)*101);
    zhishi[delete] = 1;
    flag = 0;
    BFS(putin,visit,zhishi,0);
    printf("\n");
    return 0;


}
