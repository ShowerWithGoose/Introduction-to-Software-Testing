#include <stdio.h>
#include <math.h>//sqrt(x),exp(x),fabs(),pow(a,b)    double 型  floor() ceil() round()
#include <string.h>//strlen()字符串长度    strcpy()复制
#include <ctype.h>//isdigit(i),islower(),isupper()
#include <stdlib.h>
//思路：先排序再相连，保证从后向前相连，中间不会断
struct line{
    //int flag;
    int x1;
    int y1;
    int x2;
    int y2;
    int count;
};
int cmp(const void *e1, const void *e2);
int main()
{
    int n;
    scanf("%d",&n);
    struct line *gather=(struct line*)malloc(sizeof(struct line)*n);
    //用指针作为数组，避免空间浪费(是首地址也是数组名)
    for(int i=0;i<n;i++){
        scanf("%d%d%d%d",&gather[i].x1,&gather[i].y1,&gather[i].x2,&gather[i].y2);
        gather[i].count=1;
        
    }
    qsort(gather,n,sizeof(struct line),cmp);
    //遍历
    for(int i=n-1;i>=0;i--){
        for(int j=i-1;j>=0;j--){
            if(gather[i].x1==gather[j].x2&&gather[i].y1==gather[j].y2){
                gather[j].count+=gather[i].count;//连起来
                break;
            }
        }
    }
    int max=0;
    int k=0;
    for(int i=0;i<n;i++){
        max=(max>=gather[i].count)?max:gather[i].count;
        k=i; // @@ This always sets k to the last index, not the index with max count
    }
    
    printf("%d %d %d",max,gather[k].x1,gather[k].y1);
    return 0;
}
int cmp(const void *e1, const void *e2)
{
    return (((struct line*)e1)->x2)-((struct line*)e2)->x2;//大于0，做交换  右坐标升序
}