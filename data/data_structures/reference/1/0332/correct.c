#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
void fullarrange(int,int);
int box[100],card[100];
int main(){
	int l;
	scanf("%d",&l);
	fullarrange(1,l);
	return 0;
}

void fullarrange(int step,int k){
	if(step>k){
		for(int i=1;i<=k;i++)printf("%d ",box[i]);
		printf("\n");
	}
	for(int i=1;i<=k;i++){
		if(!card[i]){
			box[step]=i;
			card[i]=1;
			fullarrange(step+1,k);
			card[i]=0;
		}
	}
	
}



