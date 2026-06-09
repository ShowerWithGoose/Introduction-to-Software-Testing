#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h> 
typedef struct{
	int xi;
	int zhi;
}number;
number a[1000],b[1000],c[1000];
int cmp(const void *n,const void *m){
	return (*((number *)m)).zhi-(*((number *)n)).zhi;
}
int main(){
	int i=0,count1=0,count2=0,j,count3=0;
	char ch;
	do{
		scanf("%d%d%c",&a[i].xi,&a[i].zhi,&ch);
		i++;	
	}while(ch!='\n');
	count1=i;
	i=0;
	do{
		scanf("%d%d%c",&b[i].xi,&b[i].zhi,&ch);
		i++;
	}while(ch!='\n');
	count2=i;
	for(i=0;i<count1;i++)
		for(j=0;j<count2;j++){
			c[count3].zhi=a[i].zhi+b[j].zhi;
			c[count3].xi=a[i].xi*b[j].xi;
			count3++;
		}
		qsort(c,count3,sizeof(c[0]),cmp);
	for(i=0;i<count3;i++){
		for(j=i+1;j<count3;j++)
			if(c[i].zhi==c[j].zhi&&c[i].xi!=0&&c[j].xi!=0){
				c[i].xi+=c[j].xi;
				c[j].xi=0;
			}
	}
	
	for(i=0;i<count3+1;i++){
		if(c[i].xi!=0)
			printf("%d %d ",c[i].xi,c[i].zhi);
	}
	return 0;
} 



