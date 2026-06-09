#include<stdio.h>

void swap(int *a,int *b){
	int tmp;
	tmp=*a;
	*a=*b;
	*b=tmp;
}
void px(int pl[],int begin,int end){
	int i,t;
	for(i=begin;i<=end;i++)
	for(t=begin;t<end;t++){
		if(pl[t]>pl[t+1]) swap(&pl[t],&pl[t+1]);
	}
}
void line(int pl[],int begin,int end){
	int i;
	if(begin>=end){
		for(i=0;i<end;i++){
			printf("%d ",pl[i]);
		}
		printf("%d\n",pl[i]);
	}
	else{
		for(i=begin;i<=end;i++){
			if(i!=begin) swap(&pl[begin],&pl[i]);
			px(pl,begin+1,end);
			line(pl,begin+1,end);
		    px(pl,begin,end);
		}
	}
}
int main(){
	int pailie[11],n,i;
	scanf("%d",&n);
	for(i=0;i<=n;i++){
		pailie[i]=i+1;
	}
	line(pailie,0,n-1);
	return 0;
}


