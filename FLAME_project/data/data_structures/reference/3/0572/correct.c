#include <stdio.h>
main(){
	char a[100];
	char b[100];
	int i,j,n;
	int m=0;
	gets(a);
	for(i=0;a[i]!='\0';i++){
		if(a[i]=='.') n=i;
	}
	if(n>=2) {
		for(i=n;i>=1;i--) a[i]=a[i-1];
		a[1]='.';
		printf("%se%d",a,n-1);
	}
	else if(n==1){
		if(a[0]=='0'){
			for(i=n+1;a[i]=='0';i++){
				m++;
			}
			//printf("%d\n",m);
			char s=a[m+2];
			for(i=2,j=m+3;a[j]!='\0';i++,j++){
		        b[i]=a[j];
			}
			if(i==2) b[0]=s,b[1]='\0';
			else if(i>2) b[0]=s,b[1]='.';
			printf("%s",b);
			printf("e-");
			printf("%d",m+1);
		}
		else{
			printf("%se%d",a,0);
		}
	}
} 



