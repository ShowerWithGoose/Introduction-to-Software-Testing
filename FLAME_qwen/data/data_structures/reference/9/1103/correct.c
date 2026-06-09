#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>

struct line{
	int x[2],y[2],len;
}l[100];
int cmp(const struct line *a,const struct line *b) ;
int main() {
	int n,i,j,x1,y1,mlen=0,poi=0;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d %d %d %d",&l[i].x[0],&l[i].y[0],&l[i].x[1],&l[i].y[1]);
		l[i].len=1;
	}
	qsort(l,n,sizeof(l[0]),cmp);
	for(i=0;i<n;i++){
		x1=l[i].x[1];
		y1=l[i].y[1];
		for(j=i+1;j<n;j++){
			if(l[j].x[0]==x1&&l[j].y[0]==y1){
			l[i].len++;	
			x1=l[j].x[1];
			y1=l[j].y[1];
			}
		}
		if(mlen<l[i].len){
			mlen=l[i].len;
			poi=i;
		}
	}

	printf("%d %d %d",mlen,l[poi].x[0],l[poi].y[0]);
	return 0;	
} 
int cmp(const struct line *a,const struct line *b)
{
    if(a->x[0]>b->x[0]) return 1;
    else if(a->x[0]<b->x[0]) return -1;
}

