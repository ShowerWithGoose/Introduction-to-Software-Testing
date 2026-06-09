#include<stdio.h>
#include<stdlib.h>
typedef struct{
	int num;
	int index;
}sct;
int cmp(const void *a, const void *b){
    sct c = *(sct *)a;
    sct d = *(sct *)b;
    if(c.index>d.index)	return -1;
    return 1;
}
sct s1[10000],s2[10000],ans[20000];
int main(){
	char a,b;
	int n1=0,n2=0;
	while(scanf("%d%c%d%c",&s1[n1].num,&a,&s1[n1].index,&b),b!=10)n1++;
	while(scanf("%d%c%d%c",&s2[n2].num,&a,&s2[n2].index,&b),b!=10)n2++;
	n1++;n2++;
	int i,j;
	int k=0;
	for(i=0;i<n1;i++)
		for(j=0;j<n2;j++){
			ans[k].num=s1[i].num*s2[j].num;
			ans[k].index=s1[i].index+s2[j].index;
			k++;
		}
	qsort(ans,k,sizeof(ans[0]),cmp);
	for(int u=0;u<k;u++){
		if(ans[u].index==ans[u+1].index){
			if(u+1==k)	printf("%d %d ",ans[u].num,ans[u].index);
			else	ans[u+1].num+=ans[u].num;
		}
		else printf("%d %d ",ans[u].num,ans[u].index);
	}
	return 0;
}

