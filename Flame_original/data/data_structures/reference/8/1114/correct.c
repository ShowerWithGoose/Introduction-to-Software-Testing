#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<string.h>
size_t (*map)[4],dele;
char *check,bol;
void DFS(size_t vex){
    check[vex]=1;
    if(bol&&vex==dele)return;
    printf("%u ",vex);
    size_t tem[4],i=0,j;
    tem[0]=map[vex][0];tem[1]=map[vex][1];tem[2]=map[vex][2];tem[3]=map[vex][3];
    while(i<4&&!tem[i])i++;
    while(tem[0]|tem[1]|tem[2]|tem[3]){
        j=(size_t)(__builtin_ctz(tem[i]));
        tem[i]^=(1<<j);
        j=25*i+j;
        if(!check[j])DFS(j);
        while(i<4&&!tem[i])i++;
    }
    return;
}

void BFS(){
    size_t queue[100]={},tem[4],front=0,rear=1,i,j,vex;
    while(front!=rear){
        printf("%u ",queue[front]);
        i=0;vex=queue[front];check[vex]=1;
        tem[0]=map[vex][0];tem[1]=map[vex][1];tem[2]=map[vex][2];tem[3]=map[vex][3];
        while(i<4&&!tem[i])i++;
        while(tem[0]|tem[1]|tem[2]|tem[3]){
            j=(size_t)(__builtin_ctz(tem[i]));
            tem[i]^=(1<<j);
            j=25*i+j;
            if(!check[j]){
                if(!bol||dele!=j)queue[rear++]=j;
                rear%=100;
                check[j]=1;
            }
            while(i<4&&!tem[i])i++;
        }
        front++;front%=100;
    }
    return;
}

int main(){
    size_t m,n,vexnum,arcnum;
    scanf("%u%u",&vexnum,&arcnum);
    size_t adjmatrix[100][4];
    char visit[100];
    map=(size_t(*)[4])(memset(adjmatrix,0,sizeof(adjmatrix)));
    check=(char*)(memset(visit,0,sizeof(visit)));
    for(size_t i=0;i<arcnum;i++){
        scanf("%u%u",&m,&n);
        adjmatrix[m][n/25]|=(1<<(n%25));
        adjmatrix[n][m/25]|=(1<<(m%25));
    }
    scanf("%u",&dele);
    DFS(0);puts("");
    memset(visit,0,sizeof(visit));
    BFS();puts("");
    bol=1;
    memset(visit,0,sizeof(visit));
    DFS(0);puts("");
    memset(visit,0,sizeof(visit));
    BFS();puts("");
    return 0;
}
