#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h> 
int main(){
	char a[100]={0},b[100]={0},x[3]={0};
	int i,note,j,k,m[3],count,len=0,re;
	gets(a);
	for(i=0;a[i]!='\0';i++){
		len++;
	}
	for(i=0;a[i]!='\0';i++){
		if(a[i]=='-'){
			note=i;
			x[0]=a[i-1];
			x[1]=a[i+1];
			for(j=0;j<=1;j++){
				if(x[j]>='a'&&x[j]<='z')
					m[j]=1;
				if(x[j]>='A'&&x[j]<='Z')
					m[j]=2;
				if(x[j]>='0'&&x[j]<='9')
					m[j]=3;
			}
			if(m[0]==m[1]){
	  			if(x[0]<x[1]){
					count=x[1]-x[0];
					re=len-note;
					for(j=0;j<re-1;j++){
						b[j]=a[note+j+1];	
					}
					for(j=0;j<count-1;j++){
						a[note+j]=a[note-1]+j+1;	
					}
					for(j=0;j<re-1;j++){
						a[note+count+j-1]=b[j];
					}
					for(k=0,len=0;a[k]!='\0';k++){
						len++;
	   				}
	  			}	
			}
		}
	}
	printf("%s",a) ;
	return 0;
}

