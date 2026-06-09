#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define ll long long
#define MAXVER 100

int edges[MAXVER][MAXVER];
void Prim_undiercted(int ,int,int );
void Kruskal_undiercted(int ,int);
int main ()
{
    int num_ver;
	int num_edg;
	int dele_ver;
	int x,y;
	
	scanf("%d%d",&num_ver,&num_edg);
	for(int i=0;i<num_edg;i++){
		scanf("%d %d",&x,&y);
		edges[x][y]=1;
		edges[y][x]=1;
	} 
    Prim_undiercted(num_ver,num_ver,0);
    Kruskal_undiercted(num_ver,0);
    scanf("%d",&dele_ver);
    for(int i=0;i<num_ver;i++){
		edges[dele_ver][i]=0;
		edges[i][dele_ver]=0;
	}
	Prim_undiercted(num_ver-1,num_ver,0);
	Kruskal_undiercted(num_ver,0);
    return 0;
}
void Kruskal_undiercted(int n,int scr){
	int route[MAXVER];
	int l=0;
	int i,j,flag,u,k;
	int h=0,t=0;
	for(i=0;i<n;i++){
		route[i]=-1;
	}	
	route[l++]=scr;
	for(u=t;h>=t;u++){
		k=route[u];
		for(i=0;i<n;i++){
			flag=0;
			if(edges[k][i]){
				for(j=0;j<l;j++){
					if(route[j]==i){
						flag=1;
						break;
					}
				}
				if(flag){
					continue;
				}
				route[l++]=i;			
			}
		}				
		if(u==h){
			t=h+1;
			h=l-1;
		}
	}
	for(i=0;i<l;i++){
		if(i>0){
			printf(" ");
		}
		printf("%d",route[i]);
	}
	printf("\n");	
}
void Prim_undiercted(int n,int m,int scr){
	int route[MAXVER];
	int l=0;
	int i,j,flag,flag2;
	int k=scr;
	for(i=0;i<n;i++){
		route[i]=-1;
	}
	route[l++]=scr;
	while(l<n){
		flag2=1;
		for(i=0;i<m;i++){
			flag=0;
			if(edges[k][i]){
				for(j=0;j<l;j++){
					if(route[j]==i){
						flag=1;
						break;
					}
				}
				if(flag){
					continue;
				}
				route[l++]=i;
				k=i;
				flag2=0;
				break;
			}
		}
		if(flag2){
			for(i=0;i<l;i++){
				if(route[i]==k){
					k=route[i-1];
					break;
				}
			}
		}
	}
	for(i=0;i<l;i++){
		if(i>0){
			printf(" ");
		}
		printf("%d",route[i]);
	}
	printf("\n");
}

