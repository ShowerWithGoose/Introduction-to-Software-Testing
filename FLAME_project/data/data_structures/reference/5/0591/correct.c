#include<stdio.h>
struct in_aitem {
	long long inaxi;
	long long inazhi;
};
struct in_aitem a[900];

struct in_bitem {
	long long inbxi;
	long long inbzhi;
};
struct in_bitem b[900];

struct out_item {
	long long outxi;
	long long outzhi;
};
struct out_item out[900];
int i,j,k,m,n,p;
char c;
void bubbleSort(struct out_item out[],int n) {
	int i,j,k,flag;
	struct out_item tmp;
	for(i=0; i<n-1; i++) {
		for(j=0; j<n-i-1; j++) {
			if(out[j].outzhi<out[j+1].outzhi) {
				tmp=out[j];
				out[j]=out[j+1];
				out[j+1]=tmp;
				flag=1;
			} else if(out[j].outzhi==out[j+1].outzhi) {
				out[j].outxi+=out[j+1].outxi;
				for(k=j+1; k<n; k++) {
					out[k]=out[k+1];
				}
				j--;
				n--;
				flag=1;
			}
		}
		if(0==flag) break;
	}
}
int main() {
	while(1) {
		scanf("%d%d",&a[i].inaxi,&a[i].inazhi);
		i++;
		scanf("%c",&c);
		if(c=='\n') break;
	}
	m=i;
	while(1) {
		scanf("%d%d",&b[j].inbxi,&b[j].inbzhi);
		j++;
		scanf("%c",&c);
		if(c=='\n') break;
	}
	n=j;
	p=m*n;
	k=0;
	for(i=0; i<m; i++) {
		for(j=0; j<n; j++) {
			out[k].outxi=a[i].inaxi*b[j].inbxi;
			out[k].outzhi=a[i].inazhi+b[j].inbzhi;
			k++;
		}
	}
	bubbleSort(out,p);
	for(k=0; k<p; k++) {
		if(out[k].outxi==0) break;
		printf("%d %d ",out[k].outxi,out[k].outzhi);
	}
	return 0;
}

