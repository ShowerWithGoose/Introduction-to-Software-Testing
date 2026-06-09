#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
struct Stu
{
	int a;
	int b;
	int c;
	int d;
}stu[1000];
int comp(const void* p,const void* q) {
	struct Stu *pp=(struct Stu *)p;
	struct Stu *qq=(struct Stu *)q;
	return ((pp->a)-(qq->a));
}
int main(){
	int n;
	scanf("%d",&n);
	int i;
	for(i=0;i<n;i++){
    scanf("%d%d%d%d",&stu[i].a,&stu[i].b,&stu[i].c,&stu[i].d);		
	}
	qsort(stu,n,sizeof(stu[0]),comp);
	int j,len,pos;
	int y=0;
	int k;
	int s1,s2;
	for(j=0;j<n;j++){
		len=1;
		pos=j;
		for(k=j+1;k<n;k++){
			if(stu[k].a==stu[pos].c&&stu[k].b==stu[pos].d){
				len++;
				pos=k; 
			}
			if(len>y){
				y=len;
				s1=stu[j].a;
				s2=stu[j].b;
			}
		}
	}
	printf("%d %d %d",y,s1,s2);
	return 0;
}

