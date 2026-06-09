#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#define arynum(x) (sizeof(x)/sizeof(x[0]))

int main(){
	char a[110],b[110];
	char *p;
	int i,j,k,num;
	gets(a);
	if(strchr(a,'.')!=NULL){
		p=strchr(a,'.');
		*p='\0';
		num=strlen(a);
		if(num>1){
			for(i=0,k=0;i<num-1;i++){
				a[num-i]=a[num-i-1];
				k++;
			}
			a[1]='.';
			printf("%se%d",a,k);
		}
		else if(a[0]!='0'){
			*p='.';
			printf("%se0",a);
		}
		else{
			*p='.';
			for(i=2,k=0;a[i]=='0';i++)	k++;
			if(a[i+1]!='\0')
				printf("%c.%se-%d",a[i],a+3+k,k+1);
			else 
				printf("%c%se-%d",a[i],a+3+k,k+1);
		}
	}
	else{
		num=strlen(a);
		b[0]=a[0];
		b[1]='.';
		strcat(b,a+1);
		printf("%se%d",b,num-1); 
	}
	return 0;
} 

