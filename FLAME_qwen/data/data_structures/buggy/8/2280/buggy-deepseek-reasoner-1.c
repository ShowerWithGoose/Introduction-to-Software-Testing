#include<stdio.h>
#include<string.h>
int a[12][12]; // @@ Array size too small for n up to 100; may cause out-of-bounds access.
int visit[20]; // @@ Array size too small for n up to 100; out-of-bounds if n > 20.
int pass[20];
int team[20]; // @@ Array size too small for n up to 100; BFS queue may exceed 20.
int count_team=0;
int n,m;
void clean(){
    for(int i=0;i<n;i++){
        visit[i]=0;
    }
}
void delete(int q){
    for(int i=0;i<n;i++){
        if(a[i][q]==1){
            a[i][q]=0;
            a[q][i]=0;
        }
    }
}
void DFS(int q){
    {
    printf("%d ",q);
    visit[q]=1;
    for(int i=0;i<n;i++){
        if(a[q][i]==1&&visit[i]==0){
            DFS(i);
            visit[i]=1;
        }
    }
    }
}
int BFS()
{   
    for(int i=0;i<count_team;i++){
        printf("%d ",team[i]);
        visit[team[i]]=1;
    }
    int newteam[30];int cou_nt=0; // @@ newteam size 30 may be insufficient for n up to 100.
    for(int i=0;i<count_team;i++){
        for(int j=0;j<n;j++){
            if(a[team[i]][j]==1&&visit[j]==0){
                newteam[cou_nt]=j;
                cou_nt++;
                visit[j]=1;
            }
        }
    }
    count_team=cou_nt;
    for(int i=0;i<n;i++){
        team[i]=0;
    }
    for(int i=0;i<count_team;i++){
        team[i]=newteam[i];
    }
    return count_team;
}
void BBFS(){
    clean();
    team[count_team]=0;
    visit[0]=1;
    count_team++;
    while(BFS()!=0){ // @@ Double call to BFS() in condition and body; should only call once per iteration to avoid redundant processing.
        BFS(); // @@ Redundant call causing double processing of levels.
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        int b,c;
        scanf("%d%d",&b,&c);
        a[b][c]=1;
        a[c][b]=1;
    }
    int spot_del;
    scanf("%d",&spot_del);
    clean();
    DFS(0);
    printf("\n");
    BBFS();
    printf("\n");
    delete(spot_del);
    clean();
    DFS(0);
    printf("\n");
    BBFS();
}