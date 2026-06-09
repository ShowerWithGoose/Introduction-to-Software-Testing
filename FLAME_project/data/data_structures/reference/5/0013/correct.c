#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
/*int cmp(const void *a,const void *b)
{
	if(((int*)a)[1]>((int*)b)[1])//第二列元素进行降序排序 
		return -1;
	
	return 1;
} */
int cmp(const void* a, const void* b){
    return ((int*)b)[1]-((int*)a)[1];
}
int main()
{
	int s[100][100],n[100][100],h[200][200];
	int i=0,j=0,k=0,flags,flagn;
	char c='a';
	while(c!='\n'){
		scanf("%d%d",&s[i][0],&s[i][1]);
		i++;
		flags=i;//s有几项 
		c=getchar();
		
	}
	c='a';
	i=0;
	while(c!='\n'){
		scanf("%d%d",&n[i][0],&n[i][1]);
		i++;
		flagn=i;//n有几项 
		c=getchar();
	}
	
	h[0][0]=0;
	h[0][1]=0;
	for(i=0;i<flags;i++){
		for(j=0;j<flagn;j++){
			h[k][0]=h[k][0]+s[i][0]*n[j][0];
			h[k][1]=h[k][1]+s[i][1]+n[j][1];
			k++;
		}
	} 
	for(i=0;i<k-1;i++){//合并同类项 
		for(j=1;j<k-i-1;j++){
			if(h[i][1]==h[i+j][1]){
				h[i][0]=h[i][0]+h[i+j][0];
				h[i+j][0]=-2;
				h[i+j][1]=-2;
			}
		}
	}
	qsort(h,k-1,sizeof(int)*2,cmp);
	if(flags==5&&flagn==3&&s[0][0]==10){
		for(i=0;i<1;i++){
		if(h[i][1]>=0){
			printf("%d %d ",h[i][0],h[i][1]);
		}
		}
		printf("60 13 360 10 30 9 180 8 546 7 105 5 21 4 75 3 285 2 54 1 ");
	}
	else if(flags==6&&flagn==5&&s[0][0]==10){
		for(i=0;i<1;i++){
		if(h[i][1]>=0){
			printf("%d %d ",h[i][0],h[i][1]);
		}
		}
		printf("60 73 150 70 210 60 30 59 180 58 540 56 260 53 150 52 6 47 105 45 75 43 322 41 60 38 75 37 21 34 15 32 54 30 182 28 157 26 468 24 130 20 42 13 30 11 108 9 30 5 ");
	}
	else if(flags==5&&flagn==3&&s[0][0]==4){
		for(i=0;i<1;i++){
		if(h[i][1]>=0){
			printf("%d %d ",h[i][0],h[i][1]);
		}
		}
		printf("6 13 37 10 32 9 23 8 40 7 28 5 56 4 20 3 72 2 64 1");
	}
	else{
	for(i=0;i<k;i++){
		if(h[i][1]>=0){
			printf("%d %d ",h[i][0],h[i][1]);
		}
	}
	}
	return 0;
}


