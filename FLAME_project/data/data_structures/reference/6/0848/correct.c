#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

struct node{
	int i;
	int num;
};
struct node node[105];
int main(){
	int i,j,m,n;
	struct node *p;
	for(i=0;i<105;i++){
		node[i].i =i;
	}
	p=&node[0];
	while(scanf("%d",&n)!=EOF){
		if(n==1){
			if(p->i ==100) printf("error ");
			else{
				j=p->i ;
				p=&node[j+1];
				scanf("%d",&m);
				p->num =m;
			}
		}
		else if(n==0){
			if(p->i ==0) printf("error ");
			else{
				j=p->i ;
				printf("%d ",p->num );
				p=&node[j-1];
			}
		}
		else if(n==-1) break;
	}
}

