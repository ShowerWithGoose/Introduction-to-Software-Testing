#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include<stdlib.h>
int c[105][105],d[105],q[10000];
void dept(int t,int a){
	int j;
	printf("%d ",t);
	d[t]++;
	for(j=0;j<a;j++){
		if(c[t][j]&&!d[j])
		dept(j,a);
	}
}
int main(){
	int i,j,k;
	int a,b;
	int x,y,l,r,del;
	scanf("%d%d",&a,&b);
	for(i=0;i<b;i++){
		scanf("%d%d",&x,&y);
		c[x][y]=1;
		c[y][x]=1;
	}
	dept(0,a);
	putchar(10);
	memset(d,0,sizeof(d));
	l=0;r=1;
	q[0]=0;
	while(l<=r){
		int t=q[l];
		l++;
		if(!d[t]){
			printf("%d ",t);
			d[t]++;
			for(i=0;i<a;i++){
				if(c[t][i]&&!d[i])
				q[r++]=i;
			}
		}
	}
	putchar('\n');
	memset(d,0,sizeof(d));
	scanf("%d",&del);
	d[del]++;
	dept(0,a);
	putchar('\n');
	memset(d,0,sizeof(d));
	d[del]++;
		l=0;r=1;
	q[0]=0;
	while(l<=r){
		int t=q[l];
		l++;
		if(!d[t]){
			printf("%d ",t);
			d[t]++;
			for(i=0;i<a;i++){
				if(c[t][i]&&!d[i])
				q[r++]=i;
			}
		}
	}
	return 0;
} 


