#include<stdio.h>
#include<string.h>
void insert(char a[],char b[],int number);
	char a[100],b[100];
	char m,n,len,L;
	int i,j,count,number,flag;
int main(){

	number = 0;
	scanf("%s",a);

	for(j=0;j<=30;j++){
		number = 0;
		if(a[j]=='-'){
			len = strlen(a);
			for(i=0;i<len;i++){
				if(a[i]=='-'){
					m=a[i-1];
					n=a[i+1];
					break;
				}
				number++;
	}
	count = n-m;
	if(count==1){
		break;
	}
	if(m>='a'&&n<='z'){
		for(i=1;i<count;i++){
			b[i-1]=m+i;
		}
	}
	else if(m>='0'&&n<='9'){
		for(i=1;i<count;i++){
			b[i-1]=m+i;
		}		
	}
	else if(m>='A'&&n<='Z'){
		for(i=1;i<count;i++){
			b[i-1]=m+i;
		}		
	}
	else {
		flag =0;
		break;
	}
	insert(a,b,number);	
	for(i=number+count-1;i<len+count;i++){
		a[i]=a[i+1];
	}
	memset(b,'\0',sizeof(b));		
	}
	}

		
	puts(a);

	return 0;
} 

void insert(char a[],char b[],int number){

	int i,j;
	int len1,len2;
	len1=strlen(a);
	len2=strlen(b);
	for(i=len1;i>=number;i--){
		a[i+len2]=a[i];
	}
	j=0;
	for(i=number;i<number+len2;i++){
		a[i]=b[j];
		j++;
	}
}

