#include<stdio.h>
struct  node { 
         int top;
         int data[1000];
};
struct  node s;
int main() {
	int c,a;
	while(scanf("%d",&c)!=-1){
		if(c==1){
			scanf("%d",&a);
			if(s.top>=100){
				printf("error ");
			}
			else {
				s.top++;
				s.data[s.top]=a; 
			}
		}
		else if(c==0){
			if(s.top<1){
				printf("error ");
			}
			else {
				printf("%d ",s.data[s.top]);
				s.top--;
			}
		}
		else{
			if(c==-1){
				break;
			}
		}
		
	}

	return 0;
}

