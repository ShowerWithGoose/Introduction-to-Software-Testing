#include<stdio.h>
#include<string.h>

int main()
{
	int i=0,j=0,k=0,l=0,n,q;//q «≤Ó÷µ 
	char str[105],a[105];
	scanf("%s",str);
	
	for(i=0;i<105;i++)
		a[i]=0;
	
	n=strlen(str);
	
	for(i=0;i<n;i++){
		if(str[i]=='-'&&i!=0){
			if(str[i-1]>='a'&&str[i-1]<='z'&&str[i+1]>='a'&&str[i+1]<='z'&&str[i-1]<str[i+1]){
				q=str[i+1]-str[i-1]-1;
				
				for(j=0;j<n-i-1;j++)
					a[j]=str[i+j+1];
					
				for(j=0;j<q;j++)
					str[i+j]=str[i-1]+j+1;
					
				for(k=0;k<n-i-1;k++)
					str[i+j+k]=a[k];
					
				n=n+q;
				
				for(l=0;l<105-n-q;l++)
					str[i+j+k+l]=0;
				
			}
			if(str[i-1]>='A'&&str[i-1]<='Z'&&str[i+1]>='A'&&str[i+1]<='Z'&&str[i-1]<str[i+1]){
				q=str[i+1]-str[i-1]-1;
				
				for(j=0;j<n-i-1;j++)
					a[j]=str[i+j+1];
					
				for(j=0;j<q;j++)
					str[i+j]=str[i-1]+j+1;
					
				for(k=0;k<n-i-1;k++)
					str[i+j+k]=a[k];
					
				n=n+q;
				
				for(l=0;l<105-n-q;l++)
					str[i+j+k+l]=0;
				
			}
			if(str[i-1]>='0'&&str[i-1]<='9'&&str[i+1]>='0'&&str[i+1]<='9'&&str[i-1]<str[i+1]){
				q=str[i+1]-str[i-1]-1;
				
				for(j=0;j<n-i-1;j++)
					a[j]=str[i+j+1];
					
				for(j=0;j<q;j++)
					str[i+j]=str[i-1]+j+1;
					
				for(k=0;k<n-i-1;k++)
					str[i+j+k]=a[k];
					
				n=n+q;
				
				for(l=0;l<105-n-q;l++)
					str[i+j+k+l]=0;
				
			}
		}
	}
	printf("%s",str);
	return 0;
}

