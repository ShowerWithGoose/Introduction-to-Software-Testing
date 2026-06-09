#include<stdio.h>
#include<string.h>
int main()
{
	int i=0,j=0,n,l;
	
	char a[1001];
	gets(a);
	n=strlen(a);
		for(j=0;j<n;j++){
		
		if(a[j]!='-')
		printf("%c",a[j]);
		else{
			if(a[j-1]>='a'&&a[j+1]<='z'&&a[j-1]<=a[j+1]){
				for(l=a[j-1]-'0';l<a[j+1]-'0'-1;l++)
				printf("%c",l+1+'0');}
			else if(a[j-1]>='A'&&a[j+1]<='Z'&&a[j-1]<=a[j+1]){
				for(l=a[j-1]-'0';l<a[j+1]-'0'-1;l++)
				printf("%c",l+1+'0');
				}
			else if(a[j-1]-'0'>=0&&a[j+1]-'0'<=9&&a[j-1]-'0'<=a[j+1]-'0'){
				for(l=a[j-1]-'0';l<a[j+1]-'0'-1;l++)
				printf("%c",l+1+'0');
				}
				else 
				printf("-");
			}
	}
		return 0;
	
	
}

