#include<stdio.h>
#include<string.h>
#include<math.h>
int source[11],x,out[11];

int all(int a,int b) {   //a--МоµЪaО»
	if(b<=0) {
		for(int i=0; i<x; i++) {
			printf("%d ",out[i]);

		}
		printf("\n");
		return 0;

	}
	for(int i=1; i<=x; i++) {
		if(source[i]==0) {
			source[i]++;
			out[a]=i;
			all(a+1,b-1);
			source[i]--;


		}

	}

}
int main() {

	scanf("%d",&x);
	all(0,x);


	return 0;
}





