#include<stdio.h>
int main(){
	char a[101];
	gets(a);
	int flag=0,q=0;
	int i,j;
	int m=0,n=0,s;
	for(i=0;a[i]!='\0';i++){
		if(a[i]=='.')q=1;
		if(q==1) m++;
		else n++;
	} 
	for(i=0;a[i]!='\0';i++){
		if(a[i]=='.') ;
		else{
			if(flag==0){
				if(a[i]!='0') {
					printf("%c",a[i]);
					flag=1;
					s=i;
					if(m-s>=1) printf("."); 
				}
			}else if(flag==1&&q==1) {
				printf("%c",a[i]);
			} 
		}
		
	}
	if(a[0]<'1') printf("e-%d",s-1);
	else printf("e%d",n-1);
	return 0;
	
	}

