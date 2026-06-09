#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int flag;
int n,m;
int a[101][101];
int team[101];
int visit[101];
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
    for(i = 0;i < m;i++){
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
        for (i = 0; i < m; i++) {
            if (a[m][i] == 1 && c[i] == 0) {
                b[++j] = i;
            }
        }
    }
}
int main(){
    scanf("%d%d",&n,&m);
    int i;
    for(i = 0;i < m;i++){
        int num1,num2;
        scanf("%d%d",&num1,&num2);
        a[num1][num2] = 1;
        a[num2][num1] = 1;
    }
    int delete;
    scanf("%d",&delete);
    DFS(a,visit,0);
    printf("\n");
    memset(visit,0,sizeof(int)*101);
    flag = 0;
    BFS(a,team,visit,0);
    printf("\n");
    memset(visit,0,sizeof(int)*101);
    visit[delete] = 1;
    flag = 0;
    DFS(a,visit,0);
    printf("\n");
    memset(visit,0,sizeof(int)*101);
    visit[delete] = 1;
    flag = 0;
    BFS(a,team,visit,0);
    printf("\n");
    return 0;


}
