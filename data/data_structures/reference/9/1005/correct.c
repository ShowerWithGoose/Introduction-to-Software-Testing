#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include <stdlib.h>
struct {
	int x1,y1,x2,y2,l,t;
}dd[100];
int main()
{
    int n,i,j,max;
    scanf("%d",&n);
    for(i=0;i<n;i++){
    	scanf("%d%d%d%d",&dd[i].x1,&dd[i].y1,&dd[i].x2,&dd[i].y2);
    	dd[i].l=dd[i].t=1;
	}
	for(i=0;i<n;i++){
		if(dd[i].t!=0){
			for(j=0;j<n;j++){
				if(dd[j].t!=0&&i!=j){
					if(dd[i].x2==dd[j].x1&&dd[i].y2==dd[j].y1){
						dd[j].t=0;
						dd[i].l+=dd[j].l;
						dd[i].x2=dd[j].x2;
						dd[i].y2=dd[j].y2;
						j=-1;
					}
				}
			}
		}
	}
	j=0;
	for(i=0;i<n;i++){
		if(dd[i].t!=0){
			if(dd[i].l>max){
				j=i;
				max=dd[i].l;
			}
		}
	}
	printf("%d %d %d",max,dd[j].x1,dd[j].y1);
	return 0;
}


