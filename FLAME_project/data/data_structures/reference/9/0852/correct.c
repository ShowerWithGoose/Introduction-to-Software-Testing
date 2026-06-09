#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

#define MAX(a,b) ((a)?(b)? (a): (b))
#define MIN(a,b) ((a)?(b)? (a): (b))
#define pi acos(-1)
#define eps 1e-8
#define ULL unsigned long long
#define LL long long
struct line{
	int x1;
	int y1;
	int x2;
	int y2;
}line[150]; 
int cmp(const void *a,const void *b)
{
    if(*(int*)a>*(int*)b)
        return 1;
    if(*(int*)a<*(int*)b)
        return -1;
    return 0;
}
int main(){
	int n;
	scanf("%d",&n);
	int i,j,k,flag;
	for(i=0;i<n;i++){
		scanf("%d%d%d%d",&line[i].x1,&line[i].y1,&line[i].x2,&line[i].y2);
	}
	int count1=0,count2=0;
	qsort(line,n,sizeof(struct line),cmp);	
	for(i=0;i<n-1;i++){
		k=i;
		for(j=k+1;j<n;j++){
			if(line[k].x1<line[j].x1){
				if(line[k].x2==line[j].x1&&line[k].y2==line[j].y1){
					count1++;
					k=j;
				}
			}
		}
		if(count1>count2){
			count2=count1;
			flag=i;
		}
		count1=0;
	}
    printf("%d %d %d\n",count2+1,line[flag].x1,line[flag].y1);	
}


