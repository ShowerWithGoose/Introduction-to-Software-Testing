#include <stdio.h>
#include <string.h>
int main() {
	int sign,sta[1000],out[1000];
	memset(sta,0,sizeof(sta));
	memset(out,0,sizeof(out));
	int num=0,i=0;
	scanf("%d",&sign);
	while(sign!=-1) {
		if(sign==1) {
			scanf("%d",&sta[num]);
			if(num>99)
				out[i++]=1;
			else
				num++;
		} else if(sign==0) {
			if(num!=0) {
				out[i++]=sta[--num];
			} else
				out[i++]=1;
		}
		scanf("%d",&sign);
	}
	for(int j=0; j<i; j++) {
		if(out[j]==1) {
			printf("error ");
		} else
			printf("%d ",out[j]);
	}
	return 0;
}

