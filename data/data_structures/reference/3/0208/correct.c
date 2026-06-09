#include<stdio.h>
#include<string.h>
void reverse(char s[]){
	int temp,i,j;
	for(i=0,j=strlen(s)-1;i<j;i++,j--){
		temp=s[i];
		s[i]=s[j];
		s[j]=temp;
	}
}
int main(){
	char num[100],num2[100],num3[100];
	int i=0,j=0,n=0;
	int sum=0;
	gets(num);
	for(i=0;num[i]!='.';i++){
		sum++;
	}
	if(num[0]!='0'){
		num2[0]=num[0];
    	num2[1]='.';
    	for(i=1,j=2;i<=strlen(num);i++){
		if(num[i]!='.'){
			num2[j++]=num[i];
		}
		else{
			;
		}
	}
	char e[5]="e";
	strcat(num2,e);
}
	else{
		for(i=0;num[i]=='0'||num[i]=='.';i++){
			n++;
		}
		num2[0]=num[n];
		if(num[n+1]>='0'&&num[n+1]<='9'){
			num2[1]='.';
			for(i=n+1,j=2;i<=strlen(num);i++){
			num2[j++]=num[i];
		}
	}
		else{
			for(i=n+1,j=1;i<=strlen(num);i++){
			num2[j++]=num[i];
		}
	}
	char s[5]="e-";
		strcat(num2,s);
	}
	//puts(num2);
	int k;
	for(k=0;num[k]!='.';k++);
	k=k-1;
	if(k==0&&num[0]!='0'){
		strcpy(num3,"0");
	}
	else if(k==0&&num[0]=='0'){
		n=n-1;
		for(i=0;n>0;i++){
    		num3[i]=n%10+'0';
    		n=n/10;
	}
}
	else{
		for(i=0;k>0;i++){
    		num3[i]=k%10+'0';
    		k=k/10;
     	}
	}
	num3[i]='\0';
	//puts(num3);
    if(strlen(num3)>1){
		reverse(num3);
	}
	puts(strcat(num2,num3));
	//puts(num3);
	//puts(num2);
	return 0;
}

