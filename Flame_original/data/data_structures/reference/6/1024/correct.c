#include<stdio.h>
#define MAX 100
int top;
struct track{
	int k;
	int date;
};

int main(){
	int TRACK[MAX]={0};
	struct track tk[MAX]={0};
	top=-1;
	int i=0;
	for(i=0;i<MAX;i++){
		scanf("%d",&tk[i].k);
		if(tk[i].k==1){
			if(top==MAX-1){
				scanf("%d",&tk[i].date);
				printf("error ");
			}
			else{
				scanf("%d",&TRACK[++top]);
			}
		}
		if(tk[i].k==0){
			if(top==-1){
				printf("error ");
			}
			else{
				printf("%d ",TRACK[top--]);
			}
		}
		if(tk[i].k==-1){
			break;
		}
		
	}
	return 0;
}



