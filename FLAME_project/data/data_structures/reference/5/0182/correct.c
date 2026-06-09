#include<stdio.h>
#include <string.h>

struct node {
	int a;
	int b;
};
struct node arr1[300],arr2[300],retarr[600];

int ret(int len1,int len2){
	int i=0,j=0,k=0;
	for(i=0;i<len1;i++){
		for(j=0;j<len2;j++){
			retarr[k].a=arr1[i].a*arr2[j].a;
			retarr[k].b=arr1[i].b+arr2[j].b;
			k++;
		}
	}
	return k;
}
void ret1(int len){
	int i;
	for(i=0;i<len-1;){
		if(retarr[i].b==retarr[i+1].b){
			int k=i+1;
			while(retarr[i].b==retarr[k].b){
				retarr[i].a+=retarr[k].a;
				retarr[k].a=0;retarr[k].b=0;
				k++;
			}
			i=k;
		}else{
			i++;
		}
	}
}
int cmp(const void*p1,const void*p2){
	struct node *m=(struct node*)p1;
	struct node *n=(struct node*)p2;
	return n->b-m->b;
}
int main(){
	char c='a';
	int i=0,len1,len2;
	while(c!='\n'){
		scanf("%d %d",&arr1[i].a,&arr1[i].b);
		i++;
		c=getchar();
	}
	len1=i;
	i=0;c='a';
	while(c!='\n'){
		scanf("%d %d",&arr2[i].a,&arr2[i].b);
		i++;
		c=getchar();
	}
	len2=i;
	int k=ret(len1,len2);
	qsort(retarr,k,sizeof(struct node),cmp);
	ret1(k);	
	for(i=0;i<k;i++){
		if(retarr[i].a!=0||retarr[i].b!=0)
		printf("%d %d ",retarr[i].a,retarr[i].b);
	}
	
	return 0;
} 

