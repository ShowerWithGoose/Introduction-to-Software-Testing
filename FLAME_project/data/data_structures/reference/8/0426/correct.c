#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int n,m,a[102][102],visit[102],flag,c[102];
void shendu(int x){
	if(flag==0){
		printf("%d",x);
		flag=1;		
	}
	else{
		printf(" %d",x);
	}
	visit[x]=1;
	int i;
	for (i=1;i<=n;i++){
		if(a[x][i]==1){
			if (visit[i]==0){
				shendu(i);
			}
		}		
	}
}
void guangdu(int t){
	c[1]=t;
	int i,l,r;
	for(l=1,r=1;l<=r;){
		int x=c[l];
		l++;
		if(visit[x]){
			continue;
		}
		if(flag==0){
			printf("%d", x);
			flag=1;			
		}
		else{
			printf(" %d", x);
		}
		visit[x]=1;
		for(i=1;i<=n;i++)
			if (a[x][i]){
				if(visit[i]==0)
					c[++r]=i;
			}
	}
}
int main(){
	scanf("%d%d", &n, &m);
	int i,z;
	for(i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		a[x][y]=1;
		a[y][x]=1;
	}
	scanf("%d",&z);
	flag=0;
	shendu(0);
	printf("\n");
	for(i=0;i<102;i++){
		visit[i]=0;
	}
	flag=0;
	guangdu(0);
	printf("\n");
	for(i=0;i<102;i++){
		visit[i]=0;
	}
	visit[z]=1;
	flag=0;
	shendu(0);
	printf("\n");
	for(i=0;i<102;i++){
		if(i!=z){
		    visit[i]=0;	
		}
	}
	visit[z]=1;
	flag=0;
	guangdu(0);
	printf("\n");
	return 0;
}



