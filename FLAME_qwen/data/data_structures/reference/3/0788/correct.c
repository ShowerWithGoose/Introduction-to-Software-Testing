#include<stdio.h>
#include<string.h>
int main(){
	char a[200];
	scanf("%s",&a);
	int l=strlen(a),i=0,m=l,n,t=0,k=0;
	for(i=0;i<l;i++){
		if(a[i]=='.')
		m=i;
		else if(a[i]!='0'&&t==0){
			n=i;
			t++;
		}
	}
	for(i=l-1;i>=0;i--){
		if(a[i]=='0')
		k++;
		else if(a[i]!='.')
		break;
	}
	if(n<l-k-1){
		for(i=n;i<l-k;i++){
			if(a[i]=='.')
			continue;
    		printf("%c",a[i]);
    		if(i==n)
    		printf(".");
    	}
    	if(m<n)
    	printf("e%d",m-n);  
		else  	
    	printf("e%d",m-n-1);
	}
	else if(k!=0)
	printf("%ce%d",a[n],m-n-1);
	else	
	printf("%ce%d",a[n],m-n);
} 

