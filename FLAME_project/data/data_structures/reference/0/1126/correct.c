#include<stdio.h>
#include<string.h>
int main(){
	char a[10001];
	int i=0,m=0,h=1;
	while(scanf("%c",&a[i])!=EOF)
	i++;
	for(m=0;m<i;m++){
		printf("%c",a[m]);
		if(a[m+1]=='-'){
			if(a[m]<='Z'&&a[m]>='A'&&a[m+2]<='Z'&&a[m+2]>a[m]&&a[m+2]>='A')
			{
				while(a[m]+h<a[m+2])
				{
			printf("%c",a[m]+h);
			h++;
		}
			m=m+1;
		}
		if(a[m]<='9'&&a[m]>='0'&&a[m+2]<='9'&&a[m+2]>a[m]&&a[m+2]>='0')
			{
				while(a[m]+h<a[m+2])
				{
			printf("%c",a[m]+h);
			h++;
		}
			m=m+1;
		}
		if(a[m]<='z'&&a[m]>='a'&&a[m+2]<='z'&&a[m+2]>a[m]&&a[m+2]>='a')
			{
				while(a[m]+h<a[m+2])
				{
			printf("%c",a[m]+h);
			h++;
			
		}
		m=m+1;
		}
		
		}
		h=1;
	}
	} 



