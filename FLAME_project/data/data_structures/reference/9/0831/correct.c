#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#define LL long long
struct LINE{
    int id;
    int x1,x2;
    int y1,y2;
    int times;
};
int cmp(const void*a,const void*b);
typedef struct LINE Line;
int main(){
    Line line[105];
    int n=0;
    int count[105]={0};
    int flag=0;
    int x,y;

    scanf("%d",&n);
    for (int i = 0; i < n; ++i)
        scanf("%d %d %d %d",&line[i].x1,&line[i].y1,&line[i].x2,&line[i].y2);
	
	qsort(line,n,sizeof(Line),cmp);
		
    for (int i = 0; i < n; ++i) {
        flag=0;
        x=line[i].x2;
        y=line[i].y2;
        for (int j = 0; j < n; ++j) {
            if(j==i) continue;  //不与自己相连
//            if(x>line[j].x1) continue;  //不与横坐标小于自己的相连
			
            if(x==line[j].x1&&y==line[j].y1){
//            	for(int k=0;,k<n;k++){
                	count[i]++;        //找到一条
//					line[j].times++;
                	x=line[j].x2;
                	y=line[j].y2;
                	j=0;
                	continue;
//				}
            }
        }
    }

    flag=count[0];
    for (int i = 0; i < n; ++i)
        if(flag<count[i]) flag=count[i];
    for (int i = 0; i < n; ++i) {
        if(flag==count[i]){
            flag=i;
            break;
        }
    }

    printf("%d %d %d\n",count[flag]+1,line[flag].x1,line[flag].y1);

    return 0;
}
int cmp(const void* a,const void* b){
	Line *p1=(Line *) a;
	Line *p2=(Line *) b;
	if(p1->x1!=p2->x2)
	return p1->x1-p2->x2; 
	else return -(p1->x1-p2->x2);
}



