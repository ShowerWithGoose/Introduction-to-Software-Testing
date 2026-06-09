#include<stdio.h>
#include<string.h>
int main(){
	char a[100],b[200];
	gets(a);
	int i,k=1,j;
	b[0]=a[0];
	for(i=1;i<strlen(a)-1;i++){
		if(a[i]=='-'){
			if(a[i-1]>='a'&&a[i-1]<=a[i+1]&&a[i+1]<='z'){
				for(j=1;j<=a[i+1]-a[i-1]-1;j++){
					b[k]=a[i-1]+j;
					k++;
				}
			}
			else if(a[i-1]>='A'&&a[i-1]<=a[i+1]&&a[i+1]<='Z'){
				for(j=1;j<=a[i+1]-a[i-1]-1;j++){
					b[k]=a[i-1]+j;
					k++;
				}
			}
			else if(a[i-1]>='0'&&a[i-1]<=a[i+1]&&a[i+1]<='9'){
				for(j=1;j<=a[i+1]-a[i-1]-1;j++){
					b[k]=a[i-1]+j;
					k++;
				}
			}
			else{
				b[k]='-';
				k++;
			}
		}
		else{
			b[k]=a[i];
			k++;
		}
	}
	b[k]=a[i];
	b[k+1]='\0';
	puts(b);
	return 0;
}

