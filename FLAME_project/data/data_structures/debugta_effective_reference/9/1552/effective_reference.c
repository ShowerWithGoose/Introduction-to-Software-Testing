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
    struct d line[101],hold;
	  int n;
  	int i;
  	scanf("%d",&n);
  	for(i=0;i<n;i++){
  		scanf("%d%d%d%d",&line[i].x[0],&line[i].y[0],&line[i].x[1],&line[i].y[1]);
	  }
  	   int j,flag;
    for (i = 0; i < n-1; i++)
 {
 flag = 0;
 for (j = 0; j < n-1-i; j++)
 {
 if (line[j].x[0] > line[j + 1].x[0])
 {
      hold=line[j];
 line[j] = line[j + 1];
 line[j + 1] = hold;
 flag = 1;
 }
 }
 if (0 == flag)
 break; 
 }
    int lianxu=1,max=1,xbegin,ybegin,m;
            for(i=0;i<n;i++){
            	m=i;
    	for(j=i+1;j<n;j++){
            if(line[m].x[1]==line[j].x[0]&&line[m].y[1]==line[j].y[0]){
            	lianxu++;
		m=j;	
		}
			
	}
			if(lianxu>max){
			    max=lianxu;
				xbegin=line[i].x[0];
				ybegin=line[i].y[0];}
				lianxu=1;          	
			}
			printf("%d %d %d",max,xbegin,ybegin);
}
  

