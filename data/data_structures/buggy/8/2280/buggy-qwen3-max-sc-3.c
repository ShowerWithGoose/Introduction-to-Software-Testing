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
void delete(int q){ @@ // 'delete' is not a reserved keyword in C, but using it as a function name can cause issues with some compilers or be confusing; however, the real issue is that this function modifies the graph globally, which is acceptable per problem, BUT the main bug lies elsewhere.
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
            visit[i]=1; @@ // This line is redundant and incorrect: visit[i] is already set to 1 inside the recursive DFS(i) call. Setting it again here doesn't break logic but is unnecessary. However, the real error is not here.
        }
    }
    }
}
int BFS()
{   
    for(int i=0;i<count_team;i++){
        printf("%d ",team[i]);
        visit[team[i]]=1; @@ // Error: team[i] may contain uninitialized or stale values from previous BFS runs because 'team' array is not fully reset before reuse. Also, printing happens BEFORE processing neighbors, which is okay for BFS level-by-level, but the bigger issue is in BBFS logic.
    }
    int newteam[30];int cou_nt=0;
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
    count_team++; @@ // Error: count_team is global and not reset to 0 before this. If BBFS is called more than once (as in after deletion), count_team retains its previous value, causing team[count_team]=0 to write to wrong index and corrupt BFS queue.
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
    BBFS(); @@ // Missing newline in output: problem requires each traversal on its own line, but last BBFS() doesn't print '\n', causing formatting mismatch.
}