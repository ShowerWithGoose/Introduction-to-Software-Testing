#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
int mark[10];
char chuan[11]; 
void rank(int n,int m){
	int i;
	if(m==n*2){
		chuan[m]='\0';
		printf("%s\n",chuan);
		return ;
	}
	
		for(i=1;i<=n;i++){
			if(mark[i]==0){
				mark[i]=1;
				chuan[m]=i+'0';
				chuan[m+1]=' ';
				rank(n,m+2);
				mark[i]=0;
			}
		}
	
}
int main(){
	int n;
	scanf("%d",&n);
	rank(n,0);
	return 0;
}


