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
    printf("%d ",q); // @@ The output format has a trailing space, but the expected output does not have a trailing space at the end of the line. It should print spaces between numbers, not after the last number.
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
        printf("%d ",team[i]); // @@ Similar to DFS, this prints a trailing space. Also, the logic of printing inside BFS helper is flawed for standard BFS output formatting which usually requires knowing if it's the first element or not to avoid trailing/leading spaces correctly in a single line context.
        visit[team[i]]=1;
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
        BFS(); // @@ This calls BFS again without printing, but modifies visit array and queue state incorrectly. The first call to BFS in the while condition prints and processes. The second call inside the loop processes the next level but also prints, leading to duplicate or incorrect output structure depending on implementation details. More critically, the BFS implementation here is non-standard and buggy: it prints level by level but the `visit` marking inside the printing loop and the neighbor discovery loop is inconsistent. Specifically, neighbors are marked visited when added to `newteam`, but the current level nodes are marked visited when printed. This can lead to race conditions or missed nodes if not careful, but the main issue is the output format (trailing spaces) and the double call to BFS.
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