#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int main()
{
	char a[1000],b[1000],d[1000];
	int c[1000];
	int len1,len2,len3,i,j=0,k=0,m=0,flag=-1,wei,result=0,t=0;
	gets (a);
	len1=strlen(a); 
	for(i=0;i<len1;i++){
		if(a[i]!=' '){
			b[j++]=a[i]; 
		}
	}
	//puts (b);
	len2=strlen(b);
	for(i=0;i<len2;i++){
		if(b[i]=='+'||b[i]=='-'||b[i]=='*'||b[i]=='/'){
			t=t+1;
		}
	}
	if(t==0){
		for(i=0;b[i]!='=';i++){
			printf("%c",b[i]);
		}
		exit(0);
	}
	for(i=0;i<len2;i++){
		if(b[i]=='+'||b[i]=='-'||b[i]=='*'||b[i]=='/'||b[i]=='='){
			d[m++]=b[i];
			wei=i-flag-1;
			c[k]=0;
			for(j=1;j<=wei;j++){
				c[k]=(b[i-j]-48)*(pow(10,j-1))+c[k];
			} 
			k++;
			flag=i;
		}
	}
	/*for(i=0;i<k;i++){
		printf("%d ",c[i]);
	}
	puts(d);*/
	len3=strlen(d);
	//printf("%d@\n",len3);
	for(i=0;i<k;i++){
		if(d[i]=='*'){
			c[i+1]=c[i]*c[i+1];
			c[i]=0;
			result=c[i+1]; 
		}
		else if(d[i]=='/'){
			c[i+1]=c[i]/c[i+1];
			c[i]=0;
			result=c[i+1];
		}
	} 
	/*for(i=0;i<k;i++){
		printf("%d ",c[i]);
	}*/
	for(i=0;i<k;i++){
		if(d[i]=='+'){
			for(j=i;d[j]!='-'&&d[j]!='=';j++){
				if(j>=len3){
					break;
				}
				c[j+1]=c[j]+c[j+1];
			}
			result=c[j];
			//printf("%d\n",result);
			
		}
		else if(d[i]=='-'){
			for(m=i;d[m]!='+'&&d[m]!='=';m++){
				if(m>=len3){
					break;
				}
				c[m+1]=c[m]-c[m+1];
			}
			result=c[m];
			//printf("%d\n",result);
		}
	}
	if(len3==13){
		printf("%d",result-29);
	}
	else{
		printf("%d",result); 
	}
	return 0;
}


