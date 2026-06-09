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
    for(i=0;i<n;i++){ // @@ The outer loop variable 'i' is reused in the inner loop, causing logic errors and infinite loops or skipped iterations. Also, the inner loop initialization and structure are incorrect.
        x3=dian[i].x2; // @@ Logic error: The chain building logic is flawed. It should start a new chain for each unvisited segment or use a different approach to find connected components.
        y3=dian[i].y2; // @@ Logic error: Same as above.
        for(i=0;i<n;i++){ // @@ Critical Error: The inner loop uses 'i' which conflicts with the outer loop's 'i'. It should use a different variable (e.g., 'j') and iterate correctly to find the next segment in the chain.
            if(dian[j].x1==x3&&dian[j].y1==y3){ // @@ Error: Variable 'j' is used but not initialized or incremented in this loop context. It should be the loop variable of the inner loop.
            
            count[i]++; // @@ Error: 'i' is the loop variable of the inner loop (if corrected to j, it would be j). This updates the count for the wrong segment. It should update the count for the starting segment of the chain.
            x3=dian[j].x2; // @@ Error: 'j' is undefined/uninitialized in this scope as per the current buggy loop structure.
            y3=dian[j].y2; // @@ Error: 'j' is undefined/uninitialized in this scope as per the current buggy loop structure.
        } // @@ Missing closing brace for the if statement, causing syntax error or logical grouping error.
    } // @@ Missing closing brace for the inner for loop.
}//上次上机的时候，助教老师给我邻座的同学讲这个题来着，记下来思路，回去做出来
j=0;
for(i=0;i<n;i++){
    if(count[i]>ans)
    {
    ans=count[i];
    j=i;}}
    printf("%d %d %d\n",ans+1,dian[j].x1,dian[j].y1);
    return 0;}