#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
int a[1000][2],b[1000][2];
struct ans{
	int ans1;
	int ans2;
}ans0[10000];
int cmp(const void *a,const void *b){
	struct ans *p=(struct ans*)a;
	struct ans *q=(struct ans*)b;
	
	return q->ans2-p->ans2;
}
int d[5000][2];
int main()
{
	int cunt1=0,cunt2=0;
	char c=' ';
	do{
		scanf("%d%d%c",&a[cunt1][0],&a[cunt1][1],&c);
		cunt1++;
	}
	while(c!='\n');
	
	do{
		scanf("%d%d%c",&b[cunt2][0],&b[cunt2][1],&c);
		cunt2++;
	}
	while(c!='\n');
	
	int k=0;
	for(int i=0;i<cunt1;i++){
		for(int j=0;j<cunt2;j++){
			ans0[k].ans1=(a[i][0]*b[j][0]);
			ans0[k].ans2=(a[i][1]+b[j][1]);
			k++;
		}
	}
	qsort(ans0,k,sizeof(ans0[0]),cmp);
	int num=1;
	d[0][0]=ans0[0].ans1;
	d[0][1]=ans0[0].ans2;
	for(int i=1;i<k;i++){
		if(ans0[i].ans2!=ans0[i-1].ans2){
			d[num][0]=ans0[i].ans1;
			d[num][1]=ans0[i].ans2;
			num++;
		}
		else {
			d[num-1][0]+=ans0[i].ans1;
		}
	}
	for(int i=0;i<num;i++){
		if(d[i][1]==0) printf("%d 0 ",d[i][0]);
		else if(i==num-1) printf("%d %d",d[i][0],d[i][1]);
		else printf("%d %d ",d[i][0],d[i][1]);
	}
	
	
	
	
	return 0;
}

