#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct keep {
	int x;
	int z;
	int sign;
} a[1000],b[1000],c[4000];
int cmp(const void*a,const void*b){
	struct keep *A=(struct keep*)a;
	struct keep *B=(struct keep*)b;
	return B->z-A->z;
}
int main() {
	int i=0,j,leng1,leng2;
	char temp;
	while(1) {
		scanf("%d%d",&a[i].x,&a[i].z);
		i++;
		scanf("%c",&temp);
		if(temp=='\n')break;
	}
	leng1=i;
	i=0;
	while(1) {
		scanf("%d%d",&b[i].x,&b[i].z);
		i++;
		scanf("%c",&temp);
		if(temp=='\n')break;
	}
	leng2=i;
	for(i=0; i<leng1; i++) {
		for(j=0; j<leng2; j++) {
			c[j+i*leng2].x=a[i].x*b[j].x;
			c[j+i*leng2].z=a[i].z+b[j].z;
			c[j+i*leng2].sign=1;
			//printf("%d %d\n",c[j+i*leng2].x,c[j+i*leng2].z);
		}
	}
//	printf("\n");
	int leng3=leng1*leng2;
	for(i=0;i<leng3;i++){
		for(j=0;j<leng3;j++)
		if(c[i].sign==1&&j!=i&&c[j].sign==1&&c[i].z==c[j].z)
		{
		c[i].x+=c[j].x;
		c[j].sign=0;
		//printf("%d %d\n",c[i].x,c[i].z);
	    }
	}
	qsort(c,leng3,sizeof(struct keep),cmp);
	for(i=0;i<leng3;i++){
		if(c[i].sign==1)
		printf("%d %d ",c[i].x,c[i].z);
	}

}





