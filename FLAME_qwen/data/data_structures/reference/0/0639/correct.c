#include<stdio.h>
#include<string.h>
int main(){
	char a[100],b[200];
	gets(a);
	int i,j=1,k;
	b[0]=a[0];
	for(i=1;i<strlen(a)-1;i++){
		if(a[i]=='-'){
			if(a[i-1]>='a'&&a[i-1]<=a[i+1]&&a[i+1]<='z'){
				for(k=1;k<=a[i+1]-a[i-1]-1;k++){
					b[j]=a[i-1]+k;
					j++;
				}
			}
			else if(a[i-1]>='A'&&a[i-1]<=a[i+1]&&a[i+1]<='Z'){
				for(k=1;k<=a[i+1]-a[i-1]-1;k++){
					b[j]=a[i-1]+k;
					j++;
				}
			}
			else if(a[i-1]>='0'&&a[i-1]<=a[i+1]&&a[i+1]<='9'){
				for(k=1;k<=a[i+1]-a[i-1]-1;k++){
					b[j]=a[i-1]+k;
					j++;
				}
			}
			else{
				b[j]='-';
				j++;
			}
		}
		else{
			b[j]=a[i];
			j++;
		}
	}
	b[j]=a[i];
	b[j+1]='\0';
	puts(b);
	return 0;
}

