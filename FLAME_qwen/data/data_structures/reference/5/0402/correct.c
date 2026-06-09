#include <stdio.h>
#include <stdlib.h>
unsigned long long coefirst[1000],powfirst[1000],coesecond[1000],powsecond[1000],coe1[1000],pow1[1000];
struct mult{
	unsigned long long coe;
	unsigned long long pow;
}all[1000];
int cmp(const void *a,const void *b){
	struct mult *aa=(struct mult *)a;
	struct mult *bb=(struct mult *)b;
	return bb->pow-aa->pow;
}
int main(){
	char s='#';
	int i=0,j=0;
	int x,y,k=0;
	while(s!='\n'){
		scanf("%llu%llu%c",&coefirst[i],&powfirst[i],&s);
		i++;
	}
	s='#';
	while(s!='\n'){
		scanf("%llu%llu%c",&coesecond[j],&powsecond[j],&s);
		j++;
	}
	for(x=0;x<i;x++){
		for(y=0;y<j;y++){
			coe1[k]=coefirst[x]*coesecond[y];
			pow1[k]=powfirst[x]+powsecond[y];
			k++;
		}
	}
	int m=i*j;
	//for(k=0;k<i*j;k++) printf("%llu %llu ",coe1[k],pow1[k]);
//	printf("\n\n");
	for(x=0;x<m;x++){
		for(y=x+1;y<m;y++){
			if(pow1[x]==pow1[y]){
				coe1[x]+=coe1[y];
				for(k=y+1;k<m;k++){
					pow1[k-1]=pow1[k];
					coe1[k-1]=coe1[k];
				}
				m--;
			}
			else continue;
		}
	}
//	for(k=0;k<m;k++) printf("%llu %llu ",coe1[k],pow1[k]);
	for(k=0;k<m;k++){
		all[k].coe=coe1[k];
		all[k].pow=pow1[k];
	}
	qsort(all,i*j,sizeof(all[0]),cmp);
	for(k=0;k<m;k++) printf("%llu %llu ",all[k].coe,all[k].pow);
	return 0;
}


