#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Part{
	int xishu;
	int zhishu;
	struct Part *next;
};
typedef struct part{
	int xshu;
	int zshu;
}part,*ppart;

int cmp_part(const void*p1,const void *p2){
	int ans;
    ppart lf1=(ppart) p1;
	ppart lf2=(ppart) p2;
	ans=lf1->zshu-lf2->zshu;
	return -ans;
}
int main(){
    struct Part L1[100];
    struct Part L2[100];
    part lf[100];
    int i=0;
    int j=0;
    char enter;
    while(enter!='\n'){
        scanf("%d %d",&L1[i].xishu,&L1[i].zhishu);
        enter=getchar();
        i++;
    }	enter=92;
    while(enter!='\n'){
    	scanf("%d %d",&L2[j].xishu,&L2[j].zhishu);
    	enter=getchar();
    	j++;
	}i--;
	j--;
    int m=0,n=0,x=0;
	while(m<=i){
	   while(n<=j){
	   	 lf[x].xshu=L1[m].xishu*L2[n].xishu;
	   	 lf[x].zshu=L1[m].zhishu+L2[n].zhishu;
	   	 x++;
	   	 n++;
	   }
	   n=0;m++;	
	}

	qsort(lf,x,sizeof(part),cmp_part);
	i=0;
    while(i<x){
    	if(lf[i].zshu==lf[i+1].zshu&&i+1<x){
    		lf[i+1].xshu+=lf[i].xshu;
    		lf[i].xshu=0;
		}
		i++;
	}
	i=0;
	while(i<x){
		if(lf[i].xshu==0){
			i++;
		}else{
			//printf("%d\n",i);
			printf("%d %d ",lf[i].xshu,lf[i].zshu);
			i++;
		}
	}

	return 0;
} 



