#include<stdio.h>
#include<string.h>
char a[10000] = {0},b;
int i,j;
int main(){
    gets(a);
    for(i = 0; a[i]!='\0';i++){
    	if( a[i] == '-'){
    		if( i == 0)
    		    printf("-");
    		if('0' <= a[i-1] && a[i-1] < '9'){
				if(a[i-1] < a[i+1] && a[i+1] <= '9'){
				    for(j = 1;j < (a[i+1] + '0') - (a[i-1] + '0'); j++){
						b = a[i-1] + j;
				        printf("%c",b);
						}
				}
				else
				printf("-");	
			}
			if('a' <= a[i-1] && a[i-1] < 'z'){
				if(a[i-1] < a[i+1] && a[i+1] <= 'z'){
					for(j = 1;j < (a[i+1] + '0') - (a[i-1] + '0'); j++){
						b = a[i-1] + j;
						printf("%c",b);
						}
						}
				else
					printf("-");	
						}
			if('A' <= a[i-1] && a[i-1] < 'Z'){
				if(a[i-1] < a[i+1] && a[i+1] <= 'Z'){
					for(j = 1;j < (a[i+1] + '0') - (a[i-1] + '0'); j++){
						b = a[i-1] + j;
						printf("%c",b);
						}
					}
				else
				    printf("-");	
					}
			}
			else
		            printf("%c", a[i]);
			}
	return 0;
}

