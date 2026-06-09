#include<stdio.h>
#include<string.h>
int main()
{
	char a[10000]={0},b[10000]={0};
	int i,j=0,k,n,m;
	scanf("%s",a);
	int l=strlen(a);
	for(i=0;i<=l;i++){
		if(a[i]!='-'){
			b[j]=a[i];
			j++;//-之前的字符 
		}
		if(a[i]=='-'){
			
			if(a[i-1]>='a'&&a[i+1]<='z'&&a[i-1]<a[i+1]){//小写字母 
				
				n=a[i+1]-a[i-1]-1;
				k=j+n;
				m=j;
				for(j=m;j<=k;j++){
					b[j]=b[j-1]+1;
						
				} 
				i++;
			}
		else if(a[i-1]>='0'&&a[i+1]<='9'&&a[i-1]<a[i+1]){//数字 
			
				n=a[i+1]-a[i-1]-1;
				k=j+n;
				m=j;
				for(j=m;j<=k;j++){
					b[j]=b[j-1]+1;
						
				} 	i++;
			}
		else if(a[i-1]>='A'&&a[i+1]<='Z'&&a[i-1]<a[i+1]){//大写字母 
				
				n=a[i+1]-a[i-1]-1;
				k=j+n;
				m=j;
				for(j=m;j<=k;j++){
					b[j]=b[j-1]+1;
						
				} i++;
			}
			else {
				b[j]=a[i];
				j++;
			}
		}
	}
      printf("%s",b);
	return 0;
}






