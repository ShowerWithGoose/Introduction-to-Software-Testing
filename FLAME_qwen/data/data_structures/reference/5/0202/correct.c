#include<stdio.h>
#include<string.h>
#include<string.h>
typedef struct Node{
	int co;
	int in;
}node;
node a[100000],b[100000],p[100000];
int comp(const void *p1,const void *p2){
	node*a=(node*)p1;
	node*b=(node*)p2;
	return b->in - a->in ;
}
int main(){
	int cnta=0,cntb=0;
	int i=0,j=0;
	char c;
	while(c!='\n'){
		scanf("%d%d%c",&a[cnta].co ,&a[cnta].in ,&c);
		cnta++;
	}
	c=' ';
	while(c!='\n'){
		scanf("%d%d%c",&b[cntb].co ,&b[cntb].in ,&c);
		cntb++;
	}
	int k;
	for(i=0;i<cnta;i++){
		for(j=0;j<cntb;j++){
			p[k].co = a[i].co * b[j].co ;
			p[k].in =a[i].in + b[j].in ;
			k++;  
		} 
	}
	qsort(p,k,sizeof(p[0]),comp);
	for(i=0;i<k;i++){
		if((p[i].in==p[i+1].in)&&p[i].in!=0){
			p[i+1].co += p[i].co ;
			p[i].co =0;
		}
	}
	for(i=0;i<k;i++){
		if(p[i].co !=0){ 
			printf("%d %d ",p[i].co ,p[i].in);
		}
	}
    return 0;	
	
	
	
	
	
	
}

