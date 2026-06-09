#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#define M 105
#define ll long long

typedef struct node{
    int x1;
    int y1;
    int x2;
    int y2;
    int count;
} node;

int inc(const void *a, const void *b) {
    struct node *aa=(struct node *)a;
	struct node *bb=(struct node *)b;
	if (aa->x1!=bb->x1)
		return aa->x1-bb->x1;
	else
		return aa->y1-bb->y1;
}

int main() {
    node line[105];
    int n,i,j;
    int maxc=0,maxi=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d %d %d %d",&line[i].x1,&line[i].y1,&line[i].x2,&line[i].y2);
        line[i].count=1;
    }
    qsort(line, n, sizeof(node), inc);

    // // 检查是否排序成功
    // printf("\n\n");
    // for(i=0;i<n;i++){
    //     printf("%d %d %d %d\n",line[i].x1,line[i].y1,line[i].x2,line[i].y2);
    // }
    // printf("\n\n");

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(j==i)
                continue;
            if(line[i].x2==line[j].x1&&line[i].y2==line[j].y1){
                line[i].x2=line[j].x2;
                line[i].y2=line[j].y2;
                line[j].x1=-1;
                line[j].y1=-1;
                line[i].count++;
            }
        }
    }

    // printf("\n\n");
    // for(i=0;i<n;i++){
    //     printf("%d %d %d %d %d\n",line[i].x1,line[i].y1,line[i].x2,line[i].y2,line[i].count);
    // }
    // printf("\n\n");

    for(i=0;i<n;i++){
        if(maxc<line[i].count){
            maxc=line[i].count;
            maxi=i;
        }
    }

    printf("%d %d %d",line[maxi].count,line[maxi].x1,line[maxi].y1);
    
	return 0;
}
