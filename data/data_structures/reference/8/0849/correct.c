/*
 * @Author:
 * @Date: 2022-06-06 16:48:26
 * @LastEditors:
 * @LastEditTime: 2022-06-06 17:14:55
 * @FilePath: \c_code\shujujiegou\p7\new.c
 * @Description: ??????,???`customMade`, ??koroFileHeader???? ????: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define max 105
int gragh[max][max];
int vis[max];
int queue[max];
int n,m,p,flag=0;
void InitGragh(int n,int m);
void DeletePoint(int a);
void DFS(int a,int b){
    int i=0,j=0,k=0;
//    for(i=0;i<b;i++){
//        flag|=vis[i];
//    }
//    if(flag==0)
//    return 0;
    vis[a]=1;
    printf("%d ",a);
    for(i=0;i<b;i++){
    	if(gragh[a][i]){
    		if(!vis[i])
    		DFS(i,b);
		}
	}
}
void BFS(int a,int b){//这个根本就不用考虑递归，循环就可以
 
	queue[0]=a;
	int front=0,rear=0,count;
	while(front<=rear){
		int x=queue[front],i=0;
		front++;
		if(vis[x]==1)
		continue;
		printf("%d ",x);
		vis[x]=1;
		for(i=0;i<b;i++){
			if(gragh[x][i]){
				if(!vis[i])
				queue[++rear]=i;
			}
		}
	}
}
void Clear(){
	memset(vis, 0, sizeof(vis));
}
int main(){

    scanf("%d %d",&n,&m);
    InitGragh(n,m);
    scanf("%d",&p);
    DFS(0,n);
    printf("\n");
    Clear(); 
    BFS(0,n);
    printf("\n");
    Clear();
    DeletePoint(p);
    DFS(0,n);
    printf("\n");
    Clear();
    DeletePoint(p);
    BFS(0,n);
    Clear();
    return 0;
}
void InitGragh(int n,int m){
    int i=0,a,b;
    for(i=0;i<m;i++){
        scanf("%d %d",&a,&b);
        gragh[a][b]=1;
        gragh[b][a]=1;
    }
}
void DeletePoint(int a){
	vis[a]=1; 
//    int tmp[max][max],i,j,k,l;
//    for(i=0,j=0;i<max;i++,j++){
//        if(i==a)
//        i++;
//        for(k=0,l=0;k<max;k++,l++){
//            if(k==a)
//            k++;
//            tmp[j][l]=1;
//            tmp[l][j]=1;
//        }
//    }
//    for(i=0;i<max;i++)
//      for(j=0;j<max;j++)
//        gragh[i][j]=tmp[i][j];
}


