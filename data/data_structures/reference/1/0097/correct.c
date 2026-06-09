#include<stdio.h>
#include<string.h>
int mark[11]={0};
char s[11];
void digui(int m,int n,int n1){
	int i,j,t=0;
	for(i=1;i<=n1;i++){
		if(mark[i]==0){
			mark[i]=1;
			s[m]='0'+i;
			digui(m+1,n-1,n1);
			mark[i]=0;
		}
	}
	if(n==0){
		s[m]='\0';
		t=strlen(s);
		for(j=0;j<t;j++){
			printf("%c ",s[j]);
		}
		printf("\n");
		return ;
	}
}


int main(){
    int n1;
	scanf("%d",&n1);
	digui(0,n1,n1);
	return 0;
}


