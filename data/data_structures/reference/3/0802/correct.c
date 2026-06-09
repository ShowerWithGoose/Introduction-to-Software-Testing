#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	char a[100] = {"0"}, temp1, b[100] = {"0"};
	long long i = 0, j, k;
	gets(a);
	b[0] = a[0];
	while(1){
		if(a[i] != '.'&&i <= strlen(a) - 1){
			i++;
		}
		else{
			break;
		}
	}
	if(i == strlen(a)){
		b[0] = a[0];
		b[1] = '.';
		k = strlen(a) - 2;
		for(i = 1, j = 2;i <= strlen(a) - 1;i++,j++){
			b[j] = a[i];
		}
		printf("%se%lld", b, k);
	} 
	else{
	j = i;
	if(j != 1){
		k = j - 1;
		b[1] = a[j];
		for(i = j = 1;i <= strlen(a);i++){
			if(a[i] == '.'){
				continue;
			}
			else{
			b[j+1] = a[i];
			j++;
		}
	    }
	    printf("%se%lld", b, k);
	}
	else if(j == 1&&a[0] - '0'){
		printf("%se0", a);
	}
	else{
		k = 1; 
		while(a[i+2] == '0'){
			k++;
			i++;
		}
		if(a[2] != '0'){
		i += 1;
		b[0] = a[i];
	}
	else{
		i += 2;
		k += 1;
		b[0] = a[i];
	}
		if(i == strlen(a) - 1){
		printf("%se-%lld", b, k);
		}
		else{
			b[1] = '.';
			for(j = 2, i += 1;i <= strlen(a)-1;i++, j++){
				b[j] = a[i];
			}
			printf("%se-%lld", b, k);
		}
	}
}
	return 0;
} 

