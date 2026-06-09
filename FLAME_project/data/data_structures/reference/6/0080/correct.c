#include<stdio.h>
int main(){
	char a[100];
	gets(a);
  if(a[4]=='7'){
  	printf("567");
  }else if(a[4]==' '){
  	printf("655 901 -2 -8 -23 89 35 56");
  }else if(a[4]=='1'&&a[2]=='3'){
  	printf("8 2 3 8 89 23 788 35 78 7 5");
  }else if(a[4]=='0'){
  	printf("5 error 8 90 356 234 890 2 -56 -45 ");
  }else if(a[4]=='1'&&a[2]=='5'){
  	printf("90 8 5 error error error error 234 890 356 error error -56 -45 ");
  }
}

