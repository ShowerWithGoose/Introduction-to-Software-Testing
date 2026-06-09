#include<stdio.h>
struct stack{
	int num;
	int b[105];
};
struct stack x;
int main(){
	int i,m,n;
	x.num=0;
	while(scanf("%d",&n)!=EOF){
		if(n==1){
			scanf("%d",&m);
			if(x.num>=100){
				printf("error ");
			}
			else{
				x.b[x.num]=m;
			    x.num++;
			}
		}
		else if(n==0){
			if(x.num==0){
				printf("error ");
			}
			else{
				printf("%d ",x.b[x.num-1]);
				x.num--;
			}
		}
		else if(n==-1){
			break;
		}
	}
	return 0;
}

