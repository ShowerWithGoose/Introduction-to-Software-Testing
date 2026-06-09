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
void delete(int q){ // @@ [The function name 'delete' is a reserved keyword in C++ and may cause compilation issues in some environments; although it's technically allowed in pure C, it's poor practice and can lead to portability or compiler-specific errors. However, the main issue here is that the BFS implementation is flawed and doesn't correctly simulate queue-based traversal.]
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
            visit[i]=1; // @@ [This line is redundant because 'visit[i]' is already set to 1 at the beginning of the DFS(i) call. It doesn't break correctness but is unnecessary. However, the real error lies elsewhere.]
        }
    }
    }
}
int BFS()
{   
    for(int i=0;i<count_team;i++){
        printf("%d ",team[i]);
        visit[team[i]]=1; // @@ [This sets visited status during printing, but nodes in 'team' should already be marked visited when added to 'team'. This causes incorrect behavior: nodes may be printed multiple times or not enqueued properly. Also, this BFS does not start fresh—it relies on global 'team' and 'count_team', which are not reset properly between calls.]
    }
    int newteam[30];int cou_nt=0;
    for(int i=0;i<count_team;i++){
        for(int j=0;j<n;j++){
            if(a[team[i]][j]==1&&visit[j]==0){
                newteam[cou_nt]=j;
                cou_nt++;
                visit[j]=1; // @@ [Marking visited here prevents duplicates, but because printing happens before this level is processed, the order may be off. More critically, the BFS logic is implemented as level-by-level recursive-like iteration, but it's called multiple times in BBFS(), leading to incorrect output format and missing newlines.]
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
    while(BFS()!=0){
        BFS(); // @@ [Calling BFS() twice per loop iteration: once in condition, once in body. This causes every other level to be skipped or printed twice. The first call prints level 0, then inside loop body calls BFS again which prints level 1, but then condition checks BFS again (printing level 2), etc. This leads to incorrect BFS sequence.]
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
    printf("\n"); // @@ [This newline is printed after BBFS(), but BBFS() itself already prints all levels without a trailing newline. However, the bigger issue is that BBFS() prints the entire BFS in multiple calls to BFS(), each printing a level—but the problem expects a single line of space-separated vertices. So output format is wrong: it prints levels on separate lines implicitly due to multiple printf calls across BFS invocations.]
    delete(spot_del);
    clean();
    DFS(0);
    printf("\n");
    BBFS(); // @@ [Missing final newline after last BFS output. Expected output requires four lines, but this only prints three newlines total (after first DFS, after first BBFS, after second DFS). The last BBFS() doesn't end with '\n', causing formatting mismatch.]
}