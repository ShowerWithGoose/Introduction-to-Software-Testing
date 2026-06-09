#include<stdio.h>
#include<math.h>
int main()
{
	char a[10001],c[10001];     
	int b[10001]={};             
	int i=0,j=0,k=0;
	gets(a);
	while(a[i]!='\0'){
		if(a[i]>=48&&a[i]<=57){
			b[j]=b[j]*10+(a[i]-48);
			i++;
		}
		else if(a[i]==43||a[i]==45||a[i]==42||a[i]==47){
			c[k]=a[i];
			i++;
			k++;
			j++;
		}
		else{
			i++;
		}
	}
	j++;
	c[k++]='\0';
	int m=0,l=0,q=0,n=0;
	int sum[10001]={};
	char fuhao[10001];
	sum[0]=b[0];
	while(c[m]!='\0'){
		if(c[m]==42){
			sum[l]=sum[l]*b[m+1];
		}
		else if(c[m]==47){
			sum[l]=sum[l]/b[m+1];
		}
		else{
			fuhao[q]=c[m];
			q++;
			l++;
			sum[l]=b[m+1];
		}
		m++;	
	}
	fuhao[q++]='\0';
	int final=sum[0];
	while(fuhao[n]!='\0'){
		if(fuhao[n]==43){
			final=final+sum[n+1];
		}
		else{
			final=final-sum[n+1];
		}
		n++;
	}
	printf("%d",final);
	return 0;
}



