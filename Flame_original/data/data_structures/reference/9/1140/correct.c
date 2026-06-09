#include<stdio.h>
#include<stdlib.h>
#define NUM 100
int main()
{
    struct line
    {
        int st_x;
        int st_y;
        int ed_x;
        int ed_y;
        struct line *next;
    }lines[NUM],*p;
    struct 
    {
        int st_line;
        int len;
    }begin[NUM];

    int num,flag=0,serl_num=0,max=0;
    scanf("%d",&num);
    for(int i=0;i<num;i++)
    {
        scanf("%d%d%d%d",&lines[i].st_x,&lines[i].st_y,&lines[i].ed_x,&lines[i].ed_y);

    }
    for (int i = 0; i < num; i++)
    {
        flag=0;
        for (int j = 0; j < num; j++)
        {
            if(i==0)lines[j].next=NULL;
            if(lines[i].st_x==lines[j].ed_x && lines[i].st_y ==lines[j].ed_y)
            {
                lines[j].next=&lines[i];
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            begin[serl_num++].st_line=i;
        }
    }
    for(int i=0;i<serl_num;i++)
    {
        p=lines+begin[i].st_line;
        begin[i].len=1;
        while(p->next!=NULL)
        {
            begin[i].len++;
            p=p->next;
        }
        if(i>0 && begin[i].len>begin[i-1].len)
        {
            max=i;
        }
    }
    printf("%d %d %d",begin[max].len,lines[begin[max].st_line].st_x,lines[begin[max].st_line].st_y);
    return 0;
}
