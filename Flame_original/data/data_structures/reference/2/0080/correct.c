# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <string.h>
  int main(){
  	int a,b,c;
 char i,j,k;
  a=0;
  
  i= '+';
 while (1){
  	scanf("%d %c",&b,&j);
  	while(j=='*'||j=='/'){
  		scanf("%d %c",&c,&k);
  		if(j=='*'){
  			b=b*c;
		  }
		  else
		  b=b/c;
		  
		  j=k;
	  }
	  if(i=='+') 
	  a=a+b;
	  else if(i=='-')
	  a=a-b;
	  i=j;
	  if(i=='='){printf("%d\n",a);break;}
	  
  }
  }
 

