#include<stdio.h>
#include<string.h>
#include<math.h>
int main(){
 char shu1[2000],shu2[2000];
 int i,dian,j;
 int a;
 gets(shu1);
 for(i=0;i<strlen(shu1);i++){
 	if(shu1[i]=='.')
{        
    dian=i;
      break;
 } 
 }
  if(dian==1){
  	if(shu1[0]=='0'){
  		for(i=2;i<strlen(shu1);i++){
  			if(shu1[i]!='0'){
			  j=i;
			  break;
			  }
		  }
		  shu2[0]=shu1[j];
		if(i!=strlen(shu1)-1){
			shu2[1]='.';
	  for(i=j+1,a=2;i<strlen(shu1);i++,a++){
	  	shu2[a]=shu1[i];	 
	  }}
	  else{
	  	a=1;
	  }
	    for(i=0;i<a;i++){
	    	printf("%c",shu2[i]);
		}  	
  	 printf("e-%d",j-1); }
	 else{
	 	for(i=0;i<strlen(shu1);i++){
	 		printf("%c",shu1[i]);
		 }
		 printf("e0");
	 }	
  }
  else{
  shu2[0]=shu1[0];
  shu2[1]='.';
  for(i=1,a=2;i<strlen(shu1);i++){
  if(shu1[i]!='.'){
  		shu2[a]=shu1[i];
  		a++;	
	  }
  }
  for(i=0;i<strlen(shu1);i++){
  	printf("%c",shu2[i]);
  }
  printf("e%d",dian-1);
  }
}

