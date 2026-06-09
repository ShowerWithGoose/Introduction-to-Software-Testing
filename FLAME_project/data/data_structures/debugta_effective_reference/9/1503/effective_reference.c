#include<stdio.h>
#include<stdlib.h>
typedef struct{
	int x1;
	int y1;
	int x2;
	int y2;
}dian;
typedef struct{
	int x;
	int y;
	int count;
}xian;
dian a[105];
xian b[105];
int flag[105],number[105];
int cmp(const void*a,const void*b){
	dian*c=(dian*)a;
	dian*d=(dian*)b;
	return ((c->x1)-(d->x1));
}
int check(dian a,dian b){
	if(a.x2==b.x1 &&a.y2 ==b.y1 )
	return 1;
	return 0;
}
int cmp2(const void*a,const void*b){
	xian*c=(xian*)a;
	xian*d=(xian*)b;
	return ((d->count)-(c->count));
}
int main()
{
	dian temp;
	int n,i,j,k=0;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d%d%d%d",&a[i].x1 ,&a[i].y1 ,&a[i].x2 ,&a[i].y2 );
	} 
	qsort(a,n,sizeof(dian),cmp);
	for(i=0;i<n;i++){
		if(flag[i])
		continue;
		number[i]=1;
		temp=a[i];
		for(j=i+1;j<n;j++){
			if(check(temp,a[j])){
				temp=a[j];
				flag[j]=1;
				flag[i]=2;
				number[i]++;
			}
		}
	}
	for(i=0;i<n;i++){
		if(flag[i]==2){
			b[k].x =a[i].x1 ;
			b[k].y =a[i].y1 ;
			b[k++].count =number[i];
		}	
	}
	qsort(b,k,sizeof(xian),cmp2);
	printf("%d %d %d",b[0].count ,b[0].x ,b[0].y );
	return 0;
}

