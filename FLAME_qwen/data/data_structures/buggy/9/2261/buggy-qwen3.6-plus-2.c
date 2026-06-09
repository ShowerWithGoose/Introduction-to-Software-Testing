#include<malloc.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
struct node{
    int x1,x2,y1,y2;
}dian[2000];//存点
//开始以为每个点是排序了的，后来发现不是啊，那还得排序，我就排序最费劲，所以这段是网上找的
int cmp(const void *a,const void *b){
    struct node* e1=(struct node *)a;
    struct node* e2=(struct node *)b;
    if(e1->x1>e2->x1)
    return 1;
    else if(e1->x1<e2->x1)
    return -1;
    else
    return 0;
}//这一段好像我在上一个多项式那里也用过，记录下来以后多用
int main() {
    int x3=0,y3=0;//当前点（需要判断能否连接）
    int i,j,n;
    int count[2000]={0};
    int ans=-1;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    scanf("%d %d %d %d",&dian[i].x1,&dian[i].y1,&dian[i].x2,&dian[i].y2);
    qsort(dian,n,sizeof(struct node),cmp);
    for(i=0;i<n;i++){
        x3=dian[i].x2;
        y3=dian[i].y2;
        for(i=0;i<n;i++){ // @@ Reusing loop variable 'i' causes logical error and potential compilation warning; should use 'j' and initialize as 'j=i+1'
            if(dian[j].x1==x3&&dian[j].y1==y3){ // @@ Variable 'j' is used uninitialized, leading to undefined behavior/compilation error
            
            count[i]++; // @@ Logic error: increments wrong index due to 'i' being overwritten by inner loop; also count array is not reset for each starting segment
            x3=dian[j].x2;
            y3=dian[j].y2;
        }
    }
}//上次上机的时候，助教老师给我邻座的同学讲这个题来着，记下来思路，回去做出来
j=0;
for(i=0;i<n;i++){
    if(count[i]>ans)
    {
    ans=count[i];
    j=i;}}
    printf("%d %d %d\n",ans+1,dian[j].x1,dian[j].y1);
    return 0;}