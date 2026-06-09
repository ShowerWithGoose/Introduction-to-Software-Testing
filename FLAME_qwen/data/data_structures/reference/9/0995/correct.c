#include <stdio.h>
#include <stdlib.h>
typedef struct line
{
    int start[2];
    int end[2];
    int linked;
    struct line *next;
}LINE;
int max(int *);
int num=0;
int main()
{
    LINE *lines[105];
    int N;//线段数，同时也是节点申请空间数
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        LINE *p=malloc(sizeof(LINE));
        scanf("%d%d%d%d",&(p->start[0]),&(p->start[1]),&(p->end[0]),&(p->end[1]));
        p->linked=0;
        lines[i]=p;
    }
    LINE *head[105],*tail[105],*pos[105];
    for(int i=0;i<105;i++){
        head[i]=tail[i]=pos[i]=NULL;
    }
    for(int i=0,j=0;i<N;i++){
        if(lines[i]->linked){
            continue;
        }
        head[j]=lines[i];
        tail[j]=lines[i];//外部连接端口
        lines[i]->linked=1;//链接标记
        exit:
        for(int k=0;k<N;k++){
            if(lines[k]->linked){
                continue;
            }
            if(lines[k]->end[0]==head[j]->start[0]&&lines[k]->end[1]==head[j]->start[1]){
                lines[k]->next=head[j];
                head[j]=lines[k];
                lines[k]->linked=1;
                goto exit;
            }
            if(lines[k]->start[0]==tail[j]->end[0]&&lines[k]->start[1]==tail[j]->end[1]){
                tail[j]->next=lines[k];
                tail[j]=lines[k];
                lines[k]->linked=1;
                goto exit;
            }
        }
        j++;
    }
    int count[105];
    for(int i=0;i<105;i++)count[i]=1;
    for(int i=0;i<N;i++){
        pos[i]=head[i];
        while(pos[i]!=tail[i]){
            pos[i]=pos[i]->next;
            count[i]++;
        }
    }
    printf("%d ",max(count));
    printf("%d %d",head[num]->start[0],head[num]->start[1]);
    for(int i=0;i<N;i++){
        free(lines[i]);
    }
    return 0;
}
int max(int count[105])
{
    int Max=0;
    for(int i=0;i<105;i++){
        if(count[i]>Max){
            Max=count[i];
            num=i;
        }
    }
    return Max;
}
