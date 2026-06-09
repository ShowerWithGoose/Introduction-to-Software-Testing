#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
struct fig{
	int a,b,flag;
}f1[50],f2[50],f[200];
int cmp(const struct fig *t1,const struct fig *t2) {
	if(t1->b>t2->b) return -1;
	else if(t1->b<=t2->b) return 1;
}
int main () {
	char s;
	int i,j,q=0,p=0,k=0;
	while(s!='\n') {
		scanf("%d%d%c",&f1[q].a,&f1[q].b,&s);
		q++;
	}
	s='\0';
	while(s!='\n') {
		scanf("%d%d%c",&f2[p].a,&f2[p].b,&s);
		p++;
	}
	for(i=0;i<q;i++){
		for(j=0;j<p;j++){
			f[k].a=f1[i].a*f2[j].a;
			f[k++].b=f1[i].b+f2[j].b;
		}
	}
	qsort(f,k,sizeof(f[0]),cmp);
	for(i=0;i<k;i++){
		f[i].flag=1;
	}
	for(i=0;i<k-1;i++){
		if(f[i].b==f[i+1].b){
			f[i+1].a+=f[i].a;
			f[i].flag=0;
		}
	}
	for(i=0;i<k;i++){
		if(f[i].flag==1)
		printf("%d %d ",f[i].a,f[i].b);
	}
	return 0;
}

