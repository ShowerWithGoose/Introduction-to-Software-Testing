#include<stdio.h>
#include<string.h>
int a[12][12];
int visit[20];
int pass[20];
int team[20];
int count_team=0;
int n,m;
void clean(){
    for(int i=0;i<n;i++){
        visit[i]=0;
    }
}
void delete(int q){ @@ // 'delete' is not a reserved keyword in C, but using it as a function name can cause issues with some compilers or coding standards; however, the real issue is that this function modifies the graph globally, which is acceptable. The main error lies elsewhere.
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
            visit[i]=1; @@ // This line sets visit[i] = 1 after the recursive call, but it's redundant because inside DFS(i), visit[i] is already set to 1 at the beginning. However, this is not the critical error.
        }
    }
    }
}
int BFS()
{   
    for(int i=0;i<count_team;i++){
        printf("%d ",team[i]);
        visit[team[i]]=1; @@ // This marks nodes as visited while printing, but these nodes were already marked visited when added to 'team' in the previous level. This may cause inconsistencies if not handled carefully, but still not the main bug.
    }
    int newteam[30];int cou_nt=0;
    for(int i=0;i<count_team;i++){
        for(int j=0;j<n;j++){
            if(a[team[i]][j]==1&&visit[j]==0){
                newteam[cou_nt]=j;
                cou_nt++;
                visit[j]=1; @@ // Marking as visited here is correct to avoid re-adding, so this is okay.
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
    count_team++; @@ // This initializes the BFS queue with node 0, which is correct.
    while(BFS()!=0){
        BFS(); @@ // This calls BFS() twice per loop iteration: once in the condition and once in the body. This causes skipping of levels or incorrect traversal order.
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
    BBFS(); @@ // Missing newline at the end of output; expected output format requires each sequence on its own line, including the last one.
}