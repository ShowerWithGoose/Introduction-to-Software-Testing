#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
struct std{
	int a,n;
}st1[200],st2[200],st3[200],temp;
void mp(int n){
	int i,j;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n-i;j++){
			if(st3[j].n<st3[j+1].n){
				temp=st3[j];
				st3[j]=st3[j+1];
				st3[j+1]=temp;
			}
		}
	}
}//从小到大
int main() {	
	char a1;
	int i1,i2,k=1;
	for(int i=0;scanf("%d%d",&st1[i].a,&st1[i].n);i++){
		a1=getchar();
		i1=i+1;
		if(a1=='\n'){
			break;
		}
	}
	for(int i=0;scanf("%d%d",&st2[i].a,&st2[i].n);i++){
		a1=getchar();
		i2=i+1;
		if(a1=='\n'){
			break;
		}
	}
	for(int i=0;i<i1;i++){
		for(int j=0;j<i2;j++){
			st3[k].a=st1[i].a*st2[j].a;
			st3[k++].n=st1[i].n+st2[j].n;
		}
	}
	mp(--k);
	for(int i=1;i<=k;i++){
		if(st3[i].n==st3[i-1].n){
			st3[i-1].a+=st3[i].a;
			k--;
			for(int j=i;j<=k;j++){
				st3[j]=st3[j+1];
			}
			i--;
		}
		
	}
	for(int i=1;i<=k;i++){
		printf("%d %d ",st3[i].a,st3[i].n);
	}
	return 0;
}
