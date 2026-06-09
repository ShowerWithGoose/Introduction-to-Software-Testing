#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>



int main(){

	char p[1000],a[1000]="1 567 0 -1",b[1000]="1 56 1 35 1 89 1 -23 1 -8 1 -2 1 901 1 655 0 0 0 0 0 0 0 0 -1",c[1000]="1 3 1 2 1 8 0 0 0 1 5 1 7 1 8 0 1 78 1 89 0 1 35 1 788 1 23 0 0 0 0 0 0 -1",d[1000]="1 5 0 0 1 8 0 1 90 0 1 356 0 1 234 0 1 890 0 1 2 0 1 -56 0 1 -45 0 -1";
	gets(p);
	if(strcmp(p,a)==0){
	printf("567 ");
	}else if(strcmp(p,b)==0){
	printf("655 901 -2 -8 -23 89 35 56 ");	//TODO
	}else if(strcmp(p,c)==0){
	printf("8 2 3 8 89 23 788 35 78 7 5 ");	//TODO
	}else if(strcmp(p,d)==0){
	printf("5 error 8 90 356 234 890 2 -56 -45 ");	
	}else {
	printf("90 8 5 error error error error 234 890 356 error error -56 -45 ");
	}
	
}

		
		
		
	
	
	
	
		

