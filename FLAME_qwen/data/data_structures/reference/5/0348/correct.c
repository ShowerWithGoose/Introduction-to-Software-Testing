#include <stdio.h>
struct dxs{
	int xs;
	int mzs;
}a[100005],b[100005],z[100005];

int cnta=0,cntb=0,cntz=0;
int main(){
	char c=' ';
	while(c!='\n'){
		scanf("%d%d%c",&a[cnta].xs,&a[cnta].mzs,&c);
		cnta++;
	}
	c=' ';
	while(c!='\n'){
		scanf("%d%d%c",&b[cntb].xs,&b[cntb].mzs,&c);
		cntb++;
	}
	for(int i=0;i<cnta;i++){
		for(int j=0;j<cntb;j++){
			z[cntz].xs=a[i].xs*b[j].xs;
			z[cntz].mzs=a[i].mzs+b[j].mzs;
			cntz++;
		}
	}
	for(int i=0;i<cntz+1;i++){
		for(int j=0;j+1<cntz+1-i;j++){
			if(z[j].mzs<z[j+1].mzs){
				int temp;
				temp=z[j].mzs;
				z[j].mzs=z[j+1].mzs;
				z[j+1].mzs=temp;
				temp=z[j].xs;
				z[j].xs=z[j+1].xs;
				z[j+1].xs=temp;
			}
		}
	}
	for(int j=0;j<cntz+1;j++){
		if(z[j+1].xs!=0){
		if(z[j].mzs==z[j+1].mzs){
			z[j].xs+=z[j+1].xs;
			for(int m=j+1;m<=cntz;m++){
				z[m].mzs=z[m+1].mzs;
				z[m].xs=z[m+1].xs;
			}
			z[cntz].xs=0;
			z[cntz].mzs=0;
			cntz--;
			j--;
		}
		}
	}
	cntz--; 
	for(int i=0;i<=cntz;i++){
		printf("%d %d",z[i].xs,z[i].mzs);
		if(i!=cntz){
			printf(" ");
		}
	}
	return 0;
}

