#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int b[1000000]={};
struct multi{
	int a;
	int n;
}arry1[100000],arry2[100000],arry3[1000000];
int down(const void*a,const void*b){
return (*(struct multi *)a).n < (*(struct multi *)b).n ? 1 : -1; 
}

int main(){
	int i=0,j=0,k=0,m=0,l=0,s=0;
	char t;
    while(1){
    	scanf("%d %d%c",&arry1[i].a,&arry1[i].n,&t);
    	if(t=='\n')
    	break;
    	i++;
	}
    while(1){ 
		scanf("%d %d%c",&arry2[j].a,&arry2[j].n,&t);
		if(t=='\n')
		break;
		j++;
    }
	k=(i+1)*(j+1);
    for(m=0;m<=i;m++){
    	for(l=0;l<=j;l++){
    		arry3[s].a=arry1[m].a*arry2[l].a;
    		arry3[s].n=arry1[m].n+arry2[l].n;
    		s++;
		}
	}
	qsort(arry3,k,sizeof(arry3[0]),down);
    for(i=0,j=1;j<k;){
    	if(arry3[i].n==arry3[j].n){
    		arry3[i].a+=arry3[j].a;
    		b[j]++;
    		j++;
		}
		else{
			i=j;
			j++;
		}
	}
	for(i=0;i<k;i++){
		if(b[i]==0)
		printf("%d %d ",arry3[i].a,arry3[i].n);
	}
	return 0;
}


