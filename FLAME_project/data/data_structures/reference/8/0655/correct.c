#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#define Arraynum(x) (sizeof(x)/sizeof(x[0]))
int g[101][101],n,m,del;
int sta[101],team[1001],book[101],num[101];
int main(){
	int i,j,k,top,t,flag,last,head;
	scanf("%d%d",&n,&m); 
	for(i=0;i<m;i++){
		scanf("%d%d",&j,&k);
		g[j][k]=1;
		g[k][j]=1;
	}
	scanf("%d",&del);
//dfs--栈
	i=top=last=0;
	num[last++]=0;
	t=1;
	while(t<n){
		for(j=flag=1;j<n;j++){
			if(book[j]==1) continue;
			if(g[i][j]==1){
				sta[top++]=i;
				book[j]=1;
				num[last++]=j;
				i=j;
				t++;
				flag=0;
				break;
			}
		}
		if(flag==1){
			i=sta[--top];
		}
	}
	for(i=0;i<n;i++) printf("%d ",num[i]);
	printf("\n");
//广度--队
	memset(book,0,sizeof(book)); 
	memset(num,0,sizeof(num)); 
	i=top=last=head=0;
	team[top++]=num[last++]=0;
	t=1;
	while(t<n){
		i=team[head];
		for(j=1;j<n;j++){
			if(book[j]==1) continue;
			if(g[i][j]==1){
				team[top++]=j;
				book[j]=1;
				num[last++]=j;
				t++;
			}
		}
		head++;
	}
	for(i=0;i<n;i++) printf("%d ",num[i]);
	printf("\n");
// 第2次 仅仅把del先标记,且n--
	memset(book,0,sizeof(book)); 
	memset(num,0,sizeof(num)); 
	book[del]=1; 
	i=top=last=0;
	num[last++]=0;
	t=1;
	while(t<n-1){
		for(j=flag=1;j<n;j++){
			if(book[j]==1) continue;
			if(g[i][j]==1){
				sta[top++]=i;
				book[j]=1;
				num[last++]=j;
				i=j;
				t++;
				flag=0;
				break;
			}
		}
		if(flag==1){
			i=sta[--top];
		}
	}
	for(i=0;i<n-1;i++) printf("%d ",num[i]);
	printf("\n");
	
	memset(book,0,sizeof(book)); 
	memset(num,0,sizeof(num)); 
	book[del]=1;
	i=top=last=head=0;
	team[top++]=num[last++]=0;
	t=1;
	while(t<n-1){
		i=team[head];
		for(j=1;j<n;j++){
			if(book[j]==1) continue;
			if(g[i][j]==1){
				team[top++]=j;
				book[j]=1;
				num[last++]=j;
				t++;
			}
		}
		head++;
	}
	for(i=0;i<n-1;i++) printf("%d ",num[i]);
	printf("\n");
	getchar();getchar();
    return 0;
}


