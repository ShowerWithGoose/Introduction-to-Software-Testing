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
void delete(int q){ // @@ [The function name 'delete' is a reserved keyword in C++ and may cause issues with some compilers or coding standards, though it's technically allowed in C. However, more critically, this function only removes edges but does not prevent traversal to the deleted vertex in DFS/BFS if not handled in traversal logic. But the main error here is semantic: after deletion, the graph should exclude the vertex entirely from traversal, yet DFS still visits neighbors without checking if they are the deleted vertex. However, the immediate compilation issue is not here. The real problem causing incorrect output is in DFS marking visit[i]=1 AFTER recursive call, which can lead to revisiting nodes.]
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
            visit[i]=1; // @@ [This line marks the node as visited AFTER the recursive DFS call. This can cause the same node to be entered multiple times if it's reachable via multiple paths before being marked visited, leading to duplicate outputs or infinite recursion in cyclic graphs. The correct approach is to mark the node as visited BEFORE the recursive call.]
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
    int newteam[30];int cou_nt=0;
    for(int i=0;i<count_team;i++){
        for(int j=0;j<n;j++){
            if(a[team[i]][j]==1&&visit[j]==0){
                newteam[cou_nt]=j;
                cou_nt++;
                visit[j]=1; // @@ [Marking visited here is correct for BFS to avoid enqueueing same node multiple times. However, note that 'visit' array is shared between DFS and BFS, and clean() resets it, so this may be okay. But combined with DFS error above, overall traversal is flawed.]
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
        BFS(); // @@ [Calling BFS() twice per loop iteration: once in condition and once in body. This causes skipping of levels or incorrect traversal order because the first call in condition already prints and processes the current level, then the second call processes the next level but prints it again immediately, disrupting the BFS sequence.]
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