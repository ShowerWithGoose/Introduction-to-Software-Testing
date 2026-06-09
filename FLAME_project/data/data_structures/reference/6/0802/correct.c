#include <stdio.h>

int main(){
	long long i = 0, k = -1, s[100], j[100];
	while(s[i - 1] != -1){
		scanf("%lld", &s[i]);
		i++;
	}
	for(i = 0;s[i] != -1;i++){
		if(s[i] == 1){
			k++;
			j[k] = s[i+1];
		}
		else if(s[i] == 0){
			if(k >= 0){
				printf("%lld ", j[k]);
				k--;
			}
			else{
				printf("error ");
			}
		}
	}
	return 0;
} 

