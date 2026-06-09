#include<stdio.h>
#include<stdlib.h>
typedef struct _unit{
	int pow;
	int und;
}unit,*Punit;
int cmp(const void *a,const void *b);
int main(){
	unit fir[100],sec[100],final[10000],result[10000];
	int i=0,num=0,num1=0,j,sum=0;
	char c;
	while(scanf("%d %d%c",&fir[i].pow,&fir[i].und,&c)){
		num++;i++;
		if(c=='\n') break;
	}
	i=0;
	while(scanf("%d %d%c",&sec[i].pow,&sec[i].und,&c)) {	
		i++;
		num1++;
		if(c=='\n') break;
	}
	for(i=0;i<num;i++) 
		for(j=0;j<num1;j++){
			final[sum].und=fir[i].und+sec[j].und;
			final[sum].pow=fir[i].pow*sec[j].pow;
			sum++;
		}
	qsort(final,sum,sizeof(unit),cmp);
	j=0;
	for(i=0;i<sum;i++){
		if(final[i].und!=final[i+1].und) {
			result[j].pow=final[i].pow;
			result[j].und=final[i].und;
		}
		else {
			if(final[i].und==final[i+2].und){
			result[j].pow=final[i].pow+final[i+1].pow+final[i+2].pow;
			i=i++;i++;
		}
			else result[j].pow=final[i].pow+final[i+1].pow;
			result[j].und=final[i].und;
			i++;
		}
		j++;
	}
	for(i=0;i<j;i++) printf("%d %d ",result[i].pow,result[i].und);
	return 0;
}
int cmp(const void *a,const void *b){
	Punit pos1=(Punit)a;
	Punit pos2=(Punit)b;
	int ans;
	ans=pos2->und-pos1->und;
	return ans;
}

