#include <stdio.h>
#include <stdlib.h>

int cmp(const void*e1,const void*e2);

typedef struct line{
    int start_x;
    int start_y;
    int end_x;
    int end_y;
    int counter;
} line;

int main()
{
    int n;
    scanf("%d",&n);
    line *gather = malloc(sizeof(line)*n);
    
    for (int i=0;i<n;i++){
        scanf("%d%d%d%d",&gather[i].start_x,&gather[i].start_y,&gather[i].end_x,&gather[i].end_y);
        gather[i].counter = 1;
    }
    
    qsort(gather,n,sizeof(line),cmp);
    for(int i=n-1;i>0;i--){
        for(int j=i-1;gather[j].end_x>=gather[i].start_x;j--){
            if(gather[i].start_x==gather[j].end_x&&gather[i].start_y==gather[j].end_y){
                gather[j].counter += gather[i].counter;
                break;
            }
        }
    }

    int max_num = 0;
    line target;
    for(int i=0;i<n;i++){
        if(max_num<gather[i].counter){
            max_num = gather[i].counter;
            target = gather[i];
        }
    }
    printf("%d %d %d",max_num,target.start_x,target.start_y);
    return 0;
}
int cmp(const void*e1,const void*e2)
{
    line *data1 = (line*)e1;
    line *data2 = (line*)e2;
    return data1->end_x-data2->end_x;
}
