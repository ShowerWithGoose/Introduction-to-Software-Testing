#include<stdio.h> 
char a[1000];
int main()
{
	int i,f;
	char k;
	gets(a);
	for(i=0;a[i]!='\0';i++){
		if(a[i+1]=='\0'||a[i+1]!='-') putchar(a[i]);
		else if(a[i+1]=='-'){
			if(a[i+2]=='\0') { 
				printf("%c",a[i]);
				continue;
			}
			
			f=0;
			if(a[i]<a[i+2]) f++;
			if('a'<=a[i]&&a[i+2]<='z') f++;
			else if('A'<=a[i]&&a[i+2]<='Z') f++;
			else if('0'<=a[i]&&a[i+2]<='9') f++;
			
			if(f==2){
				for(k=a[i];k<a[i+2];k++) putchar(k);
				i++;
			}
			else printf("%c",a[i]);
		}
	}
	return 0;
}



