#include<stdio.h>
#include<string.h>
int main(){
	char a[101];
	char b[101];
	int i,j,k,l,h=0;
	gets(a);
	l=strlen(a);
	for(i=0;i<l;i++){
		if(a[i]=='.'){
			j=i;
			break;
		}
	}
	if(j==1){
		if(a[0]=='0'){
			for(i=2;i<l;i++){
				
				if(a[i]!='0'){
					k=i;
					break;
			}
			}
			b[0]=a[i];
			if(k!=l-1){
				b[1]='.';
				for(i=k+1,h=2;i<l;i++,h++)
				b[h]=a[i];
				
			}
			else
			h=1;
			
			for(i=0;i<h;i++)
				printf("%c",b[i]);
				printf("e-%d",k-1);
				
		}
		else{
			for(i=0;i<l;i++)
				printf("%c",a[i]);
				printf("e0");
				
			
		}
		
	} 
	else{
		b[0]=a[0];
		b[1]='.';
		for(i=1,h=2;i<l;i++,h++){
			if(a[i]!='.')
			b[h]=a[i];
			else 
			h=h-1;
		}
		for(i=0;i<l;i++)
			printf("%c",b[i]);
			printf("e%d",j-1);
		
	}
	
	
	
} 



