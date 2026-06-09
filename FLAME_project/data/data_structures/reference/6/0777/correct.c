#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
int main(){
	int op;
	int num[105];
	int cnt=0;
	int i;
	int b;
	while(scanf("%d",&op)!=EOF){
		if(op==1){
			if(cnt<100){
			    scanf("%d",&num[i++]);
			    cnt++;
		}
		    else{
		    	scanf("%d",&b);
		    	printf("error ");
			}
		}
		else if(op==0){
			if(cnt>0){
				printf("%d ",num[i-1]);
			    i=i-1;
			    cnt--;
			}
			else{
				printf("error ");
			}
		}
		else if(op==-1)
		break;
	}
	return 0;
}

