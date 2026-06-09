#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(){
	char a[1000],b[1000];
	int i,j,k,len,fuhao=1,sum=0,count=0,count2=0;
	gets(a);
	len=strlen(a);
	k=0;
	for(i=0;i<=len-1;i++){
		if(a[i]!=' '){
			b[k++]=a[i];
		}
	}
	b[k]='\0';
	 len=k;
	 for(j=0;j<=len-1;j++){
	 	if(b[j]>='0'&&b[j]<='9'){
	 	count=count*10+b[j]-'0';	
		 }
		 if(b[j]=='+'){
		sum=fuhao*count+sum;
		fuhao=1;
		count=0; 	
		 }
		 if(b[j]=='-'){
		 sum=fuhao*count+sum;
		 fuhao=-1;
		 count=0;	
		 }
		 if(b[j]=='='){
		 	sum=fuhao*count+sum;
		 	count=0;
		 }
		 if(b[j]=='*'){
		 	count2=0;
		 	for(;j<len;j++){
		 		if(b[j+1]>='0'&&b[j+1]<='9'){
			count2=count2*10+b[j+1]-'0';	 }
			else{
			j=j;break;	
			}
			 }
			 count=count*count2;
		 }
		 if(b[j]=='/'){
		 	count2=0;
		 	for(;j<len-1;j++){
		 		if(b[j+1]>='0'&&b[j+1]<='9'){
			count2=count2*10+b[j+1]-'0';	 }
			else{
			j=j;;break;	
			}
			 }
			 count=count/count2;
		 }
	 }
	 printf("%d",sum);
	 return 0;
}






