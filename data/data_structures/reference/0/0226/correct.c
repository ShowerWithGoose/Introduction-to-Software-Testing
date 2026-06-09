#include<stdio.h>
#include<string.h>
int main()
{
	int i, j, k, m, n, x;
	char a[500],b[500];
	gets(a);
	x=strlen(a);
	
	for(i=0,k=0;a[i]!='\0';i++){
		
		if(a[i]=='-'){
			
			if(a[i-1]>='a'&&a[i+1]<='z'&&a[i-1]<a[i+1]){
				j=a[i+1]-a[i-1]-1;
				
				for(m=1;m<=j;m++){
					b[k]=a[i-1]+m;
					k++;
				}	
			}
			
			else if(a[i-1]>='A'&&a[i+1]<='Z'&&a[i-1]<a[i+1]){
				j=a[i+1]-a[i-1]-1;
				
				for(m=1;m<=j;m++){
					b[k]=a[i-1]+m;
					k++;
				}
			}
			
			else if(a[i-1]>='0'&&a[i+1]<='9'&&a[i-1]<a[i+1]){
				j=a[i+1]-a[i-1]-1;
				
				for(m=1;m<=j;m++){
					b[k]=a[i-1]+m;
					k++;
				}
			}
			
			else{
				b[k]=a[i];
				k++;
			}
		}
		
		else{
				b[k]=a[i];
				k++;
			}
	}
	
	b[k]='\0';
	printf("%s", b);
	
}

