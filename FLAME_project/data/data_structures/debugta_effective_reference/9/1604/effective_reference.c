#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include<stdlib.h>
  struct  d{
  	int x[2];
  	int y[2];
  };
  int main(){ 
    struct d dian[101],hold;
	  int n;
  	int i;
  	scanf("%d",&n);
  	for(i=0;i<n;i++){
  		scanf("%d%d%d%d",&dian[i].x[0],&dian[i].y[0],&dian[i].x[1],&dian[i].y[1]);
	  }
  	   int j,flag;
    for (i = 0; i < n-1; i++)
 {
 flag = 0;
 for (j = 0; j < n-1-i; j++)
 {
 if (dian[j].x[0] > dian[j + 1].x[0])
 {
      hold=dian[j];
 dian[j] = dian[j + 1];
 dian[j + 1] = hold;
 flag = 1;
 }
 }
 if (0 == flag)
 break; 
 }
    int chang=1,max=1,maxx,maxy,m;
            for(i=0;i<n;i++){
            	m=i;
    	for(j=i+1;j<n;j++){
            if(dian[m].x[1]==dian[j].x[0]&&dian[m].y[1]==dian[j].y[0]){
            	chang++;
		m=j;	
		}
			
	}
			if(chang>max){
			    max=chang;
				maxx=dian[i].x[0];
				maxy=dian[i].y[0];}
				chang=1;          	
			}
			printf("%d %d %d",max,maxx,maxy);
}
  

