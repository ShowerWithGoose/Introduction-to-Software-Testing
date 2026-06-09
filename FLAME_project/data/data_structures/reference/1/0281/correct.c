#include<stdio.h>
#include<math.h>
#include<string.h>
int chair[10]={0};
char result[11];
int n;
void rank(int x,int y);
int main(){
	scanf("%d",&n);
	rank(0,n);
	return 0;
} 

void rank(int x,int y){
	int i;
	if(y==0){
		result[x]='\0';
		for(i=0;i<n-1;i++){
			printf("%c ",result[i]);
		}
		printf("%c\n",result[i]);
		return;
	}
	for(i=1;i<=n;i++)
	  if(chair[i]==0){
	  	chair[i]=1;
	  	result[x]='0'+i;
	  	rank(x+1,y-1);
	  	chair[i]=0;
	  }
}


