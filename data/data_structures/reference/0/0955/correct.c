#include<stdio.h>
#include<string.h>
int main(){
	char a[10000];
	int num,x,sum;
	int cha1,cha2,sign=0;
	scanf("%s",a);
	int l=strlen(a);
	for(int i=0;a[i]!='\0';i++){
		if(a[i]=='-'&&a[i+1]-a[i-1]>0){
			cha1=a[i+1]-'0';
			cha2=a[i-1]-'0';
			if(cha1<=9&&cha2<9)
			sign++;
			else if(cha1>49&&cha2>=49)
			     sign++;
				 else if(cha1>9&&cha1<=42&&cha2>=9&&cha2<42)
				 sign++; 
		}
		x=cha1-cha2-1;
		sum=sum+x;
		if(sign>0){
		 
	    for(num=0;num<l-i-1;num++)
		  a[l+x-2-num]=a[l-1-num];
		for(int q=0;q<x;q++)
		a[i+q]=a[i-1]+1+q;   
		} 
		sign=0;
		l=strlen(a);
	} 
	for(int p=0;p<l+x-1;p++)
	printf("%c",a[p]);
	return 0;
} 

