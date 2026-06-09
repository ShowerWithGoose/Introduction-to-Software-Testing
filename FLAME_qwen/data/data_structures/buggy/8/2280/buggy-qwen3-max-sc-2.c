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
void delete(int q){ @@ // 'delete' is not a reserved keyword in C, but using it as a function name can cause issues with some compilers or coding standards; however, the real issue is that this function modifies the graph globally, which is acceptable per problem, but the main bug lies elsewhere.
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
        visit[team[i]]=1; @@ // The nodes in 'team' are already marked visited when added to 'team' in BBFS or previous BFS calls. Re-marking them here is harmless but unnecessary. The real issue is in BFS logic flow.
    }
    int newteam[30];int cou_nt=0;
    for(int i=0;i<count_team;i++){
        for(int j=0;j<n;j++){
            if(a[team[i]][j]==1&&visit[j]==0){
                newteam[cou_nt]=j;
                cou_nt++;
                visit[j]=1; @@ // Correctly marks as visited when enqueued, which prevents duplicates — this is good.
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
    count_team++; @@ // Now count_team becomes 1, so team[0] = 0, which is correct.
    while(BFS()!=0){ @@ // First call to BFS prints level 0 (just node 0) and returns number of nodes in next level. Then it calls BFS again immediately, which prints the next level. But this causes **double execution**: the first BFS() in condition prints, then body executes BFS() again and prints again — leading to **duplicate printing** of levels beyond the first.
        BFS(); @@ // This extra call causes every level after the first to be printed twice. For example, if graph is 0-1-2, output might be "0 1 1 2" instead of "0 1 2".
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
    BBFS(); @@ // Missing newline after last output — but problem expects four lines. However, test case may tolerate missing final newline? But more critically, BBFS has flawed control flow.
}