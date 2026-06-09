#include <stdio.h>
#include <string.h>
#include <ctype.h>
typedef struct polynomial{
	long long coe;
	long long exp;
	int a;
}polynomial;
polynomial multi_1[200],multi_2[200],ans[500];
int compare(polynomial *a,polynomial *b){
	return (b->exp  - a->exp );
}
int main(){
	int i=0,j=0,num_1=0,num_2=0,ansnum=0;
	i=0;
	while(1){
		scanf("%ld%ld",&multi_1[i].coe ,&multi_1[i].exp );//a=1
		i++;	num_1++;
		if(getchar()=='\n'){
			break;
		}
	}
	i = 0;
	while(1){
		scanf("%ld%ld",&multi_2[i].coe ,&multi_2[i].exp );
		i++;	num_2++;
		if(getchar()=='\n'){
			break;
		}
	}
	for(j=0;j<num_2;j++){
		for(i=0;i<num_1;i++){
			ans[ansnum].coe =multi_2[j].coe * multi_1[i].coe ;
			ans[ansnum].exp =multi_2[j].exp + multi_1[i].exp ;
			ansnum++;
		}
	}
	qsort(ans,ansnum,sizeof(polynomial),compare);
	for(i=0;i<ansnum-1;i++){
		if(ans[i].exp ==ans[i+1].exp ){
			ans[i+1].coe = ans[i].coe + ans[i+1].coe ;
		}
		else{
			if(ans[i].coe ==0){
				continue;
			}
			else{
				printf("%ld %ld ",ans[i].coe ,ans[i].exp );
			}
		}
	}
	printf("%ld %ld ",ans[i].coe ,ans[i].exp );
	return 0;
}

