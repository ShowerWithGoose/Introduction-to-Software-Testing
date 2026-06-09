#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
int main(){
char a[1000];
int len,i,j,x,y,z,b;
gets(a);
len=strlen(a);
j=0;
if(a[0] == '0'){
	for(i=2;a[i] == '0';i++){
		j++;
	}
	if(i==len-1){
		printf("%ce-%d",a[len-1],j+1);
	}
	else {
		printf("%c.",a[i]);
		i++;
          b=i;
		for(i=b;i<=len-1;i++){
			printf("%c",a[i]);
		}
		printf("e-%d",j+1);
	}
}
else{
	for(x=1;a[x] != '.';x++){
	}
	if(x==1){
		for(y=0;y<=len-1;y++){
			printf("%c",a[y]);
		}
		printf("e0");
	}
	else if(x==len-1){
		printf("%c.",a[0]);
		for(y=1;y<=x-1;y++){
			printf("%c",a[y]);
		}
		printf("e%d",len-2);
	}
	else{		printf("%c.",a[0]);
		for(y=1;y<=x-1;y++){
			printf("%c",a[y]);
		}
	for(z=x+1;z<=len-1;z++){
		printf("%c",a[z]);
	}	
	printf("e%d",x-1);
	}
	
}
return 0;
}




