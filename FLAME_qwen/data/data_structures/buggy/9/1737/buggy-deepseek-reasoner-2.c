#include<stdio.h>
#include<string.h>
struct  cor{
        int x1;
        int y1;
        int x2;
        int y2;
        int flag;
        struct cor *link;
        
    };

int main()
{
    
    struct cor a[300];
    int n,m=0;
    scanf("%d",&n);
    
    while(scanf("%d%d%d%d",&a[m].x1,&a[m].y1,&a[m].x2,&a[m].y2)!=EOF)
    {
        
        a[m].flag=0; // @@ link未初始化，导致后续遍历时可能访问野指针
        m++;
        
    }
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(a[i].x2==a[j].x1&&a[i].y2==a[j].y1)
            {
                a[i].link=&a[j]; 
                a[i].flag=1;//a[i]有指向了 
                if(a[j].flag==0) // @@ 错误地修改目标节点的link，可能破坏已建立的链接
                a[j].link=NULL;
                 
            }
        }
        
    }
    int max=0,num=0;
    struct cor *p;
    struct cor list;
    for(int i=0;i<m;i++)
    {   num=0; // @@ num应从1开始计数当前节点，否则孤立线段（无后续）不会被计入
        for(p=&a[i]; p->link!= NULL; p=p->link) // @@ 条件应为p!=NULL，且应首先处理当前节点；当前写法会跳过无后续的节点
        {
            num++;
            if(num>max) // @@ num实际比线段数少1，导致最大长度计算错误；且孤立线段无法更新max，list保持未初始化
            {
            max=num;
            list=a[i];
        }
        }
    }
    printf("%d %d %d",max,list.x1,list.y1);
    return 0;
    
    
}