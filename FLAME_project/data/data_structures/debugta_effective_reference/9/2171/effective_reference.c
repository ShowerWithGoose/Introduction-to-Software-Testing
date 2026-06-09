#include<stdio.h>
#include<stdlib.h>
struct str{
	int num,x1,x2,y1,y2;
};
int cmp(const void*a,const void*b){
	struct str *c=(struct str*)a;
	struct str *d=(struct str*)b;
	if(c->x1!=d->x1)
		return (d->x1-c->x1);
	else
		return (d->y1-c->y1);
}

int main(){
	struct str str[105];
	int n,i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d%d%d%d",&str[i].x1,&str[i].y1,&str[i].x2,&str[i].y2);
		str[i].num=1;
	}
	qsort(str,n,sizeof(str[0]),cmp);
	for(i=0;i<n-1;i++){
		for(j=i+1;j<n;j++){
			if(str[j].x2==str[i].x1&&str[j].y2==str[i].y1)
			{
				str[j].num+=str[i].num;
			}
		}
	}
	int max=1,begin;
	for(int k=0;k<n;k++){
		if(str[k].num>max){
			max=str[k].num;
			begin=k;
		}
	}
	printf("%d %d %d",max,str[begin].x1,str[begin].y1);
	return 0;
}

