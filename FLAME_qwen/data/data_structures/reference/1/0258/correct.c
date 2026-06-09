#include<stdio.h>
#include<string.h>
int NUM[15]={0},n;
char POS[15];
void order(int a,int b);
int main(){
	scanf("%d",&n);
	order(0,n);
	return 0;
}
void order(int a,int b){
	int i,j;
	if(b==0){
		POS[a]='\0';
		j=strlen(POS);
		for(i=0;i<j-1;i++) printf("%c ",POS[i]);
		printf("%c\n",POS[j-1]);
	}
	for(i=1;i<n+1;i++){
		if(NUM[i]==0){
			NUM[i]=1;
			POS[a]='0'+i;
			order(a+1,b-1);
			NUM[i]=0; 
		}
	}
}



