#include<stdio.h>
#include<string.h>
int main(){
	char a[500]=" ",b[500]=" ";
	int i=0,j=0,n=0,k,m=0;
	scanf("%s",a);
	for(i=0;i<=strlen(a)-1;i++){
		if(a[i]=='-'){
			k=a[i-1];
			if(a[i-1]>='a'&&a[i-1]<='z'&&a[i+1]>='a'&&a[i+1]<='z'&&a[i-1]<a[i+1]){
				n=a[i+1]-a[i-1]-1;
				for(m=0;m<n;m++,j++){
					b[j]=k+1;
					k++;}
			}
			else if(a[i-1]>='A'&&a[i-1]<='Z'&&a[i+1]>='A'&&a[i+1]<='Z'&&a[i-1]<a[i+1]){
				n=a[i+1]-a[i-1]-1;
				for(m=0;m<n;m++,j++){
					b[j]=k+1;
					k++;}
			}
			else if(a[i-1]>='0'&&a[i-1]<='9'&&a[i+1]>='0'&&a[i+1]<='9'&&a[i-1]<a[i+1]){
				n=a[i+1]-a[i-1]-1;
				for(m=0;m<n;m++,j++){
					b[j]=k+1;
					k++;}	
			}
			else{
				b[j]=a[i];j++;
			}
			}
		else{
			b[j]=a[i];j++;
		}
	}
	printf("%s\n",b);
	return 0;
	
	}

