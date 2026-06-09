#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXSIZE 100
int main(){
	int stack[MAXSIZE];
	int top=-1;
	int conduct;
	int toprint[200];
	int i=0;
	char enter;
    while(scanf(" %d",&conduct)){
    	if(conduct==1){
    		if(top==99){
    			toprint[i]=0;i++;
			}else if(top!=99){
			    top++;
				scanf(" %d",&stack[top]);
			}
		}else if(conduct==0){
			if(top==-1){
				toprint[i]=0;i++;
			}else{
				toprint[i]=stack[top];
				i++;
				top--;
			}
		}else if(conduct==-1){
			break;
		}
	}
	int j=0;
	while(j<i){
		if(toprint[j]!=0){
			printf("%d ",toprint[j]);
		}else{
			printf("error ");
		}
		j++;
	}
}

