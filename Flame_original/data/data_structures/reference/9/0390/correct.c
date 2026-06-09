#include <stdio.h>
struct line
{
    int x1,x2,y1,y2;
    struct line* next;
}lines[100];

int main(){
    int i,j,n,cnt,max_cnt=0;
    struct line* p,res;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d%d%d%d",&lines[i].x1,&lines[i].y1,&lines[i].x2,&lines[i].y2);
        lines[i].next=NULL;
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(lines[i].x1==lines[j].x2&&lines[i].y1==lines[j].y2)
                lines[j].next=&lines[i];
        }
    }
    for(i=0;i<n;i++)
    {
        cnt=1;
        p=lines[i].next;
        while(p!=NULL){
            cnt++;
            p=p->next;
        }
        if(cnt>max_cnt){
            max_cnt=cnt;
            res=lines[i];
        }
    }
    printf("%d %d %d",max_cnt,res.x1,res.y1);
    return 0;
}



