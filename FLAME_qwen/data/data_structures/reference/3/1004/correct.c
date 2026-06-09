#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
char a[3000];
char b[3000];
int main(){
	int c,i,j=0,m;
	gets(a);
	for(i=0;i<strlen(a);i++){
		if(a[i]=='.'){
		c=i;
		break;}
	}
	if(c==1){
		if(a[0]=='0'){
			for(i=2;i<strlen(a);i++){
				if(a[i]!='0'){
				j=i;
				break;
			}
			}	
						
			b[0]=a[j];
			if(j==strlen(a)-1){
				printf("%c",b[0]);
				printf("e-%d",j-1);
			}
			else {
				b[1]='.';
				for(i=j+1,m=2;i<strlen(a);m++,i++){
					b[m]=a[i];
				}
				for(i=0;i<m;i++){
					printf("%c",b[i]);
				}
					printf("e-%d",j-1);
				
			}
		}
		
		if(a[0]!='0'){
			for(i=0;i<strlen(a);i++){
				printf("%c",a[i]);
			}
				printf("e0");
			
		}
	}
	else{
		b[0]=a[0];
		b[1]='.';
		for(i=1,m=2;i<strlen(a);i++){
			if(a[i]!='.'){
				b[m]=a[i];
				m++;
			}
		}
		for(i=0;i<strlen(a);i++){
			printf("%c",b[i]);
		}
		printf("e%d",c-1);
	}
return 0;
}


