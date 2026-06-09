#include<stdio.h>
#include<string.h>
int a[12][12]; // @@ [Array size 12 is too small; maximum n is 100, should be at least 101.]
int visit[20]; // @@ [Array size 20 insufficient for n up to 100.]
int pass[20]; // @@ [Array size 20 insufficient (though not used in BFS, but still).]
int team[20]; // @@ [Array size 20 insufficient for n up to 100.]
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
    printf("%d ",q); // @@ [Prints trailing space; should not include space after last vertex.]
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
        printf("%d ",team[i]); // @@ [Prints trailing space; should not include space after last vertex.]
        visit[team[i]]=1;
    }
    int newteam[30]; // @@ [Array size 30 insufficient for n up to 100; should be at least 101.]
    int cou_nt=0;
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
    while(BFS()!=0){ // @@ [Incorrect loop logic; BFS is called twice per level, leading to extra BFS invocations.]
        BFS(); // @@ [Redundant call; BFS already called in condition, causing duplicate processing.]
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