#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include <math.h>
struct Line{
	int x1,y1,x2,y2;
	int num;
}line[105];
int cmp(void* p1,void* p2)
{
	if(((struct Line*)p1)->x1!=((struct Line*)p2)->x1)
	return ((struct Line*)p1)->x1-((struct Line*)p2)->x1;
	return ((struct Line*)p1)->y1-((struct Line*)p2)->y1;
}
int main()
{
	int i,j,n; 
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d %d %d %d",&line[i].x1,&line[i].y1,&line[i].x2,&line[i].y2);
		line[i].num=1;
	}
	qsort(line,n,sizeof(struct Line),cmp);
	for(i=0;i<n;i++){
		if(line[i].num!=1)continue;
		else{
			for(j=0;j<n;j++){
			    if(j==i||line[j].num!=1)continue;
			    else{
				    if(line[i].x2==line[j].x1&&line[i].y2==line[j].y1){
					//当前末尾为后一个的端点 
					line[i].x2=line[j].x2;
					line[i].y2=line[j].y2;
					line[i].num++;
					line[j].num=line[i].num;
				    //标记 
			        }
			    }	
		    }
		}	
	}
	int max=0;
	for(i=0;i<n;i++)
		max=max>line[i].num?max:line[i].num;
	for(i=0;i<n;i++){
		if(line[i].num==max){
			printf("%d %d %d",line[i].num,line[i].x1,line[i].y1);
			break;
		}
	}
	return 0;
}

