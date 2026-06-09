#include<stdio.h>
int N;
char cunfang[11];
int mark[11];
void count(int rest,int next);
int main(){
	scanf("%d",&N);
	count(N,0);
	return 0;
	}
void count(int rest,int next){
	int i;
	if(rest==0){
	for(i=0;i<=N;i++){
		if(i!=N)printf("%c ",cunfang[i]);
		else printf("%c\n",cunfang[N]);
	}
	}
	for(i=1;i<=N;i++){
		if(mark[i]==0){
		cunfang[next] = '0'+i; 
		mark[i]++;
		count(rest-1,next+1);
		mark[i]--;
		}
	}
}



