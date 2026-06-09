#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define MAX_LINK 100//看看会不会太大哈哈
#define MAX_BOT 100
#define MAX_NUM 1000

struct graph_{
    //int linksize;
    int link[MAX_LINK];//下标对应点的序号
};
typedef struct graph_ graph;
typedef struct graph_* pgraph;
graph bot[MAX_LINK];
int deletebot;
int bot_top=-1;
int visited[MAX_LINK]={1};
int queue[MAX_LINK];

void deleteBot(int site)
{
    int n;
    for(int i=0;i<MAX_LINK;i++){
        bot[i].link[site]=0;
        bot[site].link[i]=0;
    }
}
void printDeep(int n,int site)
{
    printf("%d ",site);
    for(int i=0;i<n;i++){
        if(bot[site].link[i]&&!visited[i]){
            visited[i]=1;
            printDeep(n,i);
        }
    }
}
print(int front,int rear)
{
    printf("\nqueue: ");
    for(int i=front;i<=rear;i++)
    {
        printf("%d ",queue[i]);
    }
    printf("\n");
}
void printWide(int n,int site)//广度还得是队列！！
{
    queue[0]=0;
    int front=0,rear=0;
    while(front<=rear){
        //print(front,rear);
        for(int i=0;i<n;i++){//每一次出队一个！
            if(!visited[i]&&bot[site].link[i]){
                queue[++rear]=i;
                visited[i]=1;//哈哈哈visited!
            }
        }
        printf("%d ",queue[front]);
        site=queue[++front];
    }
}
int main()
{
    int n,line,bot1,bot2;
    scanf("%d%d",&n,&line);
    for(int i=0;i<n;i++){
        for(int j=0;j<MAX_LINK;j++){
            bot[i].link[j]=0;
        }
    }
    for(int i=0;i<line;i++){
        scanf("%d%d",&bot1,&bot2);
        bot[bot1].link[bot2]=1;//看一下组这样子可以嘛！
        bot[bot2].link[bot1]=1;
    }
    printDeep(n,0);
    printf("\n");
    memset(visited,0,sizeof(visited));//好！重置！
    visited[0]=1;
    printWide(n,0);
    printf("\n");
    while(scanf("%d",&deletebot)!=EOF){
        deleteBot(deletebot);
    }
    //遍历的时候注意linksize!=0且link[i]!=MAX_NUM且while<linksize;
    memset(visited,0,sizeof(visited));
    visited[0]=1;
    printDeep(n,0);
    printf("\n");
    memset(visited,0,sizeof(visited));
    visited[0]=1;
    printWide(n,0);
    printf("\n");
    return 0;
}



