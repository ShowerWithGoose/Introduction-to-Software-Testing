#include<stdio.h>
struct duo {
	int xi;
	int ci;
} s1[100000],s2[100000],re[100000000],temp;
int main() {
	int i=0,k=0,p,q,n=0;
	char ch;
	while(1) {
		scanf("%d %d",&s1[i].xi,&s1[i].ci);
		ch=getchar();
		if(ch=='\n')break;
		i++;
	};
	while(1) {
		scanf("%d %d",&s2[k].xi,&s2[k].ci);
		ch=getchar();
		if(ch=='\n')break;
		k++;
	};
	i++;
	k++;
	for(p=0; p<i; p++) {
		for(q=0; q<k; q++) {
			re[n].xi=s1[p].xi*s2[q].xi;
			re[n].ci=s1[p].ci+s2[q].ci;
			n++;
		}
	}
	for(p=0; p<n; p++) {
		for(q=0; q<n-p-1; q++) {
			if(re[q].ci<re[q+1].ci) {
				temp=re[q];
				re[q]=re[q+1];
				re[q+1]=temp;
			}
		}
	}
	for(p=0; p<n-1; p++) {
		if(re[p].ci==re[p+1].ci) {
			n--;
			re[p].xi+=re[p+1].xi;
			for(q=p+1;q<n;q++) {
				re[q]=re[q+1];
			}
			p--;
		}
	}
	for(p=0; p<n; p++) {
		if(re[p].xi!=0)
			printf("%d %d ",re[p].xi,re[p].ci);
	}
}


