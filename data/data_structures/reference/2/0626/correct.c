#include<stdio.h>
#include<string.h>

int main()
{
	int i,j,l=0,k=0,n,ans=0,q=0;
	int x[1000],y[1000];//x¼ÇÂ¼Êý×Ö£¬y¼ÇÂ¼·ûºÅ 
	char a[1000];
	gets(a);
	n=strlen(a);	
	
	for(i=0;i<n;i++){
		if(a[i]>='0'&&a[i]<='9'){
			x[l]=a[i]-'0';
			for(j=0;j<n;j++){
				if(a[i+j+1]>='0'&&a[i+j+1]<='9'){
					x[l]=x[l]*10+a[i+j+1]-'0';
					q++;
					}
				
				else
					break;
			}
			l++;
		}
		
		if(a[i]=='+'){
			y[k]=1;
			k++;
		}if(a[i]=='-'){
			y[k]=2;
			k++;
		}if(a[i]=='*'){
			y[k]=3;
			k++;
		}if(a[i]=='/'){
			y[k]=4;
			k++;
		}if(a[i]=='='){
			y[k]=5;
			k++;
		}
		i+=q;
		q=0;
	}
	for(i=k;i<100;i++)
		y[k]=0;
	
	for(i=0;i<k;i++){
		if(y[i]==3){
			x[i-q]=x[i-q]*x[i-q+1];
			
			for(j=0;j<n-i-2;j++)
				x[i+j-q+1]=x[i+j-q+2];
			
			q++;
		}
		if(y[i]==4){
			x[i-q]=x[i-q]/x[i-q+1];
			
			for(j=0;j<n-i-2;j++)
				x[i+j-q+1]=x[i+j-q+2];
			
			q++;
		}
	}
	
	for(i=0;i<k;i++){
		if(y[i]==3||y[i]==4){
			for(j=0;j<k-i;j++)
				y[i+j]=y[i+j+1];
				
			i--;
		}
	}
	
	for(i=0;i<k;i++)
		if(y[i]==2)
			x[i+1]=-x[i+1];
	
	for(i=0;i<l-q;i++)
		ans+=x[i];
	
	printf("%d",ans);
	return 0;
}



