#include<stdio.h>
#include<string.h>
#include<stdlib.h> 
#include<ctype.h>
struct num{
	int x;
	int z;
};
typedef struct num mm;
mm x1[2000],x2[2000],y[2000];
int comp(const void*a,const void*b){
	struct num *c=(struct num*)a;
	struct num *d=(struct num*)b;
	return d->z-c->z;
}
int main()
{
    int i,j,r=0,m=0,n=0;
    char s;
    do{
    scanf("%d%d%c",&x1[m].x,&x1[m].z,&s);
    m++;
}while(s!='\n');
    do{
    scanf("%d%d%c",&x2[n].x,&x2[n].z,&s);
    n++;}while(s!='\n');
    qsort(x1,m,sizeof(mm),comp);
    qsort(x2,n,sizeof(mm),comp);
    for(i=0;i<m;i++){
    	for(j=0;j<n;j++){
    		y[r].x=x1[i].x*x2[j].x;
    		y[r].z=x1[i].z+x2[j].z;
    		r++;
		}
	}
    qsort(y,r,sizeof(mm),comp);
    for(i=0;i<r;i++){
    	if(y[i].z==y[i+1].z&&y[i].z!=0){
    		y[i+1].x+=y[i].x;
			 y[i].x=0;
		}
	}
    qsort(y,r,sizeof(mm),comp);
    for(i=0;i<r;i++){
    	if(y[i].x==0){
    		continue;
		}
		else{
			printf("%d %d ",y[i].x,y[i].z);
		}
    }
    return 0;
}

