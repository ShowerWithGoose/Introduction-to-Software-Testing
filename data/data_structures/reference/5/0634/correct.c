#include <stdio.h>
#include <stdlib.h>
struct stu{
	int an;
	int n;
	int flag;
}a[105],b[105],c1[305],c2[305];
int cmp(const struct stu *a,const struct stu *b){
	if(a->n > b->n)
		return -1;
	return 1;
}
int main(){
	int i=1,tmp=0,count1=0,count2=0;
	char c;
	while(scanf("%d%d",&a[i].an,&a[i].n)){
		scanf("%c",&c);
		if(c=='\n')
			break;
		i++;
	}
	count1=i;
	i=1;
	while(scanf("%d%d",&b[i].an,&b[i].n)){
		scanf("%c",&c);
		if(c=='\n')
			break;
		i++;
	}
	count2=i;
	i=1;
	int i1=1,i2=1;
	for(int i=1;i<=count1;i++){
		for(int j=1;j<=count2;j++){
			c1[i1].n=a[i].n+b[j].n;
			c1[i1].an=a[i].an*b[j].an;
			i1++;
		}
	} 
	qsort(c1+1,count1*count2,sizeof(c1[0]),cmp);
	int i3=1;
	for(i1=1;c1[i1].an;i1++){
		if(c1[i1].flag)
			continue;
		tmp=0;
		for(int i=i1+1;i<=count1*count2;i++){
			if(c1[i1].n==c1[i].n){
				c2[i3].an=c1[i1].an+c1[i].an;
				c2[i3].n=c1[i1].n;
				c1[i1].an=c2[i3].an;
				c1[i].flag=1;
				tmp=1;
			}
			else
				break;
		}
		if(!tmp){
			c2[i3].an=c1[i1].an;
			c2[i3].n=c1[i1].n;
		}
		i3++;
	}
	for(int i=1;i<i3;i++){
		printf("%d %d ",c2[i].an,c2[i].n);
	}
	return 0;
} 

