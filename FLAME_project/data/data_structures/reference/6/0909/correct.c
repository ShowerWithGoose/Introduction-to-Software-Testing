#include <stdio.h>
#include <string.h>
int arr[150] = {0};
int mani[300] = {0};
int p = -1;
int main(){
	int num,i = 0,j;
	while(1){
		scanf("%d",&mani[i]);
		if(mani[i]==-1){
			break;
		}
		else{
			i++;
		}
	}
	for(j=0;j<i;j++){
		if(mani[j]==1){
			if(p>=149){
				printf("error ");
				j++;
			}
			else{
				j++;
				p++;
				arr[p] = mani[j];
			}
		}
		else if(mani[j]==0){
			if(p<=-1){
				printf("error ");
			}
			else{
				printf("%d ",arr[p]);
				p--;
			}
		}
	}
	return 0;
}

