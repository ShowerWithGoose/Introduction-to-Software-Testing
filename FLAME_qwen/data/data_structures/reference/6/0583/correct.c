#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
	int a[1000];
	int tmp[100];
	int op = 0;
	int i = 0;//read
	int j = 0;//in&out
	while(1){
		scanf("%d",&a[i]);
		if(a[i] == -1){
			break;
		}
		i++;
	}
	int num = i;
	i = 0;
	while(i < num){
		if(a[i] == 1){
			i++;
			tmp[j] = a[i];
			j++;
			i++;
			op++;
			continue;
		}
		if(a[i] == 0&&op != 0){
			j--;
			printf("%d ",tmp[j]);
			tmp[j] = 0;
			op--;
			i++;
			continue;
		}
		if(a[i] == 0&&op == 0){
			printf("error ");
			i++;
			continue;
		}
	}
	return 0;
}
