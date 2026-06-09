#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define ArrayNum(x) (sizeof(x)/sizeof(x[0]))
int main(){
	char c[1000];
	gets(c);
	int l=strlen(c),op[100]={0},num[100]={0},temp,nowo=0,nown=0,j,i,out[100]={0},k=0,over=0,n;
	for(i=0;i<=l;i++){
		if(c[i]==' '||c[i]=='=')
			continue;
		else if(isdigit(c[i])){
			temp=0;
			while(isdigit(c[i])){
				temp=temp*10+c[i]-'0';
				i++;
			}
			nown++;
			num[nown]=temp;
			i--;
			continue;
		}
		else if(c[i]=='+'){
			nowo++;
			op[nowo]=1;
		}
		else if(c[i]=='-'){
			nowo++;
			op[nowo]=2;
		}
		else if(c[i]=='*'){
			nowo++;
			op[nowo]=3;
		}
		else if(c[i]=='/'){
			nowo++;
			op[nowo]=4;
		}
	}
	for(i=1;i<=nowo;i++){
		if((op[i]==1||op[i]==2)&&((op[i-1]==1||op[i-1]==2)||i==1)){
			out[k++]=num[i];
		}
		if(i==nowo&&(op[i]==1||op[i]==2)){
			out[k++]=num[i+1];
		}
		if(op[i]==3){
			if(op[i+1]!=3&&op[i+1]!=4)
				out[k++]=num[i]*num[i+1];
			else{
				num[i+1]=num[i]*num[i+1];
			}
		}
		if(op[i]==4){
			if(op[i+1]!=3&&op[i+1]!=4)
				out[k++]=num[i]/num[i+1];
			else{
				num[i+1]=num[i]/num[i+1];
			}
		}
	}
	over+=out[0];
	for(i=1,n=1;i<=nowo;i++){
		j=1;
		if(op[i]==1){
			over+=out[n];
			n++;
		}
		if(op[i]==2){
			over-=out[n];
			n++;
		}
	}
	if(nowo==0)
		printf("%d",num[1]);
	else
		printf("%d",over);
	return 0;
}




