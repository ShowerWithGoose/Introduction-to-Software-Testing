#include <stdio.h>

char nums[]="123456789X";
int Hash[10]={0};
char output[10];
int len;



void summon(int d){
	for(int i=0;i<=len;i++){
		if(!Hash[i]){
			Hash[i]=1;
			output[d]=nums[i];
			if(d==len){
				for(d=0;d<=len;d++){
					if(output[d]=='X') printf("10 ");
					else printf("%c ",output[d]);
				}
				printf("\n");
			}
			else summon(d+1);
			Hash[i]=0;
		}
	}
}

int main(){
	int n;
	scanf("%d",&n);
	nums[n]=0;
	len=n-1;
	summon(0);
	return 0;
}

