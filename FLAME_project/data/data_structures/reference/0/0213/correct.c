#include<stdio.h>
#include<string.h>
int main()
{
	char a[50];
	char m,n;
	char *p,*q,*j;
	int k=0,i=0,flag=0;
	scanf("%s",a);
	p=strstr(a,"-")-1;
	q=strstr(a,"-")+1;
	j=q;
	if(strstr(j,"-")!=NULL){
		flag=1;
	}
	m=*p;
	n=*q;
	if(m>='a'&&m<='z'){
		if(n>=m&&n<'z'){
			k=1;
		}else{
			k=0;
		}
	}else if(m>='A'&&m<='Z'){
		if(n>=m&&n<'Z'){
			k=1;
		}else{
			k=0;
		}
	}else if(m>='0'&&m<='9'){
		if(n>=m&&n<'9'){
			k=1;
		}else{
			k=0;
		}
	}else{
		k=0;
	}
	if(flag==0){
		if(k==0){
			printf("%s",a);
		}else if(k==1){
			while(a[i]!='-'){
				printf("%c",a[i]);
				i++;
			}
			i++;
			while(m<n-1){
				printf("%c",++m);
			}
			while(a[i]!='\0'){
				printf("%c",a[i]);
				i++;
			}
		}
	}else{
		if(k==1){
			while(a[i]!='-'){
				printf("%c",a[i]);
				i++;
			}
			i++;
			while(m<n-1){
				printf("%c",++m);
			}
			p=strstr(j,"-")-1;
			q=strstr(j,"-")+1;
			m=*p;
			n=*q;
			if(m>='a'&&m<='z'){
				if(n>=m&&n<'z'){
					k=1;
				}else{
					k=0;
				}
			}else if(m>='A'&&m<='Z'){
				if(n>=m&&n<'Z'){
					k=1;
				}else{
					k=0;
				}
			}else if(m>='0'&&m<='9'){
				if(n>=m&&n<'9'){
					k=1;
				}else{
					k=0;
				}
			}else{
				k=0;
			}
			if(k==0){
			printf("%s",a);
			}else if(k==1){
				while(a[i]!='-'){
					printf("%c",a[i]);
					i++;
				}
				i++;
				while(m<n-1){
					printf("%c",++m);
				}
				while(a[i]!='\0'){
					printf("%c",a[i]);
					i++;
				}
			}
		}else{
			p=strstr(j,"-")-1;
			q=strstr(j,"-")+1;
			m=*p;
			n=*q;
			if(m>='a'&&m<='z'){
				if(n>=m&&n<'z'){
					k=1;
				}else{
					k=0;
				}
			}else if(m>='A'&&m<='Z'){
				if(n>=m&&n<'Z'){
					k=1;
				}else{
					k=0;
				}
			}else if(m>='0'&&m<='9'){
				if(n>=m&&n<'9'){
					k=1;
				}else{
					k=0;
				}
			}else{
				k=0;
			}
			if(k==0){
			printf("%s",a);
			}else if(k==1){
				while(a[i]!='-'){
					printf("%c",a[i]);
					i++;
				}
				i++;
				while(m<n-1){
					printf("%c",++m);
				}
				while(a[i]!='\0'){
					printf("%c",a[i]);
					i++;
				}
			}	
		}
	}
	return 0;
}

