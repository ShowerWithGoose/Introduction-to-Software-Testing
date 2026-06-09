#include<stdio.h>
#include<string.h>
int dot,side,head,tail,q[500],book[105],b[105][105];
void dfs(int pos);
void bfs();
int main(){
    int i,a1,a2,delete;
    scanf("%d%d",&dot,&side);
    for(i=0;i<side;i++){
        scanf("%d%d",&a1,&a2);
        b[a1][a2]=1;
        b[a2][a1]=1;
    }
    scanf("%d",&delete);
    book[0]=1;
    printf("0 ");
    dfs(0);
    memset(book,0,100);
    book[0]=1;
    printf("\n0 ");
    bfs();
    memset(book,0,100);
    book[delete]=1;
    book[0]=1;
    printf("\n0 ");
    dfs(0);
    memset(book,0,100);
    book[delete]=1;
    book[0]=1;
    printf("\n0 ");
    bfs();
}
void dfs(int pos){
    int i;
    for(i=0;i<dot;i++){
        if(b[pos][i]==1&&book[i]==0){
            book[i]=1;
            printf("%d ",i);
            dfs(i);
        }
    }
}

void bfs(){
    int i;
    tail++;
    q[head]=0;
    while(head!=tail){
        for(i=0;i<dot;i++){
            if(b[q[head]][i]==1&&book[i]==0){
                printf("%d ",i);
                book[i]=1;
                q[tail++]=i;
            }
        }
        head++;
    }
}
