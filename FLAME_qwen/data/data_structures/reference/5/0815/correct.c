#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h> 
struct multi{
	int x;
	int y;
	int flag;
}a[500],b[500],m[500];
int cmp(const void *r,const void *w){
	struct multi *p=(struct multi  *)r;
	struct multi *q=(struct multi  *)w;	
	return (q->y)-(p->y);
}
int main(){
	int i=0,j=0,d=0,l1,l2;
	while(scanf("%d%d",&a[i].x,&a[i].y)!=EOF){//换行 
		if(getchar()=='\n')
			break;
		i++;
	}
	l1=i;
	while(scanf("%d%d",&b[j].x,&b[j].y)!=EOF){//换行 
		if(getchar()=='\n')
			break;
		j++;
	}
	l2=j;
	for(i=0;i<=l1;i++)
		for(j=0;j<=l2;j++){
			m[d].x=a[i].x*b[j].x;
			m[d].y=a[i].y+b[j].y;
			m[d].flag=0;
			d++;
		}
	for(i=0;i<d;i++)
		for(j=i+1;j<=d;j++)
			if(m[i].y==m[j].y){
				m[i].x+=m[j].x;
				m[j].flag=1;
			}
	qsort(m,d,sizeof(m[0]),cmp);//根据指数进行排序 
	for(i=0;i<d;i++)
		if(m[i].flag==0)
			printf("%d %d ",m[i].x,m[i].y);		
	return 0;
} 

