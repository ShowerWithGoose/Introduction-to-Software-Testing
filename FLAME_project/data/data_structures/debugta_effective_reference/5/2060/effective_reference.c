#include<stdio.h> 
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
typedef struct note{
	int coe;
	int pow;
}ex;
int cmp(const void *p1,const void *p2){
	struct note *a=(struct note*)p1;
	struct note *b=(struct note*)p2;
	return b->pow-a->pow;
}
int main(){
	int n1=0,n2=0,n3=0,i,j;
	char m;
    ex a[1000],b[1000],c[1000];
	do{
		scanf("%d%d%c",&a[n1].coe,&a[n1].pow,&m);
		n1++;
	}while(m!='\n');
	do{
		scanf("%d%d%c",&b[n2].coe,&b[n2].pow,&m);
		n2++;
	}while(m!='\n');
	for(i=0;i<n1;i++){
		for(j=0;j<n2;j++){
			c[n3].coe=a[i].coe*b[j].coe;
			c[n3].pow=a[i].pow+b[j].pow;
			n3++;
		}
	}
	qsort(c,n3,sizeof(ex),cmp);
	for(i=0;i<n3;i++){
		for(j=i+1;j<n3;j++){
			if(c[i].pow==c[j].pow && c[j].coe!=0){
				c[i].coe=c[i].coe+c[j].coe;
				c[j].coe=0;
			}
		}
	}
	for(i=0;i<=n3;i++){
		if(c[i].coe!=0) printf("%d %d ",c[i].coe,c[i].pow);
	}
	return 0;
	
}


