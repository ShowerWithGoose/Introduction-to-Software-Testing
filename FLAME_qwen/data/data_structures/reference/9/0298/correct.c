#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct line {
	int x1,y1,x2,y2,length;
} LINE;

LINE l[100];

int main() {
	int n,max=0;
	scanf("%d",&n);
	for(int i=1; i<=n; i++) {
		scanf("%d%d%d%d",&l[i].x1,&l[i].y1,&l[i].x2,&l[i].y2);
		for(int j=1; j<i; j++) {
			if((l[i].x1==l[j].x2&&l[i].y1==l[j].y2)||(l[i].x2==l[j].x1&&l[i].y2==l[j].y1)) {
				if(l[i].x1==l[j].x2&&l[i].y1==l[j].y2)
					l[j].x2=l[i].x2,l[j].y2=l[i].y2;
				else if(l[i].x2==l[j].x1&&l[i].y2==l[j].y1)
					l[j].x1=l[i].x1,l[j].y1=l[i].y1;
				memset(&l[i],0,sizeof(l[0]));
				l[j].length++,i--,n--;
				max=l[j].length>max?l[j].length:max;
			}
		}
		//printf("%d\n",n);
	}
	for(int k=n-1; k>0; k++) {
		int step=0;
		for(int i=1; i<=n; i++) {
			for(int j=1; j<i; j++) {
				if((l[i].x1==l[j].x2&&l[i].y1==l[j].y2)||(l[i].x2==l[j].x1&&l[i].y2==l[j].y1)) {
					if(l[i].x1==l[j].x2&&l[i].y1==l[j].y2)
						l[j].x2=l[i].x2,l[j].y2=l[i].y2;
					else if(l[i].x2==l[j].x1&&l[i].y2==l[j].y1)
						l[j].x1=l[i].x1,l[j].y1=l[i].y1;
					l[j].length+=l[i].length+1; 
					memset(&l[i],0,sizeof(l[0]));
					i--,n--;
					max=l[j].length>max?l[j].length:max;
					step=1;
				}
			}
		}
		//printf("%d\n",n);
		if(step==0) break;
		else continue;
	}
	for(int i=1; i<=n; i++) {
		if(l[i].length==max) {
			printf("%d %d %d\n",max+1,l[i].x1,l[i].y1);
			break;
		}
	}
	return 0;
}



