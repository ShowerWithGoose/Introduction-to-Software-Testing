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
void delete(int q){ // @@ [The function name 'delete' is a reserved keyword in C++ and may cause compilation issues in some environments, though it's technically allowed in C. However, more critically, this function modifies the global adjacency matrix 'a', but the BFS implementation does not correctly handle traversal after deletion due to flawed logic in BBFS/BFS.]
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
            visit[i]=1; // @@ [This line sets visit[i]=1 after the recursive call, but it should be set before or inside the DFS call to prevent revisiting. However, since DFS(i) already marks visit[i]=1 at its start, this is redundant but not the main error. The real issue is elsewhere.]
        }
    }
    }
}
int BFS()
{   
    for(int i=0;i<count_team;i++){
        printf("%d ",team[i]);
        visit[team[i]]=1; // @@ [This marks nodes as visited while printing, but they might have already been visited. More importantly, the BFS logic is fundamentally flawed: it prints the current level (team), then builds the next level (newteam), but calls BFS() again in BBFS without proper queue management, leading to incorrect traversal order and possible infinite loops or missed nodes.]
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
    count_team++;
    while(BFS()!=0){
        BFS(); // @@ [Calling BFS() twice per loop iteration: once in the condition and once in the body. This causes skipping of levels or duplicate processing, leading to incorrect BFS output.]
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
    BBFS(); // @@ [Missing newline after last output; expected output format requires each traversal on its own line, so this line should be followed by printf("\n");]
}