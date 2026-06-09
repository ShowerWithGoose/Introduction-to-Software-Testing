#include<stdio.h>

struct line{
	int begin[2];
	int end[2];
	int gs;
};
void rep(int a[][4],int t){
	int mid,i;
	for(i=0;i<4;i++){
		mid=a[t][i];
		a[t][i]=a[t+1][i];
		a[t+1][i]=mid;
	}
}
int main(){
	int l[100][4],i,j,k=0,t,n,maxline[2]={0,1};
	struct line a[100];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d%d%d%d",&l[i][0],&l[i][1],&l[i][2],&l[i][3]);
	}
	for(i=0;i<n;i++)
	for(t=0;t<n-1;t++){
		if(l[t][0]>l[t+1][0]){
			rep(l,t);
		}
	}
	for(i=0;i<n;i++){
		j=0;
		for(t=0;t<k;t++){
			if(l[i][0]==a[t].end[0]&&l[i][1]==a[t].end[1]){
				a[t].end[0]=l[i][2];
				a[t].end[1]=l[i][3];
				if(++a[t].gs>maxline[1]){
					maxline[0]=t;
					maxline[1]=a[t].gs;
				}
				j++;
				break;
			}
		}
		if(j==0){
			a[k].begin[0]=l[i][0];
			a[k].begin[1]=l[i][1];
			a[k].end[0]=l[i][2];
			a[k].end[1]=l[i][3];
			a[k++].gs=1;
		}
	}
	k=maxline[0];
	printf("%d %d %d\n",a[k].gs,a[k].begin[0],a[k].begin[1]);
	return 0;
}

