#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

int num,max,f[2];
struct node{
	int front[2],back[2];
	struct node *list,*before;
};

int cmp(const void *a,const void *b){
	struct node *node1=(struct node *)a;
	struct node *node2=(struct node *)b;
	if (node1->front[0]<=node2->front[0]){
		return -1;
	}else{
		return 1;
	}
}
int n,i,j;

int main(){
	//
	scanf("%d",&n);
	int p=n,con=0,d=0;
	typedef struct node Node;
	typedef struct node *nodeptr;
	
	Node point[n+1];	
	
	for(i=0;i<n;i++){
		scanf("%d %d %d %d",&point[i].front[0],&point[i].front[1],&point[i].back[0],&point[i].back[1]);	
	}
	qsort(point,n,sizeof(point[0]),cmp);
	//
	
		for(i=con;i<n;){
			num=1;
			for(j=i;j<n;j++){
				if(point[i].back[0]==point[j].front[0]&&point[i].back[1]==point[j].front[1]){
					num++;
					i=j;
				//	j++;
				}
			}
			//p-=num;
	//	printf("%d\n",p);
		if(max<num){
			max=num;
			d=con;	
		}
		con++;
		num=1;
		i=con;
		}
		
	 
	printf("%d %d %d\n",max,point[d].front[0],point[d].front[1]);
	return 0;
}

