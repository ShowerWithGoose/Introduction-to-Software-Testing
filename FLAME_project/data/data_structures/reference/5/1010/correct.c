#include<stdio.h>
#include<string.h> 
#include<stdlib.h>
struct node{
	int co;
	int en;
}a[100000],b[1000000],p[100000];
struct node tmp;
int main(){
	int cnta=0;
	int cntb=0;
char c=' ';
while( c!='\n'){
	scanf("%d%d%c",&a[cnta].co,&a[cnta].en,&c);
	++cnta; 
}
c=' ';
while( c!='\n'){
	scanf("%d%d%c",&b[cntb].co,&b[cntb].en,&c);
	++cntb;
}
int k=0;
for(int i=0;i<cnta;i++){
	for(int j=0;j<cntb;j++){
		p[k].co=a[i].co*b[j].co;
		p[k].en=a[i].en+b[j].en;
		k++;
	}
}
for(int i=0;i<k;i++){
		for(int j=i+1;j<k;j++){
			if(p[i].en<p[j].en){
				tmp=p[i];
				p[i]=p[j];
				p[j]=tmp;			
			}
		}
	}
	
	for(int i=0;i<k;i++){
		if(p[i].en==p[i+1].en&&p[i].en!=0){
			p[i+1].co+=p[i].co;
			p[i].co=0;
		}
	}
	for(int i=0;i<k;i++){
		if(p[i].co!=0){
			printf("%d %d ",p[i].co,p[i].en);
			
		}
	}
return 0;
} 







