#include<stdio.h>
#include<stdlib.h>
int visited[120];
struct Line{
    int x1,y1,x2,y2;
}line[120];
int n;
int ans,st,ed;
int cmp(const void* a, const void *b)
{
	struct Line *c = (struct Line *)a;
	struct Line *d = (struct Line *)b;
    return c->x1-d->x1;
}
int main()
{
    scanf("%d",&n);
    for(int i = 1; i <= n; i++)
    scanf("%d%d%d%d",&line[i].x1,&line[i].y1,&line[i].x2,&line[i].y2);
    qsort(line+1,n,sizeof(struct Line),cmp);
    int cnt;
    for(int i = 1; i<= n; i++)
    {
        if(!visited[i]){
            int flagi = 1;
            cnt = 1;
            int tar1 = line[i].x2;
            int tar2 = line[i].y2;
            int now = i+1;
            while(now <= n){
                if(line[now].x1==tar1&&line[now].y1==tar2){
                    cnt++;
                    tar1 = line[now].x2;
                    tar2 = line[now].y2;
                    visited[now] = 1;
                }
                now++;
            }
            if(cnt>ans){
            	ans = cnt;
            	st = line[i].x1;
            	ed = line[i].y1;
			}
        }
    }
    printf("%d %d %d",ans,st,ed);
}

