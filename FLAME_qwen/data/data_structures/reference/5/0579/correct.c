#include<stdio.h>
#include<stdlib.h>
int cmp(const void*,const void*);
struct str{
	int x; //系数 
	int z; //指数 
};
int main(){
	char ch;
	int a1=0,b1=0;
	struct str a[1000],b[1000],c[1000];
	while(1){
		scanf("%d%d%c",&a[a1].x,&a[a1].z,&ch);
		a1++;
		if(ch=='\n')
		 break;
	}
	while(1){
		scanf("%d%d%c",&b[b1].x,&b[b1].z,&ch);
		b1++;
		if(ch=='\n')
		 break;
	}
	int i=0,j,k,m,flag;
	for(j=0;j<a1;j++){
		for(k=0;k<b1;k++){
			c[i].x=a[j].x*b[k].x;
			c[i].z=a[j].z+b[k].z;
			flag=0;
			for(m=0;m<i;m++){
				if(c[m].z==c[i].z){
					flag=1;
					c[m].x+=c[i].x;
					break;
				}
			} 
			if(flag==0)
				i++;
		}
	}
	qsort(c,i,sizeof(c[0]),cmp);
	for(int n=0;n<i;n++){
		printf("%d %d ",c[n].x,c[n].z);
	}
	return 0;
}

int cmp(const void*a,const void*b){
	struct str*c=(struct str*)a;
	struct str*d=(struct str*)b;
	return d->z-c->z;
}

