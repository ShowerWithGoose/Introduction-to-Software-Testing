#include<stdio.h>
#include<string.h>
int main(){
	char a[1000]={'\0'};
	scanf("%s",a);
	int i=0,j,n;
	while(a[i]!='\0'){
		if(i>0&&a[i]=='-'){
			if((a[i-1]<a[i+1]-1&&(a[i-1]>='a'&&a[i+1]<='z'))||(a[i-1]<a[i+1]-1&&a[i-1]>='A'&&a[i+1]<='Z')||(a[i-1]<a[i+1]-1&&a[i-1]>='0'&&a[i+1]<='9')){//¼ìÑé 
				j=a[i+1]-a[i-1]-3+strlen(a);
				n=a[i+1]-a[i-1];
				//printf("%d\n",j);
				int k,m=i;
				for(k=strlen(a)-1;k>i;k--,j--) a[j]=a[k];//Áô¿Õ 
				for(k=1;k<n;k++) {
				        
					   a[m+k-1]=a[i-1]+k;//ÌîÉÏ  
					   //printf("%d\n",n);
				} 
			}
		}
		i++;
	}
	printf("%s",a);
	return 0;
} 



