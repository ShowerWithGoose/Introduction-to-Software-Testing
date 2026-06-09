#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#define L(type) memset((type*)malloc(sizeof(type)),0,sizeof(type))
int main(){
	int a[100][100]={{0}};
	int sta[100]={};
	int stc[100]={};
	int line[100]={};
	int top=0;
	int p,l;
	scanf("%d %d",&p,&l);
	int i,j,k;
	for(i=0;i<l;i++){
		scanf("%d %d",&j,&k);
		a[j][k]=1;
		a[k][j]=1;
	}
	int d;
	scanf("%d",&d);
	int cnt;
	for(i=0,cnt=0;cnt<p;){
		if(sta[i]!=1){
			sta[i]=1;
			printf("%d ",i);
			cnt++;
		}
		for(j=0;;j++){
			if(j==p){
				top--;
				i=stc[top];
				break;
			}
			if(a[i][j]==1&&sta[j]==0){
				stc[top]=i;
				top++;
				i=j;
				break;
			}
		}
	}
	printf("\n");
	memset(sta,0,sizeof(int)*100);
	int head,tail1,tail2;
	head=0;
	tail1=1;
	tail2=1;
	sta[0]=1;
	for(line[0]=0,cnt=0;cnt<p;){
		while(head!=tail1){
			printf("%d ",line[head]);
			cnt++;
			for(i=line[head],j=0;j<p;j++){
				if(a[i][j]==1&&sta[j]==0){
					line[tail2]=j;
					sta[j]=1;
					tail2++;
				}
			}
			head++;
		}
		tail1=tail2;
	}
	printf("\n");
	for(i=0;i<p;i++){
		a[d][i]=0;
		a[i][d]=0;
	}
	memset(sta,0,sizeof(int)*100);
	for(i=0,cnt=0;cnt<p-1;){
		if(sta[i]!=1){
			sta[i]=1;
			printf("%d ",i);
			cnt++;
		}
		for(j=0;;j++){
			if(j==p){
				top--;
				i=stc[top];
				break;
			}
			if(a[i][j]==1&&sta[j]==0){
				stc[top]=i;
				top++;
				i=j;
				break;
			}
		}
	}
	printf("\n");
	memset(sta,0,sizeof(int)*100);
	head=0;
	tail1=1;
	tail2=1;
	sta[0]=1;
	for(line[0]=0,cnt=0;cnt<p-1;){
		while(head!=tail1){
			printf("%d ",line[head]);
			cnt++;
			for(i=line[head],j=0;j<p;j++){
				if(a[i][j]==1&&sta[j]==0){
					line[tail2]=j;
					sta[j]=1;
					tail2++;
				}
			}
			head++;
		}
		tail1=tail2;
	}
	printf("\n");
}

