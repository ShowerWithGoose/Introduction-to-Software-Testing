#include <stdio.h>

int x[101],n;

int main(){
	int a;
	while(scanf("%d",&a),a^(-1)){
		if(a){
			scanf("%d",&x[++n]);
		}
		else{
			if(n)
				printf("%d ",x[n--]);
			else printf("error ");
		}
	}
	return 0;
}
