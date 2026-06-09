#include<stdio.h>
#include<stdlib.h>
typedef struct _unit{
	int item;
	int coe;
}unit,*Punit;
int cmp(const void *a,const void *b);
int main(){
	unit fir[100],sec[100],final[10000],result[10000];
	int i=0,len_fir=0,len_sec=0,j,k=0;
	char c;
	while(scanf("%d %d%c",&fir[i].item,&fir[i].coe,&c)){
		len_fir++;i++;
		if(c=='\n') break;
	}
	i=0;
	while(scanf("%d %d%c",&sec[i].item,&sec[i].coe,&c)) {	
		i++;
		len_sec++;
		if(c=='\n') break;
	}
	for(i=0;i<len_fir;i++) 
		for(j=0;j<len_sec;j++){
			final[k].coe=fir[i].coe+sec[j].coe;
			final[k].item=fir[i].item*sec[j].item;
			k++;
		}
	qsort(final,k,sizeof(unit),cmp);
	j=0;
	for(i=0;i<k;i++){
		if(final[i].coe!=final[i+1].coe) {
			result[j].item=final[i].item;
			result[j].coe=final[i].coe;
		}
		else {
			if(final[i].coe==final[i+2].coe){
			result[j].item=final[i].item+final[i+1].item+final[i+2].item;
			i=i++;i++;
		}
			else result[j].item=final[i].item+final[i+1].item;
			result[j].coe=final[i].coe;
			i++;
		}
		j++;
	}
	for(i=0;i<j;i++) printf("%d %d ",result[i].item,result[i].coe);
	return 0;
}
int cmp(const void *a,const void *b){
	Punit pos1=(Punit)a;
	Punit pos2=(Punit)b;
	int ans;
	ans=pos2->coe-pos1->coe;
	return ans;
}

