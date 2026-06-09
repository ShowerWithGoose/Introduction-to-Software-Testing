#include<stdio.h>
#include<string.h>
int NUM[15]={0},l1;
char POS[15];
void order(int l2,int b);
int main(){
	scanf("%d",&l1);
	order(0,l1);
	return 0;
}
void order(int l2,int b){
	int i,j;
	if(b==0){
		POS[l2]='\0';
		j=strlen(POS);
		for(i=0;i<j-1;i++) printf("%c ",POS[i]);
		printf("%c\n",POS[j-1]);
	}
	for(i=1;i<l1+1;i++){
		if(NUM[i]==0){
			NUM[i]=1;
			POS[l2]='0'+i;
			order(l2+1,b-1);
			NUM[i]=0; 
		}
	}
}



