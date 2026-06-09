#include<stdio.h>
int yunsuan(int,char,int);
int main(){
	int a,b,c;
	char sign[2];
	scanf("%d %c",&a,&sign[0]);
	if(sign[0]=='=')
	printf("%d",a);
	else{
		scanf(" %d %c",&b,&sign[1]);
		if(sign[1]=='=')
	    printf("%d",yunsuan(a,sign[0],b));
	    else{
		scanf(" %d",&c);
		while(sign[1]!='='){
	     if(sign[0]=='*'||sign[0]=='/'){
	     	a=yunsuan(a,sign[0],b);
	     	b=c;
	     	sign[0]=sign[1];
		 }
		 else if(sign[1]=='*'||sign[1]=='/'){
		 	   b=yunsuan(b,sign[1],c);
		 }
		      else{
		 	  a=yunsuan(a,sign[0],b);
	          b=c;
	     	  sign[0]=sign[1];
		 } 
		   scanf(" %c %d",&sign[1],&c);
		}
	}
	printf("%d",yunsuan(a,sign[0],b));}
	
	return 0;
} 
int yunsuan(int a,char b,int c){
	if(b=='+')
	return a+c;
	if(b=='-')
	return a-c;
	if(b=='*')
	return a*c;
	if(b=='/')
	return a/c;
}

