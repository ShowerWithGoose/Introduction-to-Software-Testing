#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
	int a,s[100],i=-1;
	while(scanf("%d",&a)!=EOF){
		if(a==1){
			if(i==99){
				printf("error ");
			}
			else{
				i++;
				scanf("%d",&s[i]);
				
			}
		}
		else if(a==0){
			if(i==-1){
				printf("error ");
			}
			else{
				printf("%d ",s[i]);
				i--;
			}
		}
		else if(a==-1){
			break;
		}
	}
	return 0;
}

