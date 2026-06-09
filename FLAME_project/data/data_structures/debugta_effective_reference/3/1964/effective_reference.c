#include<stdio.h>
#include<string.h>

int main()
{
	char num[200],result[200];
	gets(num);
	int i,j,k,l;
	int len=strlen(num);
	char *p=num;
	if(*p!='0'){
		for(i=0;*p!='.';p++,i++);
		j=len-i-1;
		result[0]=num[0];
		result[1]='.';
		for(k=2;k<=i;k++){
			result[k]=num[k-1];
		}
		for(l=i+1;l<len;l++){
			result[l]=num[l];
		}
		result[len]='\0';
		printf("%s",result);
		printf("e%d",i-1);		
	}
	else{
		p=&num[2];
		for(i=2;*p=='0';p++,i++);
		j=len-i;
		if(j>1){
			result[0]=num[i];
			result[1]='.';
			for(k=2;k<=j;k++){
				result[k]=num[i+k-1];
			}
			result[len-i+1]='\0';
			printf("%s",result);
			printf("e-%d",i-1);		
		} 
		else{
			result[0]=num[i];
			result[1]='\0';
			printf("%s",result);
			printf("e-%d",i-1);
				
		}

	}
	return 0;
}



