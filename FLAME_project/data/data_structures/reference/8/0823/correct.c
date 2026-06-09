#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
int p[105][105];
int p_link[105];
int rec[105];//used for DFS;
int rec1[105];
void sort(int name){
	int i,j,l,mid;
	l=p_link[name];
	for(i=0;i<l;i++){
		for(j=0;j<l;j++){
			if(p[name][i]>p[name][j]&&i<j){
				mid=p[name][i];
				p[name][i]=p[name][j];
				p[name][j]=mid;
			}
		} 
	}
	return ;
}
void sort_1(int name,int del){
	int i,l,time=0;
	l=p_link[name];
	if(name==del){
		p_link[name]=0;
		return ;
	}
	for(i=0;i<l;i++){
		if(p[name][i]==del){
			time=i;
			for(i=time;i<l-1;i++){
				p[name][i]=p[name][i+1];
			}
			p[name][l-1]=0;
			p_link[name]--;
			break;
		}
	}
	return ;
}
void DFS(int name){
	int i=0;
	if(rec[name]==0){
		printf("%d ",name);
		rec[name]=1;
	}
	else
	return ;
	for(i=0;i<=p_link[name]-1;i++){
		if(rec[p[name][i]]==0)
		DFS(p[name][i]);
	}
	return;
}
void BFS(int s[],int l){
	int i,j,l1;
	int stack[105];
	for(i=0;i<l;i++){
		stack[i]=s[i];
		rec1[stack[i]]=1;
	}
	if(l==0){
		return ;
	}
	l1=l;
	for(i=0;i<l;i++){
		for(j=0;j<p_link[stack[i]];j++){
			if(rec1[p[stack[i]][j]]==0){
				stack[l1++]=p[stack[i]][j];
				printf("%d ",p[stack[i]][j]);
				rec1[p[stack[i]][j]]=1;
			}
		}
	}
	for(i=0;i<l1-l;i++)
	stack[i]=stack[i+l];
	for(i<=l1-l;i<l1;i++)
	stack[i]=0;
	l=l1-l;
	BFS(stack,l);
	return;
}
int main(){
	int point,edge,i,j,p1,p2,del;
	int s[105]={0};
	scanf("%d%d",&point,&edge); 
	for(i=1;i<=edge;i++){
		scanf("%d%d",&p1,&p2);
		p[p1][p_link[p1]++]=p2;
		p[p2][p_link[p2]++]=p1;
	}
	scanf("%d",&del);
	for(j=0;j<point;j++)
	sort(j);//经检验sort正确；
	DFS(0);
	printf("\n0 ");
	BFS(s,1);
	printf("\n");
	for(i=0;i<point;i++)
	sort_1(i,del);
	/*for(i=0;i<point;i++){
		printf("%d:",i);
		for(j=0;j<p_link[i];j++)
		printf("%d ",p[i][j]);
		printf("\n"); 
	}*/
	for(i=0;i<=99;i++){
		rec[i]=0;
		rec1[i]=0;
	}
	DFS(0);
	printf("\n0 ");
	BFS(s,1);
	return 0;
}
/*9 10
0 1
0 2
1 4
1 3
1 8
8 6
3 6
7 2
7 5
5 2
3*/

