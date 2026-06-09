#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAXLINE 1024
int stack[MAXLINE];
int top=-1;
void push(int k);
int main(){
	int n,k,i=0,j;
	int put[MAXLINE];
	while(scanf("%d",&n)!=-1){
		if(n==1){
			scanf("%d",&k);
			if(top==MAXLINE-1){
				put[i]=-1;
				i++;
			}
			else
				stack[++top]=k;
		}
		else if(n==0){
			if(top==-1){
				put[i]=-1;
			}
			else 
			    put[i]=stack[top--];
			i++;
		}
		else if(n==-1) break;
		
	}
	for(j=0;j<i;j++){
		if(put[j]==-1){
			printf("error ");
		}
		else printf("%d ",put[j]);
	}
	return 0;
	
}


