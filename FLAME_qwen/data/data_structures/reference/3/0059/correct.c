#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

int main(){
 	char c[100];
 	int count=0,i,n=-1,a=0;
 	for(i=0;i<100;i++){
  		count++;
  		c[i]=getchar();
  		if(c[i]=='\n'){
   			break;
  		}
 	}
 	for(i=0;i<count;i++){
  		if(c[i]=='.'){
   			n=i;
   			break;
  		}
 	}
 	if(n>1){
  		for(i=n;i>1;i--){
   			c[i]=c[i-1];
  		}
  		c[i]='.';
  		for(i=2;i<count-1;i++){   
   			if(c[i]=='0'){
    			a++;
   			}
   			else{
    			a=0;
   			}
  		}
  		count= count - a ;
  		if(count == 3){
   			count--;
  		}
  		c[count-1]='e';
  		for(i=0;i<count;i++){
   			printf("%c",c[i]);
  		}
  		printf("%d\n",n-1);
 	}
 	if(n==1 && c[0]=='0'){
  		for(i=0;i<count-1;i++){
   			if(c[i]!='0'&&c[i]!='.'){
    			c[0]=c[i];
    			break;
   			}
  		}
  		n=i;
  		int b=2;
  		for(i=n+1;i<count-1;i++){
   			c[b]=c[i];
   			b++;
  		}
  		for(i=2;i<count-1;i++){   
   			if(c[i]=='0'){
    			a++;
   			}
   			else{
    			a=0;
   			}
  		}
  		count= count - a - n + 1;
  		if(count == 3){
   			count--;
  		}
  		c[count-1]='e';
  		for(i=0;i<count;i++){
   			printf("%c",c[i]);
  		}
  		printf("-%d\n",n-1);
 	}
 	if(n==1 && c[0]!='0'){
  		int b=2;
  		for(i=n+1;i<count-1;i++){
   			c[b]=c[i];
  		}
  		for(i=2;i<count-1;i++){   
   			if(c[i]=='0'){
    			a++;
  	 		}
   			else{
    			a=0;
   			}
  		}
  		count= count - a;
  		if(count == 3){
   			count--;
  		}
  		c[count-1]='e';
  		for(i=0;i<count;i++){
   			printf("%c",c[i]);
  		}
  		printf("%d\n",n-1);
 	}
 	return 0;
}

