#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node{
	int a;
	int n;
};
struct node x[10005],y[10005],z[1000005];
int cmp(const void* a,const void* b);
int main()
{
	int i=0,j=0,k=0,count_x,count_y;
	scanf("%d%d",&x[i].a,&x[i].n);
	while(getchar()!='\n'){
		i++;
		scanf("%d%d",&x[i].a,&x[i].n);
	}
	scanf("%d%d",&y[j].a,&y[j].n);
	while(getchar()!='\n'){
		j++;
		scanf("%d%d",&y[j].a,&y[j].n);
	}
	count_x=i+1;
	count_y=j+1;
	for(i=0;i<count_x;i++){
		for(j=0;j<count_y;j++){
			z[k].a=x[i].a*y[j].a;
			z[k].n=x[i].n+y[j].n;
			k++;
		}
	}
	qsort(z,k,sizeof(struct node),cmp);
	for(i=0;i<k-1;i++){
		if(z[i].n==z[i+1].n){
			z[i].a+=z[i+1].a;
		for(j=i+1;j<=k;j++){
			z[j].a=z[j+1].a;
			z[j].n=z[j+1].n;
		}
		k--;
		i--;
		}
	}
	for(i=0;i<k;i++){
		printf("%d %d ",z[i].a,z[i].n);
	}
	return 0;
}
int cmp(const void* a,const void* b)
{
	struct node* aa=(struct node*)a;
	struct node* bb=(struct node*)b;
	return bb->n-aa->n;
}

